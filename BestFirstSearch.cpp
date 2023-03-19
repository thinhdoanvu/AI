#include<stdio.h>
#define maxdinh 20
#define INPUT "BestFirstSearch.inp"

FILE *fp;
int n;
int dt[maxdinh][maxdinh];

void readfile(){
	fp=fopen(INPUT,"r");		
	if(fp==NULL){
		printf("File not found");
	}
	fscanf(fp,"%d",&n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			fscanf(fp,"%d",&dt[i][j]);
		}
	}
	//in noi dung cua ma tran trong so
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%3d",dt[i][j]);
		}
		printf("\n");
	}
	//dong tap tin
	fclose(fp);
}

void swap(int &x, int &y){
	int tam=x;
	x=y;
	y=tam;
}

void BestFristSearch(int start, int end){
	int visited[n]={0};
	int N=start;
	visited[start]=1;
	int Tn[n];
	int dem=0;
	int Open[n];
	int Sort[n];
	//Gan dinh dau tien
	Open[dem++]=start;
	if(N==end){
		printf("Tim thay duong di");
	}
	while(N!=end){
		//duyet qua cac dinh va luu dinh da duyet vao Tn
		int count =0;
		for(int i=0; i<n; i++){
			if(dt[N][i]!=-1 && visited[i]==0){
				Tn[count++]=i;
				//luu gia tri trong so tuong ung dinh vao Sort, dinh i noi vao Open
				Sort[dem]=dt[N][i];
				Open[dem]=i;
				dem++;
				//gan dinh da duyet
				visited[i]=1;
			}
		}
		//sap xep Open theo gia tri tang dan cua day SORT
		for(int i=1; i<dem-1;i++){
			for(int j=i+1; j<dem;j++){
				if(Sort[i] < Sort[j]){
					swap(Sort[i],Sort[j]);								
					swap(Open[i],Open[j]);
				}
			}
		}	
			
		printf("\nN= %d",N);
		printf("\nDay Tn: ");
		for(int i=0; i<count; i++){
			printf("%3d",Tn[i]);
		}
		printf("\nDay Sort sau khi SX: ");
		for(int i=1; i<dem; i++){//bo qu dinh dau tien
			printf("%3d",Sort[i]);
		}
		printf("\nDay Open sau khi SX: ");
		for(int i=1; i<dem; i++){//bo qu dinh dau tien
			printf("%3d",Open[i]);
		}
		//Lay dinh ra khoi Open
		N=Open[dem-1];
		dem--;
		//in lai day SORT va Open sau khi lay N
		printf("\nDay Sort sau khi lay N: ");
		for(int i=1; i<dem; i++){//bo qu dinh dau tien
			printf("%3d",Sort[i]);
		}
		printf("\nDay Open sau khi lay N: ");
		for(int i=1; i<dem; i++){//bo qu dinh dau tien
			printf("%3d",Open[i]);
		}
	}
	printf("\ndem = %d\n",dem);
	for(int i=0; i<n; i++){
		printf("%3d",visited[i]);
	}
	if(dem>0){
		printf("\nTim thay duong di tu start: %d - end: %d",start,end);	
	}
	else{
		printf("\nKhong tim thay duong di tu start: %d - end: %d",start,end);
	}
	
}
int main(){
	readfile();
	BestFristSearch(0,7);
	return 0;
}
