#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

double leaky_relu(double x) {
    return x > 0 ? x : 0.01 * x;
}

double leaky_relu_derivative(double x) {
    return x > 0 ? 1.0 : 0.01;
}

class Dense {
private:
    std::vector<std::vector<double>> weights;
    std::vector<double> biases;
    double learning_rate;
    bool use_leaky_relu;

public:
    Dense(int input_size, int output_size, double lr, bool use_leaky_relu = true) 
        : learning_rate(lr), use_leaky_relu(use_leaky_relu) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<double> dist(0.0, std::sqrt(2.0 / input_size));

        weights.resize(output_size, std::vector<double>(input_size));
        biases.resize(output_size);

        for (auto& row : weights)
            for (double& weight : row)
                weight = dist(gen);
        for (double& bias : biases)
            bias = 0.0;
    }

    std::vector<double> forward(const std::vector<double>& input) {
        std::vector<double> output(biases.size());
        for (size_t i = 0; i < biases.size(); ++i) {
            output[i] = biases[i];
            for (size_t j = 0; j < input.size(); ++j) {
                output[i] += weights[i][j] * input[j];
            }
            if (use_leaky_relu) output[i] = leaky_relu(output[i]);
        }
        return output;
    }

    void backward(const std::vector<double>& input, const std::vector<double>& output_gradient) {
        for (size_t i = 0; i < biases.size(); ++i) {
            double grad = use_leaky_relu ? leaky_relu_derivative(output_gradient[i]) : 1.0;
            grad *= output_gradient[i];
            grad = std::max(std::min(grad, 1.0), -1.0);  // Gradient clipping
            biases[i] -= learning_rate * grad;
            for (size_t j = 0; j < input.size(); ++j) {
                weights[i][j] -= learning_rate * grad * input[j];
            }
        }
    }
};

class Generator {
private:
    Dense dense1;
    Dense dense2;
    Dense dense3;

public:
    Generator() : dense1(1, 128, 0.0001), dense2(128, 128, 0.0001), dense3(128, 1, 0.0001, false) {}

    double generate(double x) {
        auto hidden1 = dense1.forward({x});
        auto hidden2 = dense2.forward(hidden1);
        auto output = dense3.forward(hidden2);
        return output[0];
    }

    void train(double x, double target, double d_output) {
        auto hidden1 = dense1.forward({x});
        auto hidden2 = dense2.forward(hidden1);
        auto output = dense3.forward(hidden2);
        double fake_y = output[0];
        
        double loss = std::log(1 - d_output) + std::abs(fake_y - target);
        
        dense3.backward(hidden2, {loss});
        dense2.backward(hidden1, {loss});
        dense1.backward({x}, {loss});
    }
};

class Discriminator {
private:
    Dense dense1;
    Dense dense2;

public:
    Discriminator() : dense1(2, 128, 0.0001), dense2(128, 1, 0.0001) {}

    double discriminate(double x, double y) {
        auto hidden = dense1.forward({x, y});
        auto output = dense2.forward(hidden);
        return 1.0 / (1.0 + std::exp(-output[0]));  // Sigmoid activation
    }

    void train(double x, double y, double target) {
        auto hidden = dense1.forward({x, y});
        auto output = dense2.forward(hidden);
        double d_output = 1.0 / (1.0 + std::exp(-output[0]));
        double loss = -(target * std::log(d_output) + (1 - target) * std::log(1 - d_output));
        
        dense2.backward(hidden, {loss});
        dense1.backward({x, y}, {loss});
    }
};

double scale(double x, double min_val, double max_val) {
    return 2.0 * (x - min_val) / (max_val - min_val) - 1.0;
}

double unscale(double x, double min_val, double max_val) {
    return 0.5 * (x + 1.0) * (max_val - min_val) + min_val;
}

void train_gan(Generator& generator, Discriminator& discriminator, int epochs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-10.0, 10.0);

    double min_y = -100, max_y = 200;

    for (int epoch = 0; epoch < epochs; ++epoch) {
        double x = dist(gen);
        double real_y = x * x + 2 * x;
        double scaled_x = scale(x, -10, 10);
        double scaled_real_y = scale(real_y, min_y, max_y);
        
        // Train Discriminator
        double scaled_fake_y = generator.generate(scaled_x);
        discriminator.train(scaled_x, scaled_real_y, 0.9);  // Real data
        discriminator.train(scaled_x, scaled_fake_y, 0.1);  // Fake data

        // Train Generator
        for (int i = 0; i < 5; ++i) {  // Train generator more frequently
            scaled_fake_y = generator.generate(scaled_x);
            double d_output = discriminator.discriminate(scaled_x, scaled_fake_y);
            generator.train(scaled_x, scaled_real_y, d_output);
        }

        if (epoch % 1000 == 0) {
            double fake_y = unscale(scaled_fake_y, min_y, max_y);
            std::cout << "Epoch " << epoch << ": x = " << x 
                      << ", real_y = " << real_y << ", fake_y = " << fake_y << std::endl;
        }
    }
}

int main() {
    Generator generator;
    Discriminator discriminator;

    // Training
    train_gan(generator, discriminator, 10000);

    // Visualization
    std::vector<double> x_values, y_values, fake_y_values;
    double min_y = -100, max_y = 200;
    for (double x = -10; x <= 10; x += 0.1) {
        x_values.push_back(x);
        y_values.push_back(x * x + 2 * x);
        double scaled_x = scale(x, -10, 10);
        double scaled_fake_y = generator.generate(scaled_x);
        fake_y_values.push_back(unscale(scaled_fake_y, min_y, max_y));
    }

    plt::plot(x_values, y_values, {{"label", "Real y = x^2 + 2x"}});
    plt::plot(x_values, fake_y_values, {{"label", "Generated"}});
    plt::title("GAN-generated points for y = x^2 + 2x");
    plt::legend();
    plt::show();

    return 0;
}