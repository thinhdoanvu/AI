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

int main() {
    double weights[] = {0, 1}; // w1 = 0, w2 = 1
    double bias = 4;           // b = 4

    struct Neuron n;
    n.weights = weights;
    n.bias = bias;

    double inputs[] = {2, 3}; // x1 = 2, x2 = 3
    int numInputs = 2;

    printf("%lf\n", feedforward(&n, inputs, numInputs)); // 0.999089

    return 0;
}
