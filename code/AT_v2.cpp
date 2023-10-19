#include <stdio.h>
#include <limits.h> //tra ve MAX,MIN value cua kieu du lieu
#define MAX 100
// #define MTK "Greedy_AT_1.inp"
// #define H "Greedy_AT_H1.inp"
#define MTK "Greedy_AT_2.inp"
#define H "Greedy_AT_H2.inp"

// khai bao bien
int sodinh;
int mtk[MAX][MAX];
int h[MAX];
int CHA[MAX];
FILE *fp;

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

void readfile_mtk()
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

void readfile_h()
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
    printf("Uoc luong cac dinh do thi: \n%d\n", sodinh);
    inmang(h, sodinh);
}

void AT(int start, int goal)
{
    int n;           // dinh dang xet
    int OPEN[MAX];   // dinh ke
    int CLOSE[MAX];  // dinh da xet
    int Tn[MAX];     // dinh tiem nang
    int OPENED[MAX]; // cacs dinh da duoc dua vao OPEN

    int g[MAX]; // tap cac gia tri tu i->j

    int dem = 0;
    // khoi tao
    for (int i = 0; i < sodinh; i++)
    {
        CLOSE[i] = i;
        OPENED[i] = i;
        g[i] = 0;
        CHA[i]=-1;
    }
    OPEN[dem++] = start; //OPEN[dem=0] = start,dem=1
    g[start] = 0;
    while (dem >= 0)
    {
        n = OPEN[--dem]; // dem=0; 1st: n = OPEN[0] = start
        printf("\nDinh dang xet: %d", n);
        OPENED[n] = -1;
        CLOSE[n] = -1;
        if (n == goal)
        {
            printf("\nTim thay duong di tu %d -> %d", start, goal);
            //in gia tri cua CHA
            printf("\nCHA[]: ");inmang(CHA,sodinh);
            int len=0;
            int duongdi[MAX];
            for(int i=goal; i!=-1; i=CHA[i]){//i nhay den vi tri cua cha
                duongdi[len++]=i;
            }
            //in ra duong di tu start - goal
            printf("\nDuong di: ");
            for(int i=len-1; i>=0; i--){
                printf("%d -> ",duongdi[i]);
            }
            return;
        }
        // nguoc lai, kiem tra cac dinh ke cua n
        for (int i = 0; i < sodinh; i++)
        {
            if (mtk[n][i] == 1 && OPENED[i] != -1 && CLOSE[i] != -1)
            { // co dinh ke, khong thuoc OPENED, CLOSE
                // luu tam vao Tn
                g[i] = g[n] + h[i];
                Tn[dem] = g[i];
                OPENED[i] = -1;
                OPEN[dem++] = i;
                CHA[i]=n;
            }
        }
        // in ra gia tri
        printf("\nCLOSE[]: ");
        inmang(CLOSE, sodinh);
        printf("\nOPEN[]:");
        inmang(OPEN, dem);
        printf("\nOPENED[]:");
        inmang(OPENED, sodinh);
        printf("\ng[]:");
        inmang(g, sodinh);
        printf("\nTn[]:");
        inmang(Tn, dem);
        // di tim gmin = sap xep Tn theo thu tu giam dan
        for(int i=0; i<dem-1; i++){
            for(int j=i+1; j<dem; j++){
                if(Tn[i] < Tn[j]){
                    int tam=Tn[i];
                    Tn[i]=Tn[j];
                    Tn[j]=tam;
                    //doi cho cho OPEN
                    tam=OPEN[i];
                    OPEN[i]=OPEN[j];
                    OPEN[j]=tam;
                }
            }
        }
        //in lai danh sach OPEN sau khi sap xep giam dan: dinh min nam phia cuoi OPEN
        printf("\nOPEN_sort[]: ");inmang(OPEN,dem);
    }
    // het while ma n!=goal: khong co duong di
    printf("\nKhong tim thay duong di tu %d -> %d", start, goal);
}
// chuong trinh chinh
int main()
{
    readfile_mtk();
    readfile_h();
    AT(0, 7);
    return 0;
}