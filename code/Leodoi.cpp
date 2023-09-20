#include<stdio.h>
#define maxdinh 20
#define matranke "Leodoi_1.mtk"//bai11
#define heuristic "Leodoi_1.h"//bai11
//#define matranke "Leodoi_2.mtk"//bai15
//#define heuristic "Leodoi_2.h"//bai15

int h[maxdinh];
int mtk[maxdinh][maxdinh];
FILE *fp;
int n;

void inmatran(int a[][maxdinh], int hang, int cot){
	for(int i=0; i<hang; i++){
		for(int j=0; j<cot; j++){
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void inmang(int a[], int size){
	for(int i=0; i<size; i++){
		printf("%5d",a[i]);
	}
	printf("\n");
}

void readfile(){
	//doc ma tran ke
	fp=fopen(matranke,"r");	
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				fscanf(fp,"%d",&mtk[i][j]);
			}
		}
		fclose(fp);
	}
	//doc ham luong gia heuristic
	fp=fopen(heuristic,"r");	
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&n);
		for(int i=0; i<n; i++){
			fscanf(fp,"%d",&h[i]);
		}
		fclose(fp);
	}
	inmatran(mtk,n,n);
	inmang(h,n);
}

void HillClimping(int start, int goal){
	int OPEN[maxdinh];
	int CLOSE[maxdinh];
	int u = start;
	int dem=0;
	int demclose=0;
	//OPEN[dem++]=start;
	int parent[n];
	int visited[n];
	for(int i=0;i<n;i++){
		parent[i]=-1;
		visited[i]=-1;
	}
	while(u!=goal){
		for(int i=0; i<n; i++){
			if(mtk[u][i]==1 && visited[i]==-1){
				OPEN[dem++]=i;
				parent[i]=u;
				visited[u]=1;
			}
		}
		//in danh sach OPEN truoc SX
//		printf("OPEN[]: ");
//		inmang(OPEN,dem);
		//sap xep lai danh sach OPEN dua vao ham luong gia heuristic
		for(int i=0; i<dem-1; i++){
			for(int j=i+1; j<dem; j++){
				if(h[OPEN[i]]<h[OPEN[j]]){
					int tam = OPEN[i];
					OPEN[i] = OPEN[j];
					OPEN[j] = tam;
				}
			}
		}
		//in danh sach OPEN sau khi SX
		printf("OPEN[SX giam]: ");
		inmang(OPEN,dem);
		//lay dinh ke tiep co ham luong gia be nhat:
		u=OPEN[dem-1];
		dem--;
		CLOSE[demclose++]=u;
		//in danh sach CLOSE
		printf("CLOSE[]: ");
		inmang(CLOSE,demclose);
		
		//printf("\n**********dem=%d",dem);
		if(dem==0){
			printf("\nKhong tim thay duong di tu start den goal");
		}
	}
	if(u==goal){
		printf("\nTim thay duong di tu start(%d) den goal(%d)",start,goal);
		// In ra duong di bang cach in nguoc danh sach tu start
		int path[n], len = 0;
		for (int i = goal; i != -1; i = parent[i]) {
		    path[len++] = i;
		}
		printf("\nDuong di tu %d den %d: ", start, goal);
		for (int i = len - 1; i >= 0; i--) {
		    printf("%d ", path[i]);
		}
	}
}

int main(){
	readfile();
	HillClimping(0,7);//bai 11
//	HillClimping(0,13);//bai 15
	return 0;
}
