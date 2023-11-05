#include<stdio.h>
#include<limits.h>
#define MAX 100
// #define MTK "Astar_GK.inp"
// #define H "Astar_GK.h"
#define MTK "nhanhcan.inp2"
#define H "nhanhcan.h2"

//khai bao bien
FILE *fp;
int mtk[MAX][MAX];
int sodinh;
int h[MAX];

void inmt(int mt[][MAX], int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%d\t",mtk[i][j]);
		}
		printf("\n");
	}
}

void inmang(int m[], int size){
	for(int i=0; i<size; i++){
		printf("%d\t",m[i]);
	}	
}

void readfile_mtk(){
	fp=fopen(MTK,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	fscanf(fp,"%d",&sodinh);
	for(int i=0; i<sodinh; i++){
		for(int j=0; j<sodinh; j++){
			fscanf(fp,"%d",&mtk[i][j]);
		}
	}
	printf("%d\n",sodinh);
	inmt(mtk,sodinh);
	fclose(fp);
}

void readfile_h(){
	fp=fopen(H,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}
	fscanf(fp,"%d",&sodinh);
	for(int i=0; i<sodinh; i++){
		fscanf(fp,"%d",&h[i]);
	}
	inmang(h,sodinh);
	fclose(fp);
}

void swap(int *x, int *y){
    int tam=*x; 
    *x=*y; 
    *y=tam;
}

void nhanhcan(int start, int goal){
    int CLOSE[MAX];//tap cac dinh da duoc lay ra
    int OPEN[MAX];//tap cac dinh cho xet
    int Tn[MAX];//tap cac dinh ke cua n
    int g[MAX];//chi phi tu start - hien tai
    int f[MAX];//chi phi start - hien tai - goal
    int min = INT_MAX;
    int len_Tn;//so phan tu cua Tn
    int CHA[MAX];//danh sach cac nut cha

    //khoi tao cac gia tri
    for(int i=0; i<sodinh; i++){
        CLOSE[i]=i;
        g[i]=0;
        f[i]=0;
        CHA[i]=-1;
    }

    int flag=0;//neu tim thay dinh goal thi gan flag=1 : tim thay dinh dich hay chua
    int dem=0;//so luong cac dinh OPEN con lai can xet
    OPEN[dem++]=start;//OPEN[start], dem=1
    printf("\nOPEN[]: ");inmang(OPEN,dem);
    //gan gia tri cho g va f cua dinh start
    g[start]=0;
    f[start]=h[start];

    while(dem>0){
        int n=OPEN[--dem];//dem=0, n=start o lan chay dau tien
        printf("\nDinh dang xet: %d, f[%d] = %d",n,n,f[n]);
        printf("\nmin = %d",min);
        CLOSE[n]=-1;
        printf("\nCLOSE[]: ");inmang(CLOSE,sodinh);

        if(n==goal){
            flag=1;//gan nhan tim thay duong di
            if(f[n]<min){
                min=f[n];
                //quay ve ban dau
                len_Tn=0;//xoa danh sach Tn
                printf("\nn == goal, quay ve ban dau");
            }
        }
        else{//n chua phai la dinh ket thuc
            if(f[n]<min){
                len_Tn=0;//xoa danh sach Tn
                //tim cac dinh ke cua n
                for(int i=0; i<sodinh; i++){
                    if(CLOSE[i]!=-1 && mtk[n][i]!=0){//i khong thuoc CLOSE va co dinh ke voi n
                        int f_prev = f[i];
                        g[i]=g[n]+mtk[n][i];//mtk[n][i] = cost(n,i)
                        f[i]=g[i]+h[i];
                        Tn[len_Tn++]=i;
                        //gan nut cha cua i khi i chua co nut CHA hoac f[i] < f_truocdo]
                        if(CHA[i]==-1 || f[i]<f_prev){
                            CHA[i]=n;
                        }
                    }
                }
            }
            else{//f[n]>min
                //tro ve while: cat bo nhanh con 
                len_Tn=0;//xoa sach danh sach Tn - thuc ra khong can
                printf("\nf(n) > min, cat bo nhanh con");
            }
        }
        printf("\nTn[]: ");inmang(Tn,len_Tn);
        //sap xep Tn theo thu giam dan cua chi phi f
        for(int i=0; i<len_Tn-1; i++){
            for(int j=i+1; j<len_Tn; j++){
                if(f[Tn[i]] < f[Tn[j]]){
                    swap(&Tn[i],&Tn[j]);
                }
            }
        }
        //chuyen Tn vao sau OPEN, khong sap xep lai OPEN
        for(int i=0; i<len_Tn; i++){
            OPEN[dem++]=Tn[i];
        }
        //in lai OPEN sau khi chen Tn
        printf("\nOPEN[]: ");inmang(OPEN,dem);
        //in g,f
        printf("\ng[]: ");inmang(g,sodinh);
        printf("\nf[]: ");inmang(f,sodinh);
    }
    if(flag == 0){
        printf("\nKhong tim thay duong di tu %d den %d",start,goal);
    }
    else{
        printf("\ntim thay duong di tu %d den %d",start,goal);
        printf("\nCHA[]: ");inmang(CHA,sodinh);
        int path[MAX];
        int len_path=0;
        for(int i=goal; i!=-1; i=CHA[i]){
            path[len_path++]=i;
        }
        printf("\nduong di: \n");
        for(int i=len_path-1; i>=0; i--){
            printf("%d ->",path[i]);
        }
    }
}


//chuong trinh chinh
int main(){
	readfile_mtk();
	printf("\nUoc luong chi phi:\n");
	readfile_h();
	nhanhcan(0,1);
	return 0;
}
