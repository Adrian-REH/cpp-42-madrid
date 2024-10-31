#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

double min_y = -1000 , max_y =  1000;
float tanh_activation(float x) {
    return tanh(x);
}

float tanh_derivative(float x) {
    float t = tanh(x);
    return 1 - t * t;
}
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double cross_entropy_loss(double d_output, double target) {
    double epsilon = 1e-7;  // Valor para evitar log(0)
    d_output = std::clamp(d_output, epsilon, 1.0 - epsilon);
    return -(target * std::log(d_output) + (1 - target) * std::log(1 - d_output));
}

double scale(double x, double min_val, double max_val) {
    return 2.0 * (x - min_val) / (max_val - min_val) - 1.0;
}

double unscale(double x, double min_val, double max_val) {
    return 0.5 * (x + 1.0) * (max_val - min_val) + min_val;
}

double leaky_relu(double x) {
    return x > 0 ? x : 0.0001 * x;
}

double gelu_activation(double x){
    return (x * 0.5 * (1.0 + std::erf(x / std::sqrt(2.0))));
}
double gelu_derivative(double x) {
    const double sqrt_2_pi = std::sqrt(2.0 / M_PI);  // sqrt(2/pi)
    const double sqrt_2 = std::sqrt(2.0);            // sqrt(2)
    
    double erf_part = std::erf(x / sqrt_2);
    double exp_part = std::exp(-0.5 * x * x);
    
    return 0.5 * (1.0 + erf_part) + 0.5 * x * sqrt_2_pi * exp_part;
}
double leaky_relu_derivative(double x) {
    return x > 0 ? 1.0 : 0.0001;
}
double generator_loss(double d_output) {
    double epsilon = 1e-7;  // Para evitar log(0)
    d_output = std::clamp(d_output, epsilon, 1.0 - epsilon);
    return -std::log(d_output);
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
        std::normal_distribution<double> dist(0.0, std::sqrt(2.0 / input_size)); // Distribucion ante el tamalo del input

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
            if (use_leaky_relu) output[i] = tanh_activation(output[i]);
        }
        return output;
    }

    void backward(const std::vector<double>& input, const std::vector<double>& output_gradient) {
        for (size_t i = 0; i < biases.size(); ++i) {
            double grad = use_leaky_relu ? tanh_derivative(output_gradient[i]) : 1.0;
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
    Generator() : dense1(1, 16, 0.0001), dense2(16, 16, 0.0001), dense3(16, 1, 0.0001, false) {}

    double generate(double x) {
        auto hidden1 = dense1.forward({x});
        auto hidden2 = dense2.forward(hidden1);
        auto output = dense3.forward(hidden2);
        return output[0];
    }

    double train(double x, double target, double d_output) {
        auto hidden1 = dense1.forward({x});
        auto hidden2 = dense2.forward(hidden1);
        auto output = dense3.forward(hidden2);
        double fake_y = output[0];
        //double fake_y = unscale(output[0], min_y, max_y);
        double epsilon = 1e-7; // Para evitar log(0)
    	d_output = std::clamp(d_output, epsilon, 1.0 - epsilon);
   	 	double loss = std::log(d_output);
        //double loss = std::log(d_output);
        dense3.backward(hidden2, {loss});
        dense2.backward(hidden1, {loss});
        dense1.backward({x}, {loss});
		return (loss);
    }
};


class Discriminator {
private:
    Dense dense1;
    Dense dense2;

public:
    Discriminator() : dense1(2, 16, 0.0001), dense2(16, 1, 0.0001) {}

    double discriminate(double x, double y) {
        auto hidden = dense1.forward({x, y});
        auto output = dense2.forward(hidden);
        return sigmoid(output[0]);  // Sigmoid activation
    }

    double train(double x, double y, double target) {
        auto hidden = dense1.forward({x, y});
        auto output = dense2.forward(hidden);
        double d_output = sigmoid(output[0]);  // Sigmoid activation
        //double loss = -(target * std::log(d_output) + (1 - target) * std::log(1 - d_output));
        double loss = cross_entropy_loss(d_output, target);
        
        dense2.backward(hidden, {loss});
        dense1.backward({x, y}, {loss});
		return (loss);
    }
};

void train_gan(Generator& generator, Discriminator& discriminator, int epochs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-10.0, 10.0);
	std::vector<double> loss_discriminator;
	std::vector<double> loss_generator;
	std::vector<double> epochs_vector;
    for (int epoch = 0; epoch < epochs; ++epoch) {
        double x = dist(gen);
        double real_y = std::pow(x, 3);
        double scaled_x = scale(x, -10, 10);
        double scaled_real_y = scale(real_y, min_y, max_y);
        
        // Train Discriminator
        double scaled_fake_y = generator.generate(scaled_x);
        double loss_real = discriminator.train(scaled_x, scaled_real_y, 0.9);  // Real data
        double loss_fake = discriminator.train(scaled_x, scaled_fake_y, 0.1);  // Fake data
		loss_discriminator.push_back((loss_fake + loss_real) / 2);
        // Train Generator 
        scaled_fake_y = generator.generate(scaled_x);
        double d_output = discriminator.discriminate(scaled_x, scaled_fake_y);
		loss_generator.push_back(generator.train(scaled_x, scaled_real_y, d_output));
		epochs_vector.push_back(epoch);
        if (epoch % 1000 == 0) {
            double fake_y = unscale(scaled_fake_y, min_y, max_y);
            std::cout << "Epoch " << epoch << ": x = " << x 
                        << ", y% = " << (real_y / unscale(scaled_fake_y, min_y, max_y)) * 100
                        << "%, scal_y% = " << (scale(real_y, min_y, max_y) / scaled_fake_y) * 100
                        <<"%" << std::endl;
        }
    }
	
    plt::plot(epochs_vector, loss_discriminator, {{"label", "Discriminator"}});
   plt::plot(epochs_vector, loss_generator, {{"label", "Generator"}});
    plt::title("GAN-generated Training loss");
    plt::legend();
    plt::show();

}

double mean_absolute_error(const std::vector<double>& predictions, const std::vector<double>& targets) {
    double sum_error = 0.0;
    int n = predictions.size();
    for (int i = 0; i < n; ++i) {
        sum_error += predictions[i] - targets[i];
    }
    return sum_error / n;
}

int main() {
    Generator generator;
    Discriminator discriminator;

    // Training
    train_gan(generator, discriminator, 10000);

    // Visualization
    std::vector<double> x_values, y_values, fake_y_values;
    for (double x = -10; x <= 10; x += 0.1) {
        x_values.push_back(scale(x, -10, 10));
        y_values.push_back(scale(std::pow(x, 3), min_y, max_y));
        double scaled_x = scale(x, -10, 10);
        double scaled_fake_y = generator.generate(scaled_x);
        fake_y_values.push_back(scaled_fake_y);
    }
    std::cout << "Aprox: " << mean_absolute_error(y_values, fake_y_values) << std::endl;
	plt::plot(x_values, y_values, {{"label", "Real y = x^3"}});
    plt::plot(x_values, fake_y_values, {{"label", "Generated"}});
    plt::title("GAN-generated points for y = x^2 + 2x");
    plt::legend();
    plt::show();

    return 0;
}