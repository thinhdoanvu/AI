#include<stdio.h>
#define INPUT "Xeplich.inp"
#define INPUT "Xeplich.inp2"
#define maxmay 20
#define maxcv 100

int CV[maxcv];//danh sach cac cong viec
int M[maxmay];//danh sach cac may thi cong
int vet[maxcv];//luu vet cong viec nao da duoc phan cong
int chiso[maxcv];//ky hieu cac cong viec
int somay;
int numjob;

FILE *fp;

void khoitao(int a[], int n){
	for(int i=0; i<n; i++){
		a[i]=-1;
	}
}

void inmang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d\t",a[i]);
	}
}


void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&numjob);
		printf("So cong viec: %d",numjob);
		fscanf(fp,"%d",&somay);
		printf("\nSo may can gia cong: %d",somay);
		for(int i=0; i<numjob; i++){
			fscanf(fp,"%d",&CV[i]);	
		}
		fclose(fp);
	}
	//in ra man hinh cac cong viec
	printf("\nChi tiet cac cong viec: \n");
	for(int i=0; i<numjob; i++){
		printf("CV%d\t",i);	
	}
	printf("\n");
	inmang(CV,numjob);
}

void xeplich(){
	khoitao(vet,numjob);
	//khoi tao chi so cac cong viec
	for(int i=0; i<numjob; i++){
		chiso[i]=i;
	}
	//sap xep cac cong viec theo thu tu giam dan cua thoi gian hoan thanh
	for(int i=0; i<numjob-1; i++){
		for(int j=i+1; j<numjob; j++){
			if(CV[i] < CV[j]){
				int tam=CV[i];
				CV[i]=CV[j];
				CV[j]=tam;
				//thay doi ten cua cac cong viec
				tam=chiso[i];
				chiso[i]=chiso[j];
				chiso[j]=tam;
			}
		}
	}
	//in ra man hinh cac cong viec va ten cua cac cong viec tuong ung
	printf("\nTen cong viec va thoi gian hoan thanh sau khi duoc sap xep");
	printf("\n");
	inmang(chiso,numjob);
	printf("\n");
	inmang(CV,numjob);
	
	//sap xep cong viec vao cac may
	int Tmax = CV[0];
	printf("\nTmax = %d",Tmax);
	for(int i=0; i<somay; i++){
		M[i]=CV[i];
		vet[chiso[i]]=i;
	}
	//in ra man hinh thoi gian hoan thanh cong viec cua cac may
	printf("\nThoi gian hoan thanh cua cac may\n");
	inmang(M,somay);
	printf("\nThu tu phan bo cong viec cho cac may\n");
	inmang(vet,numjob);
	
	//tim may co thoi gian hoan thanh nho nhat
	int tmin=9999;
	int maymin;
	int thutu=somay;
	int k=somay;//luu y k dat o day
	
	//lap lai cho den  khi phan bo het cong viec
	while(thutu <=numjob){
		//tim may co thoi gian thuc hien ngan nhat
		for(int i=0; i<somay; i++){
			if(tmin>=M[i]){
				maymin=i;
				tmin=M[i];
			}
		}
		printf("\nmay co thoi gian thi cong be nhat: May-%d voi thoi gian: %d",maymin,tmin);
		//gan them cong viec cho den khi thoi gian hoan thanh >= Tmax
		//int k=somay;//dat o day la sai
		while (Tmax >=M[maymin] && k<numjob){//chu y can co dau = neu ko input1 dung nhung input 2 sai
			M[maymin]+=CV[k];
			vet[chiso[k]] = maymin;//vet cua cong viec co chi so k dang xet gan bang ten may min
			k++;
			
			//tang them so cong viec da hoan thanh
			thutu++;
		}
		//cap nhat lai Tmax
		Tmax=M[maymin];
		printf("\nTmax new= %d",Tmax);
		printf("\nThoi gian hoan thanh cac may new: \n");
		inmang(M,somay);
		//in lai cong viec da phan cong cho cac may
		printf("\nBang phan cong moi:\n");
		inmang(vet,numjob);
		//tang them so lan da thuc hien len 1
		thutu++;
	}
	//het cong viec
}

int main(){
	readfile();
	xeplich();
	return 0;
}
