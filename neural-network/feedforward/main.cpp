#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

using namespace std;
#include <iostream>

float calcularMAPE(const std::vector<float>& valores_reales, const std::vector<float>& valores_predichos) {
    float error = 0.0;
    for (size_t i = 0; i < valores_reales.size(); ++i) {
        error += std::abs((valores_reales[i] - valores_predichos[i]) / valores_reales[i]);
    }
    return (error / valores_reales.size()) * 100.0; // Resultado en porcentaje
}

float calcularR2(const std::vector<float>& valores_reales, const std::vector<float>& valores_predichos) {
    float media_real = 0.0;
    for (const auto& valor : valores_reales) {
        media_real += valor;
    }
    media_real /= valores_reales.size();

    float ss_total = 0.0, ss_residual = 0.0;
    for (size_t i = 0; i < valores_reales.size(); ++i) {
        ss_total += std::pow(valores_reales[i] - media_real, 2);
        ss_residual += std::pow(valores_reales[i] - valores_predichos[i], 2);
    }
    return 1.0 - (ss_residual / ss_total);
}


// Función ReLU para la capa oculta
float relu(float x) {
    return max(0.0f, x);
}
float tanh_activation(float x) {
    return tanh(x);
}

float tanh_derivative(float x) {
    float t = tanh(x);
    return 1 - t * t;
}

float leaky_relu(float x) {
    return x > 0 ? x : 0.01f * x; // Leaky ReLU
}
// Derivada de ReLU para backpropagation
float relu_derivative(float x) {
    return x > 0 ? 1.0f : 0.0f;
}
float leaky_relu_derivative(float x) {
    return x > 0 ? 1.0f : 0.01f;  // Cambia 0.01 por otro valor si has usado un valor diferente en `leaky_relu`
}
// Función de activación para la salida (sin activación para aproximar directamente)
float identity(float x) {
    return x;  // Usamos una salida lineal para regresión
}

// Clase Neurona
class Neuron {
public:
    float weight;
    float bias;

    Neuron() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<float> dist(0.0, 0.1); // Media 0, desviación estándar 0.1 (ajustable)

        weight = dist(gen); // Peso inicial con distribución normal
        bias = dist(gen);   // Bias inicial con distribución normal
    }

    // Propaga el input a través de la neurona y aplica
    float feedforward(float input) {
        return tanh_activation(weight * input + bias);
    }
};

// Clase Red Neuronal
class NeuralNetwork {
public:
    vector<Neuron> hidden_layer;
    Neuron output_neuron;

    NeuralNetwork(int hidden_neurons) {
        // Inicia la capa oculta con `hidden_neurons` neuronas
        for (int i = 0; i < hidden_neurons; ++i) {
            hidden_layer.push_back(Neuron());
        }
    }

    // Propaga el input a través de la red y genera un output
    float feedforward(float input) {
        float hidden_output = 0.0f;
        
        // Capa oculta
        for (Neuron &neuron : hidden_layer) {
            hidden_output += neuron.feedforward(input);
        }
        
        // Capa de salida
        return identity(output_neuron.weight * hidden_output + output_neuron.bias);
    }

    // Función de entrenamiento simple con descenso de gradiente
    void train(vector<float> inputs, vector<float> targets, int epochs, float learning_rate) {

        for (int epoch = 0; epoch < epochs; ++epoch) {
            float total_loss = 0;
            
            for (size_t i = 0; i < inputs.size(); ++i) {
                float input = inputs[i];
                float target = targets[i];

                // Paso de feedforward
                float hidden_output = 0.0f;
                for (Neuron &neuron : hidden_layer) {
                    hidden_output += neuron.feedforward(input);
                }
                float output = output_neuron.weight * hidden_output + output_neuron.bias;
                
                // Calcular pérdida y gradiente
                float lambda = 0.01; // Término de regularización
                 float loss = 0.5 * pow(output - target, 2) + lambda * (pow(output_neuron.weight, 2) + pow(output_neuron.bias, 2));
                total_loss += loss;

                // Backpropagation para actualizar los pesos y sesgos
                float d_output = output - target;
                
                // Actualizar el peso y sesgo de la neurona de salida
                output_neuron.weight -= learning_rate * d_output * hidden_output;
                output_neuron.bias -= learning_rate * d_output;
                
                // Actualizar cada neurona de la capa oculta
                for (Neuron &neuron : hidden_layer) {
                    float d_hidden = d_output * output_neuron.weight * tanh_derivative(neuron.feedforward(input));
                    neuron.weight -= learning_rate * d_hidden * input;
                    neuron.bias -= learning_rate * d_hidden;
                }
            }
            
            // Imprimir el error en cada epoch
            if (epoch % 100 == 0) {
                cout << "Epoch " << epoch << " Pérdida total: " << total_loss << endl;
                cout << "Weight " << output_neuron.weight << " Bias: " << output_neuron.bias << endl;
            }
    
        }
    }
    void display_weights_and_biases() {
        cout << "Pesos y sesgos de las neuronas ocultas:" << endl;
        for (size_t i = 0; i < hidden_layer.size(); ++i) {
            cout << "Neurona " << i + 1 << " - Peso: " << hidden_layer[i].weight 
                 << ", Sesgo: " << hidden_layer[i].bias << endl;
        }
        cout << "Neurona de salida - Peso: " << output_neuron.weight 
             << ", Sesgo: " << output_neuron.bias << endl;
    }
};

int main() {
    NeuralNetwork nn(10);  // Red con 2 neuronas en la capa oculta

    // Entrenar con la función y = x^2 + 2x + 1
    std::vector<float> inputs = {-4,-3, -2, -1, 0, 1, 2};
    std::vector<float> targets;
    for (float x : inputs) {
        targets.push_back(x * x + 2 * x);
    }

    nn.train(inputs, targets, 10000, 0.001);
    nn.display_weights_and_biases();
    // Obtener predicciones
    std::vector<float> predictions;
    for (float x : inputs) {
        predictions.push_back(nn.feedforward(x));
    }
    for (int i = 0; i < inputs.size() ; i++) {
        std::cout << inputs[i] << "\t| "
        << targets[i] << "\t| "
        << predictions[i] << std::endl;
    }

    // Graficar usando matplotlib-cpp
    plt::figure_size(800, 600);
    plt::plot(inputs, targets,  {{"label", "Original"}});
    plt::plot(inputs, predictions,  {{"label", "Predicción"}});
    plt::title("Aproximación de y = x^2 + 2x con Red Neuronal");
    plt::legend();
    plt::xlabel("Input (x)");
    plt::ylabel("Output (y)");
    plt::show();
    return 0;
}