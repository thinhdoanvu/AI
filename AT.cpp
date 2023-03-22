#include<stdio.h>
#define maxdinh 20
//#define INPUT "AT.inp"
#define INPUT "AT.inp2"

//khai bao bien
int dt[maxdinh][maxdinh];
int n;
FILE *fp;


void readfile(){
	fp=fopen(INPUT,"r");	
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&n);
		//printf("n=%d",n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				fscanf(fp,"%d",&dt[i][j]);
			}
		}
		fclose(fp);
	}
	//in ra cac dinh cua do thi
	printf("Ma tran trong so cua do thi:\n");
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%5d",dt[i][j]);
			}
			printf("\n");
		}
}

void inmang(int a[],int size){
	for(int i=0; i<size; i++){
		printf("%5d",a[i]);
	}
}

void swap(int &x, int &y){
	int tam = x;
	x=y;
	y=tam;
}

void AT(int start, int end){
	int vet[n];
	int size_vet=0;
	
	int N;//dinh dang xet
	int Open[n];
	int g[n]={0};
	int Tn[n];
	int dem=0;
	int visited[n];
	int parent[n];
	//giai thuat
	N=start;
	vet[size_vet]=N;//luu vet cua N
	
	Open[dem]=start;
	g[start]=0;
	visited[start]=1;
	parent[start]=-1;
	//khoi tao mang gia tri
	for(int i=0; i<n; i++){
		parent[i]=-1;
		visited[i]=0;
	}
	
	while(N<end){
		int tempN;
		int count = 0;
		for(int i=0; i<n; i++){
			if(dt[N][i]!=0 ){
				Open[dem]=i;
				visited[i]=1;
				Tn[count]=i;
				parent[i]=N;
				dem++;
				count++;
				//tinh gia tri g:
				if(parent[i]!=-1){//kiem tra xem g[i] co chua? neu co roi can chon gmin
					g[i]=dt[N][i]+g[parent[i]];
					int tam=dt[N][i]+g[parent[i]];
					if(tam<g[i]){
						g[i]=tam;
					}
				}
				else{
					g[i]=dt[N][i];
				}
			}
		}
		
		//tim dinh co g=min, cac dinh thuoc open can xet gia tri cua g
		int MIN=g[Open[dem-1]];
		for(int i=0;i<dem-1;i++){
			if(MIN > g[Open[i]]){
				MIN=g[Open[i]];
				//N=Open[i];
			}
		}
		
		//sap xep cac dinh trong Open theo thu tu giam dan cua g[n].
		for(int i=0; i<dem-1; i++){
			for(int j=i+1; j<dem; j++){
				if(g[Open[i]] < g[Open[j]]){
					swap(Open[i], Open[j]);
				}
			}
			
		}
		//in ra danh sach cac mang:
		printf("\nVisit:\t");
		inmang(visited,n);	
		printf("\nTn:\t");
		inmang(Tn,count);
		printf("\nOpen:\t");
		inmang(Open,dem);	
		printf("\ng:\t");
		inmang(g,n);
		printf("\nParent:\t");
		inmang(parent,n);	
		printf("\nvet:\t");
		inmang(vet,size_vet);	
		
		//in ra dinh duoc chon ke tiep
		N=Open[dem-1];
		printf("\nN tiep theo la: %d",N);

		//Sau khi lay dinh N thi xoa bot 1 phan tu
		dem--;	
			
		//in lai danh sach Open sau khi lay N
		printf("\nOpen sau khi lay N: ");
		inmang(Open,dem);
	}
    
	 // In ra duong di bang cach in nguoc danh sach tu start
    int path[n], len = 0;
    for (int i = end; i != -1; i = parent[i]) {
        path[len++] = i;
    }
    printf("\nDuong di tu %d den %d: ", start, end);
    for (int i = len - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    
}


int main(){
	readfile();
	AT(0,7);
	return 0;
}
