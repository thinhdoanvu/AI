#include <stdio.h>
#define INPUT "Tomau.inp"
#define MAX 20

// bien toan cuc
int sodinh;
int mtk[MAX][MAX];
FILE *fp;
int bdt[MAX];
int V[MAX];
int VET[MAX];

void inmt(int a[][MAX], int col)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

void readfile()
{
    fp = fopen(INPUT, "r");
    if (fp == NULL)
    {
        printf("File not found");
    }
    else
    {
        fscanf(fp, "%d", &sodinh);
        printf("\nSo dinh cua do thi: %d", sodinh);
        // doc cac dinh cua do thi
        for (int i = 0; i < sodinh; i++)
        {
            for (int j = 0; j < sodinh; j++)
            {
                fscanf(fp, "%d", &mtk[i][j]);
            }
        }
        fclose(fp);
    }
    // in ra ma tran ke
    printf("\nMa tran ke cac thanh pho\n");
    inmt(mtk, sodinh);
}

void init(int mang[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        mang[i] = value;
    }
}

void inmang(int mang[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", mang[i]);
    }
}

void bacdothi()
{
    init(bdt, sodinh, 0);
    printf("\nSo bac cua cac dinh:\n");
    for (int i = 0; i < sodinh; i++)
    {
        int count = 0;
        for (int j = 0; j < sodinh; j++)
        {
            if (i != j && mtk[i][j] != 0)
            {
                count++;
            }
        }
        bdt[i] = count;
    }
}

int timmax(int mang[], int size)
{
    int max = mang[0];
    int posmax = 0;
    for (int i = 1; i < size; i++)
    {
        if (max < mang[i])
        {
            max = mang[i];
            posmax = i;
        }
    }
    return posmax;
}

void tomau()
{
    printf("\nThanh pho: \n");
    for (int i = 0; i < sodinh; i++)
    {
        V[i] = i;
    }
    inmang(V, sodinh);
    printf("\nBac cua do thi: \n");
    inmang(bdt, sodinh);
    int color = 1;
    init(VET, sodinh, -1);
    while (color <= 3)
    {
        int n = V[timmax(bdt, sodinh)];
        printf("\nThanh pho co bac max = %d: ", V[timmax(bdt, sodinh)]);
        // to mau cho thanh pho co bac max = color (1)
        //chuyen thanh pho co bdt=max thanh -1
        bdt[n]=-1;
        VET[n] = color;
        //to mau cho cac dinh ke voi dinh Vmax
        for(int i=0; i<sodinh; ){
            if(mtk[n][i]==0 && VET[i]==-1){
                VET[i]=color;
            }
            //kiem tra 2 dinh ke nhau nhung cung khong ke dinh n
            for(int j=i; j<sodinh; j++){
                if(mtk[i][j]==1){
                    i=j+1;
                    break;
                }
            }
            i++;
        }
        printf("\nThanh pho duoc to mau tuong ung color = %d: ", color);
        inmang(VET, sodinh);
        color++;
    }
}

int main()
{
    readfile();
    bacdothi();
    tomau();
    return 0;
}