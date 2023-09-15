#include<stdio.h>
#define MAX_J 100
#define MAX_M 100
#define INPUT "Xeplich.inp4"

//khai bao bien
int somay;
int socv;
int CV[MAX_J];
int M[MAX_M];
int chiso[MAX_J];//luu tru thu tu cac cong viec
int vet[MAX_J];//luu vet cong viec duoc phan cong
FILE* fp;

void inmang(int mang[], int size){
    for(int i=0; i<size; i++){
        printf("%d  ",mang[i]);
    }
}

void readfile(){
    fp=fopen(INPUT,"r");
    if(fp==NULL){
        printf("File not found");
        return;
    }
    else{
        fscanf(fp,"%d",&socv);
        printf("\nSo cong viec can hoan thanh: %d\n",socv);
        fscanf(fp,"%d",&somay);
        printf("So may thi cong: %d\n",somay);
        for(int i=0; i<socv; i++){
            fscanf(fp,"%d",&CV[i]);
        }
        printf("TG hoan thanh cac CV: \n");inmang(CV,socv);
        fclose(fp);
    }
}

void swap(int *x, int *y){
    int tam=*x;
    *x=*y;
    *y=tam;
}

void sort(int mang[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(mang[i]<mang[j]){
                swap(&mang[i],&mang[j]);
                swap(&chiso[i],&chiso[j]);
            }
        }
    }
}

int min(int mang[], int size){
    int min=mang[0];
    int posmin=0;
    for(int i=1; i<size; i++){
        if(min>mang[i]){
            min=mang[i];
            posmin=i;
        }
    }
    return posmin;
}

int max(int mang[], int size){
    int max=mang[0];
    for(int i=1; i<size; i++){
        if(max<mang[i]){
            max=mang[i];
        }
    }
    return max;
}

void xeplich(){
    //thu tu cua cac cong viec
    for(int i=0; i<socv; i++){
        chiso[i]=i;
    }
    //khoi tao vet cua cac cong viec da duoc phan cong
    for(int i=0; i<socv; i++){
        vet[i]=-1;
    }
    //khoi tao danh sach cac may
    for(int i=0; i<somay; i++){
        M[i]=i;
    }
    printf("\nDanh sach cac cong viec sau khi sap xep:\n");
    sort(CV,socv);
    printf("TG:");inmang(CV,socv);
    printf("\n");
    printf("CV:");inmang(chiso,socv);
    printf("\nHien trang cac cong viec:\n");inmang(vet,socv);
    //sap xep lan dau tien
    int Tmax=CV[0];
    int dem=0;
    for(int i=0; i<somay; i++){
        vet[i]=M[i];//luu tru cong viec ung voi may thuc hien
        M[i]=CV[i];
        dem++;
    }
    printf("\nCac cong viec sau lan dau tien: ");inmang(vet,socv);
    printf("\nThoi gian hoan thanh cac may: ");inmang(M,somay);
    printf("\nThoi gian hoan thanh dai nhat: %d",Tmax);
    
    printf("\nPhan cong cho cac dot tiep theo\n");
    while(dem<socv){//duyet cho den khi het cong viec
        //phan viec cho may min cho den khi tmin+thoi gian hoan thanh cac cong viec >=Tmax
        int t_min = M[min(M,somay)];//tim thoi gian cua may thuc hien it nhat
        while(t_min<=Tmax && dem<socv){//thoi gian thuc hien cua may be nhat van chua vuot Tmax
            printf("\nMay hoan thanh som nhat may-%d voi tg = %d",min(M,somay),M[min(M,somay)]);
            vet[dem]=min(M,somay);//cap nhat trang thai cong viec phan cho tung may
            M[min(M,somay)] += CV[dem];//bo sung cv cho may min
            printf("\nTrang thai sau khi phan viec (tt): ");inmang(vet,socv);
            printf("\nThoi gian h.thanh cua cac may: ");inmang(M,somay);
            t_min+=CV[dem];//va cap nhat thoi gian hoan thanh
            dem++;//tang so luong cv da hoan thanh
        }
        Tmax=t_min;//cap nhat lai thoi gian cho Tmax
    }
    printf("\nTong thoi gian hoan thanh: %d",max(M,somay));
}

int main(){
    readfile();
    xeplich();
}