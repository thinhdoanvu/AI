#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define OUTPUT "SampleFloat.output"

// Dinh nghia kieu du lieu
typedef struct
{
    double x1;
    double x2;
    int label; // Nhãn của lớp (0 hoặc 1)
} DataPoint;

FILE *fp;
int row=MAX;

void write2file()
{
    // Tao du lieu ngau nhien
    srand(time(NULL)); // ket qua random moi lan chay la khac nhau
    DataPoint data[MAX];
    for (int i = 0; i < MAX; i++)
    {
        data[i].x1 = rand() / (double)RAND_MAX * 10.0;
        data[i].x2 = rand() / (double)RAND_MAX * 10.0;
        if (data[i].x1 + data[i].x2 > 10.0)
        {
            data[i].label = 1;
        }
        else
        {
            data[i].label = 0;
        }
    }
    // luu vao file ouput
    fp = fopen(OUTPUT, "w");
    if (fp == NULL)
    {
        printf("\nFile not found");
        return;
    }
    else
    {
        //ghi vao so dong du lieu
        fprintf(fp,"%d\n",row);
        //ghi cac gia tri con lai theo tung cap
        for (int i = 0; i < MAX; i++)
        {
            fprintf(fp, "%f,%f,%d\n", data[i].x1, data[i].x2, data[i].label);
        }
        fclose(fp);
    }
}

int main()
{
    write2file();
    return 0;
}
