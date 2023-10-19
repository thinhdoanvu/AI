#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define OUTPUT "SampleInt.output"

// Dinh nghia kieu du lieu
typedef struct
{
    int x1;
    int x2;
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
        data[i].x1 = 1 + rand() % (100); // rand a -> b-a+1
        data[i].x2 = 1 + rand() % (100); // rand 1 -> 100
        if (data[i].x1 + data[i].x2 > 100)
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
            fprintf(fp, "%d,%d,%d\n", data[i].x1, data[i].x2,data[i].label);
        }
        fclose(fp);
    }
}

int main()
{
    write2file();
    return 0;
}
