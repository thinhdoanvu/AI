#include <stdio.h>
#define MAX 20
#define MTK "Greedy_BestFS_2.inp"
#define H "Greedy_BestFS_H2.inp"

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
    printf("Uoc luong cac dinh do thi: \n%d\n", sodinh);
    for (int i = 0; i < sodinh; i++)
    {
        printf("%d  ", h[i]);
    }
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

void BestFirstSearch(int start, int goal)
{
    printf("\n========================================");
    int dem = 0;
    int OPEN[MAX];
    int CLOSE[MAX];
    int Tn[MAX];
    int n;
    int len;
    int OPENED[MAX];
    int Parent[MAX];

    // khoi tao gia tri
    init(CLOSE, sodinh, 0);
    init(OPENED, sodinh, 0);
    init(Parent, sodinh, -1);
    OPEN[dem++] = start;

    while (dem >= 0)
    {
        printf("\nOPEN[]: ");
        inmang(OPEN, dem);
        n = OPEN[--dem];
        printf("\nDinh dang xet: %d", n);
        CLOSE[n] = -1;
        printf("\nCLOSE[]");
        inmang(CLOSE, sodinh);
        OPENED[n] = -1;
        printf("\nOPENED[]: ");
        inmang(OPENED, sodinh);
        if (n == goal)
        {
            printf("\nTim thay duong di tu %d -> %d", start, goal);
            // in ra lo trinh duong di tu start den goal
            int duongdi[MAX];
            int len = 0; // so phan tu cua duongdi[]
            // luu cha cua cac dinh vao duong di
            for (int i = goal; i != -1; i = Parent[i])
            {
                duongdi[len++] = i;
            }
            printf("\nduongdi: ");
            inmang(duongdi, len);
            // in duong di
            printf("\nLo trinh tu start = %d den goal = %d: ", start, goal);
            for (int i = len - 1; i >= 0; i--)
            {
                printf("%d ->  ",duongdi[i]);
            }
            return;
        }
        else
        {
            // xet cac dinh ke cua n
            len = 0;
            for (int i = 0; i < sodinh; i++)
            {
                if (mtk[n][i] != 0 && CLOSE[i] != -1 && OPENED[i] != -1)
                {
                    Tn[len++] = i;
                    OPENED[i] = -1;
                    // gan nut cha
                    Parent[i] = n;
                }
            }
            printf("\nTn[] truoc sap xep: ");
            inmang(Tn, len);
            // sapxep gia tri h tang dan cho Tn
            for (int i = 0; i < len - 1; i++)
            {
                for (int j = i + 1; j < len; j++)
                {
                    if (h[Tn[i]] < h[Tn[j]])
                    {
                        swap(&Tn[i], &Tn[j]);
                    }
                }
            }
            printf("\nTn[] sau sap xep: ");
            inmang(Tn, len);
            // chen Tn vao OPEN
            for (int i = 0; i <= len; i++)
            {
                OPEN[dem + i] = Tn[i];
            }
            dem = dem + len;
            printf("\nDanh sach cac nut cha: ");
            inmang(Parent, sodinh);
        }
    }
    if (dem < 0)
    {
        printf("\nKhong tim thay duong di tu %d -> %d", start, goal);
        return;
    }
}

int main()
{
    readmtk();
    readh();
    BestFirstSearch(0, 7);
    return 0;
}