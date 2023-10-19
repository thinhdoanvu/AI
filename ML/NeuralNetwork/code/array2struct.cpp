#include<stdio.h>
#define INPUT "array.inp"
#define MAX 10

struct toado
{
    int x;
    int y;
};

struct toado td[MAX];

FILE *fp;
int n;
int m[MAX][MAX];
int X[MAX],Y[MAX];

void inmang(struct toado m[], int size){
    for(int i=0; i<size; i++){
        printf("\n%d %d",m[i].x, m[i].y);
    }   
}

void inm1c(int m[], int size){
    for(int i=0; i<size; i++){
        printf("%d  ",m[i]);
    }
}

void readfile()
{
    fp=fopen(INPUT,"r");
    if(fp==NULL)
    {
        printf("File not found");return;
    }
    fscanf(fp,"%d",&n);
    for(int i=0; i<n*2; i=i+1){
        fscanf(fp,"%d %d",&td[i].x, &td[i].y);
    }
    //in ra gia tri cua x va y
    //cach 1:
    printf("\ntd: ");inmang(td,n);
    //cach 2:
    int dem=0;
    for(int i=0; i<n; i=i+1){
        X[dem]=td[i].x;
        Y[dem++]=td[i].y;
    }
    fclose(fp);
    printf("\nX[]: ");inm1c(X,dem);
    printf("\nY[]: ");inm1c(Y,dem);

}   

int main()
{
    readfile();
}