#include<stdio.h>
#include<limits.h>
#define INPUT "Greedy_TSP.inp"
#define MAX 100


//bien toan cuc
FILE *fp;
int sodinh;
int chiphi[MAX][MAX];

void inmt(int mt[][MAX],int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			printf("%5d",mt[i][j]);
		}
		printf("\n");
	}
}

void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
		return;
	}	
	else{
		fscanf(fp,"%d",&sodinh);
		for(int i=0; i<sodinh; i++){
			for(int j=0; j<sodinh; j++){
				fscanf(fp,"%d",&chiphi[i][j]);
			}
		}
		fclose(fp);
	}
	//in ra cac gia tri
	printf("So dinh cua do thi: %d",sodinh);
	printf("\nChi phi di lai giua cac thanh pho: \n");inmt(chiphi,sodinh);
}

void inmang(int m[], int size){
	for(int i=0; i<size; i++){
		printf("%d  ",m[i]);
	}
}

void Greedy_TSP(int start){
	int VET[MAX];

	int CLOSE[MAX];
	int n = start;
	int dem=0;
	
	printf("\nDinh xuat phat: %d",n);
	for(int i=0; i<sodinh; i++){
		CLOSE[i]=i;
	}
	CLOSE[n]=-1;
	printf("\nCLOSE[]: ");inmang(CLOSE,sodinh);
	
	//luu lai thu tu dinh da duyet
	VET[dem]=n;//VET[0 ? ? ? ? ? ? ?]
	
	while (dem<sodinh-1){
		int MIN = INT_MAX;
		int pos;//luu giu dinh co chi phi la min
		
		for(int i=0; i<sodinh; i++){
			//tim MIN cua cac dinh ke voi n
			if(i!=n && MIN>chiphi[n][i] && CLOSE[i]!=-1){
				MIN=chiphi[n][i];
				pos=i;
			}
		}
		//gan dinh ke tiep la dinh co pos=min
		n=pos;
		printf("\nDinh ke tiep: %d",n);
		CLOSE[n]=-1;
		printf("\nCLOSE[]: ");inmang(CLOSE,sodinh);
		
		//luu VET cho dinh ke tiep
		VET[dem++]=n;//VET[0 6 ? ? ? ? ? ? ?]
	}
	//in ra mang cua VET
	printf("\nThu tu cac thanh pho da di qua: ");inmang(VET,dem);
}


int main(){
	readfile();
	Greedy_TSP(0);
	return 0;
}
