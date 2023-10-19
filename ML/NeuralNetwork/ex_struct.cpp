#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// khai bao bien
struct SV
{
    char hoten[30];
    char lop[10];
    float toan;
    float ly;
    float hoa;
    float dtb;
};

int N;
struct SV sinhvien[10];

void nhapthongtin()
{
    for (int i = 0; i < N; i++)
    {
        fflush(stdin);
        printf("Ho ten: ");
        gets(sinhvien[i].hoten);
    }
}

void in()
{
    for(int i=0; i<N; i++){
        printf("%s",sinhvien[i].hoten);
    }
}

int main()
{
    N = 1;
    nhapthongtin();
    in();
    return 0;
}