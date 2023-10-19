#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define INPUT "PLA_Int.inp"

// Dinh nghia kieu du lieu
typedef struct
{
    int x1;
    int x2;
    int label; // Nhãn của lớp (0 hoặc 1)
} DataPoint;

DataPoint data[MAX];

FILE *fp;
int row;

void readfile()
{
    fp = fopen(INPUT, "r");
    if (fp == NULL)
    {
        printf("\nFile not found");
        return;
    }
    else
    {
        fscanf(fp, "%d", &row);
        printf("%d\n", row);
        for (int i = 0; i < row; i++)
        {
            fscanf(fp, "%d,%d,%d", &data[i].x1, &data[i].x2, &data[i].label); // ky hieu dau , trong file INPUT
        }
        // in ra cac gia tri cua data
        for (int i = 0; i < row; i++)
        {
            printf("(%d,%d,%d)", data[i].x1, data[i].x2, data[i].label);
            printf("\n");
        }

        fclose(fp);
    }
}

// Ham tinh du doan dau ra cua du lieu
int predict(double w1, double w2, double b, DataPoint data)
{
    double result = w1 * data.x1 + w2 * data.x2 + b;
    return result > 0 ? 1 : 0;
}

// Giai thuat PLA tinh perceptron
//chung ta su dung kieu con tro de cap nhat gia tri cua w1, w2 va b. 
//Neu khong su dung kieu nay, gia tri duoc thay doi chi la ban sao cua no ma thoi
//trong do, *data la mang chua cac DataPoint

void trainPLA(double *w1, double *w2, double *b, DataPoint *data, int numData, double learningRate)
{
    int converged = 0;
    int count = 0;
    
    while (converged==0) {//chua hoi tu
        converged = 1;
        printf("\n---------count = %d-----------",count);
        for (int i = 0; i < numData; i++) {
            int predicted = predict(*w1, *w2, *b, data[i]);
            printf("\npred = %d",predicted);
            //printf("\n(w1, w2, b) = %lf,%lf,%lf",*w1,*w2,*b);
            if (predicted != data[i].label) {
                *w1 += learningRate * (data[i].label - predicted) * data[i].x1;
                *w2 += learningRate * (data[i].label - predicted) * data[i].x2;
                *b += learningRate * (data[i].label - predicted);
                converged = 0;
                printf("\n(w1, w2, b) = %lf,%lf,%lf",*w1,*w2,*b);
            }
        }
        count++;
    }
    printf("Giai thuat PLA ket thuc sau %d buoc\n", count);
}

int main()
{
    readfile();
    // Khoi tao trong so - w va nguong b
    double w1 = 0.0;
    double w2 = 0.0;
    double b = 0.0;

    // Huan luyen PLA
    trainPLA(&w1, &w2, &b, data, row, 0.1);

    // In ra trong so w va nguong b
    printf("w1 = %lf, w2 = %lf, b = %lf\n", w1, w2, b);

    return 0;
}
