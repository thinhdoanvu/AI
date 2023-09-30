#include <stdio.h>
#include<limits.h>
#define MAX 20
//#define MTK "Greedy_AT_1.inp"
//#define H "Greedy_AT_H1.inp"
#define MTK "Greedy_AT_2.inp"
#define H "Greedy_AT_H2.inp"

// bien toan cuc
FILE *fp;
int sodinh;
int mtk[MAX][MAX];
int h[MAX];

void inmt(int mt[][MAX], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }
}

void inmang(int m[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", m[i]);
    }
}

void readmtk()
{
    fp = fopen(MTK, "r");
    if (fp == NULL)
    {
        printf("File not found");
        return;
    }
    else
    {
        fscanf(fp, "%d", &sodinh);
        for (int i = 0; i < sodinh; i++)
        {
            for (int j = 0; j < sodinh; j++)
            {
                fscanf(fp, "%d", &mtk[i][j]);
            }
        }
        fclose(fp);
    }
    printf("So dinh cua do thi: \n%d\n", sodinh);
    inmt(mtk, sodinh);
}

void readh()
{
    fp = fopen(H, "r");
    if (fp == NULL)
    {
        printf("File not found");
        return;
    }
    else
    {
        for (int i = 0; i < sodinh; i++)
        {
            fscanf(fp, "%d", &h[i]);
        }
        fclose(fp);
    }
    printf("Uoc luong cac dinh do thi: \n%d\n", sodinh);inmang(h,sodinh);
}

void swap(int *x, int *y)
{
    int tam = *x;
    *x = *y;
    *y = tam;
}

void init(int m[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        m[i] = value;
    }
}

void sort(int m[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(m[i] < m[j]){
                swap(&m[i],&m[j]);
            }
        }
    }
}

void AT(int start, int goal)
{
    int g[MAX];
    int OPENED[MAX];
    int OPEN[MAX];
    int CLOSE[MAX];
    int Tn[MAX];
    int CHA[MAX];
    //khoi tao gia tri
    for(int i=0; i<sodinh; i++){
        CLOSE[i]=i;
        OPENED[i]=i;
    }
    init(CHA,sodinh,-1);
    printf("\n========================================");
    int dem = 0;
    OPEN[dem++] = start;
    g[start]=0;

    while (dem >= 0)
    {
        //lay ra dinh trong OPEN (lay tu cuoi danh sach)
        int n=OPEN[--dem];
        //in ra cac gia tri
        printf("\nDinh hien tai: %d",n);

        CLOSE[n]=-1;
        OPENED[n]=-1;
        
        printf("\nOPENED[]: ");inmang(OPENED,sodinh);
        printf("\nCLOSE[]: ");inmang(CLOSE,sodinh);
        if(n==goal){
            printf("\nTim thay duong di tu %d -> %d",start,goal);
            printf("\nCHA[]: ");inmang(CHA,sodinh);

            int duongdi[MAX];
            int len=0;
            //duyet du goal ve start, neu CHA[i]!=-1 chuyen i ve vi tri CHA[i]
            for(int i=goal; i!=-1; i=CHA[i]){
                duongdi[len++]=i;
            }
            printf("\nduong di tu %d den %d: " ,goal, start);inmang(duongdi,len);
            return;
        }
        else{
            for(int i=0; i<sodinh; i++){
                if(i!=n && mtk[n][i] == 1 && CLOSE[i]!=-1 && OPENED[i]!=-1){
                    //i khong phai la n, i ke n, i khong thuoc CLOSE, i khong co trong OPENED
                    //tinh cac gia tri g(i)
                    Tn[dem]=g[n]+h[i];
                    g[i]=g[n]+h[i];
                    OPENED[i]=-1;
                    OPEN[dem]=i;
                    CHA[i]=n;
                    dem++;
                }
            }
            printf("\nOPEN[] chua sort: ");inmang(OPEN,dem);
            printf("\nTn[] chua sort: ");inmang(Tn,dem);
            //sap xep theo thu tu giam dan cua Tn (gia tri cua g)
            for(int i=0; i<dem -1 ; i++){
                for(int j=i+1; j<dem; j++){
                    if(Tn[i]<Tn[j]){
                        swap(&Tn[i], &Tn[j]);
                        swap(&OPEN[i], &OPEN[j]);
                    }
                }
            }
            printf("\nOPEN[] sap xep giam: ");inmang(OPEN,dem);
            printf("\nTn[] sap xep giam: ");inmang(Tn,dem);
        }
        printf("\n---------------------------------");
    }
    if(dem<0){
        printf("\nKhong tim thay duong di tu %d -> %d",start,goal);
    }
}

int main()
{
    readmtk();
    readh();
    //H1
    //AT(0, 6);
    //H2
    AT(0,7);
    return 0;
}