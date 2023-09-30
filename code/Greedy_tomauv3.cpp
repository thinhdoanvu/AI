#include <stdio.h>
#include <limits.h> //tim so lon nhat va be nhat cua kieu du lieu
#define MAX 100     // so dinh toi da cua do thi
//#define INPUT "Greedy_Tomau1.inp"
//#define INPUT "Greedy_Tomau2.inp"
#define INPUT "Greedy_Tomau3.inp"

// khai bao bien
int sodinh;
FILE *fp; // kieu du lieu file
int mtk[MAX][MAX];
int bdt[MAX];

void inmatran(int mt[MAX][MAX], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%3d", mt[i][j]); // in cac phan tu cua cot tren moi hang
        }
        printf("\n"); // xuong hang khi het so luong phan tu cua moi hang
    }
}

void readfile()
{
    fp = fopen(INPUT, "r"); // mode =  read
    if (fp == NULL)
    {
        printf("File not found");
        return;
    }
    else
    {
        // doc so dinh cua do thi
        fscanf(fp, "%d", &sodinh);
        // doc gia tri ma tran ke cua cac dinh
        for (int i = 0; i < sodinh; i++)
        {
            for (int j = 0; j < sodinh; j++)
            {
                fscanf(fp, "%d", &mtk[i][j]);
            }
        }
        fclose(fp);
    }
    // in ra cac gia tri
    printf("So dinh cua do thi: %d", sodinh);
    printf("\nMTK[][]:\n");
    inmatran(mtk, sodinh);
}

void inmang(int m[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", m[i]);
    }
}

void bacdothi()
{
    for (int i = 0; i < sodinh; i++)
    {
        int count = 0;
        for (int j = 0; j < sodinh; j++)
        {
            if (mtk[i][j] == 1)
            {
                count++;
            }
        }
        // luu gia tri cua bac do thi [i] vao mang
        bdt[i] = count;
    }
    // in ra so bac cua cac dinh
    printf("\nBac do thi: ");
    inmang(bdt, sodinh);
}

int timmax(int m[], int size)
{
    int max = m[0];
    int posmax = 0;
    for (int i = 1; i < size; i++)
    {
        if (max < m[i])
        {
            max = m[i];
            posmax = i;
        }
    }
    return posmax;
}

void init(int m[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        m[i] = value;
    }
}

void tomau()
{
    int COLOR[MAX];
    // khoi tao cac dinh co mau = 0 (chua to)
    init(COLOR, sodinh, 0);

    int color = 1; // khoi tao mau ban dau la 1

    // lap lai cac dinh voi color = 1,2,3
    while (color <= 3)
    {
        int n = timmax(bdt, sodinh); // tim dinh co so bac lon nhat
        COLOR[n] = color;
        // to mau cho cac dinh khong ke voi dinh dang xet n
        for (int i = 0; i < sodinh;)
        {
            if (mtk[n][i] == 0 && COLOR[i]==0)//COLOR==0: chua to
            {
                COLOR[i] = color;
                bdt[i]=INT_MIN;
                //loai bo dinh ke voi i: hay i se thuc hien bo qua viec xet tuan tu cac dinh
                for(int j=i+1; j<sodinh; j++){//xet dinh ke i
                    if(mtk[i][j]==1){//2 dinh ke nhau
                        i=j;//nhay i toi vi tri cua j
                        break;
                    }
                }
            }
            i++;//trong truong hop khong co dinh nao ke i thi chuyen qua i ke tiep
        }
        // in ra cac dinh voi cac mau da to
        printf("\nCOLOR[%d]: ", color);
        inmang(COLOR, sodinh);
        //thay doi gia tri cho max
        bdt[n]=INT_MIN;//vo cung be ~-2.4xx.xxx.xxx
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