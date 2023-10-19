#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Định nghĩa một cấu trúc để biểu diễn điểm dữ liệu
typedef struct {
    double x1;
    double x2;
    int label; // Nhãn của lớp (0 hoặc 1)
} DataPoint;

// Hàm tính đầu ra dự đoán của perceptron cho một điểm dữ liệu
int predict(double w1, double w2, double b, DataPoint data) {
    double result = w1 * data.x1 + w2 * data.x2 + b;
    return result > 0 ? 1 : 0;
}

// Thuật toán PLA để huấn luyện perceptron
void trainPLA(double *w1, double *w2, double *b, DataPoint *data, int numData, double learningRate) {
    int converged = 0;
    int iterations = 0;
    
    while (!converged) {
        converged = 1;
        for (int i = 0; i < numData; i++) {
            int predicted = predict(*w1, *w2, *b, data[i]);
            if (predicted != data[i].label) {
                *w1 += learningRate * (data[i].label - predicted) * data[i].x1;
                *w2 += learningRate * (data[i].label - predicted) * data[i].x2;
                *b += learningRate * (data[i].label - predicted);
                converged = 0;
            }
        }
        iterations++;
    }
    printf("PLA converged after %d iterations.\n", iterations);
}

int main() {
    srand(time(NULL));
    
    // Tạo dữ liệu ngẫu nhiên
    DataPoint data[100];
    for (int i = 0; i < 100; i++) {
        data[i].x1 = rand() / (double)RAND_MAX * 10.0;
        data[i].x2 = rand() / (double)RAND_MAX * 10.0;
        if (data[i].x1 + data[i].x2 > 10.0) {
            data[i].label = 1;
        } else {
            data[i].label = 0;
        }
    }

    for(int i=0; i<100; i++){
        printf("%lf,%lf,%d\n",data[i].x1, data[i].x2, data[i].label);
    }

    // Khởi tạo trọng số và bias
    double w1 = 0.0;
    double w2 = 0.0;
    double b = 0.0;

    // Huấn luyện PLA
    trainPLA(&w1, &w2, &b, data, 100, 0.1);

    // In ra trọng số và bias đã học được
    printf("w1 = %lf, w2 = %lf, b = %lf\n", w1, w2, b);

    return 0;
}
