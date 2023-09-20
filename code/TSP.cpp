#include<stdio.h>
#define maxdinh 8
#define INPUT "TSP.inp"

FILE *fp;
int sodinh;
int dinh[maxdinh][maxdinh];

void inmt(int dinh[][maxdinh], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%5d",dinh[i][j]);
		}
		printf("\n");
	}
} 

void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&sodinh);
		//doc toa do cac dinh
		for(int i=0; i<sodinh; i++){
			for(int j=0; j<sodinh; j++){
				fscanf(fp,"%d",&dinh[i][j]);
			}
		}
		inmt(dinh,sodinh);
		fclose(fp);
	}
}

int min(int a, int b){
	return (a<b)?a:b;
}

void inmang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%3d",a[i]);
	}
}

void Greedy1(int dinh[][maxdinh], int start){
	int vet[maxdinh]={0,0,0,0,0,0,0};
	int thutu=0;//thu tu cua dinh duuoc xet 1 2 3 4 5 6 7 8
	int n=start;//dinh dang xet
	//gan dinh xuat phat = 1
	vet[n]=++thutu;
	//in ra dinh xuat phat
	printf("Thu tu cac  thanh pho da di qua la: \n");
	printf("%d -> ",n+1);
	while(thutu<sodinh){
		//tim min cua dinh ke dinh dang xet (n)
		int GTmin=99999;
		int posmin;
		for(int i=0; i<sodinh; i++){
			if(i!=n && vet[i]==0 && GTmin > dinh[i][n]){
				GTmin = dinh[i][n];
				posmin=i;
			}
		}
		n=posmin;
		vet[n]=++thutu;
		//printf("\nGTmin=%d, posmin = %d\n",GTmin,posmin);	
		//inmang(vet,maxdinh);
		printf("%d -> ",n+1);
	}
	//in lai dinh xuat phat
	printf("%d",start+1);	
}

int main(){
	readfile();
	Greedy1(dinh,0);
	return 0;
}
