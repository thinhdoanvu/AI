#include <stdio.h>
#include <math.h>

double sigmoid(double x) {
    // Hàm kích hoạt: f(x) = 1 / (1 + e^(-x))
    return 1 / (1 + exp(-x));
}

struct Neuron {
    double *weights;
    double bias;
};

double feedforward(struct Neuron *n, double *inputs, int numInputs) {
    // Trọng số inputs, thêm bias, sau đó sử dụng hàm kích hoạt
    double total = 0;
    for (int i = 0; i < numInputs; i++) {
        total += n->weights[i] * inputs[i];
    }
    total += n->bias;
    return sigmoid(total);
}

struct OurNeuralNetwork {
    struct Neuron h1;
    struct Neuron h2;
    struct Neuron o1;
};

double feedforwardNetwork(struct OurNeuralNetwork *network, double *x) {
    double out_h1 = feedforward(&network->h1, x, 2);
    double out_h2 = feedforward(&network->h2, x, 2);

    // Các đầu vào cho o1 là các đầu ra từ h1 và h2
    double inputs_o1[] = {out_h1, out_h2};
    return feedforward(&network->o1, inputs_o1, 2);
}

int main() {
    struct Neuron neuron;
    neuron.weights = (double[]){0, 1}; // w1 = 0, w2 = 1
    neuron.bias = 0;

    struct OurNeuralNetwork network;
    network.h1 = neuron;
    network.h2 = neuron;
    network.o1 = neuron;

    double x[] = {2, 3}; // x1 = 2, x2 = 3
    printf("%lf\n", feedforwardNetwork(&network, x)); // 0.721633

    return 0;
}
