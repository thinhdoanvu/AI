#include<stdio.h>
#define maxdinh 10
#define INPUT "Tomau.inp"
//#define INPUT "Tomau.inp2"

int sodinh;
int dinh[maxdinh][maxdinh];
FILE *fp;
int bac[maxdinh];//bac cua do thi
int vet[maxdinh];//cac dinh da to mau

void inmatran(int a[][maxdinh], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}

void inmang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%3d",a[i]);
	}
}

void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	}
	else{
		fscanf(fp,"%d",&sodinh);
		for(int i=0; i<sodinh; i++){
			for(int j=0; j<sodinh; j++){
				fscanf(fp,"%d",&dinh[i][j]);
			}
		}
		fclose(fp);
	}
	//in ra man hinh ma tran ke cac dinh
	inmatran(dinh,sodinh);
}

void khoitao(){
	for(int i=0; i<sodinh; i++){
		bac[i]=0;
		vet[i]=0;
	}
}

int max(int a, int b){
	return (a>b)?a:b;
}

void sobac(int dinh[][maxdinh], int sodinh){
	printf("\nSo dinh cua do thi: 0  1  2  3  4  5  6");
	printf("\nSo bac cua do thi:");
	for(int i=0;i<sodinh;i++){
		for(int j=0; j<sodinh; j++){
			if(i!=j && dinh[i][j] == 1){
				++bac[i];	
			}
		}
	}
	inmang(bac,sodinh);
}

void tomau(int dinh[][maxdinh], int sodinh){
	int n;//dinh dang xet
	int color=1;//mau cua do thi
	
	while(color<=3){
		//tim max bac cua cac dinh
		int GTmax=-1;
		int posmax;
		for(int i=0; i<sodinh; i++){
			if(i!=n && vet[i]==0 && GTmax < bac[i]){
				GTmax = bac[i];
				posmax=i;
			}
		}
		printf("\nDinh co so bac lon nhat la: %d",posmax);
		//to mau cho dinh co so bac lon nhat
		n=posmax;
		vet[n]=color;
		//to mau cho cac dinh khong ke voi n
		for(int i=0; i<sodinh; ){
			if(dinh[i][n]==0 && vet[i]==0){
				vet[i]=color;
				for(int j=i; j<sodinh; ){//kiem tra 2 dinh da duoc to co ke voi dinh nao khac?
					if(dinh[i][j]==1){
						i=j+1;
						break;
					}
				}
			}
			i++;
		}
		//in ra man hinh cac dinh da duoc to mau
		printf("\nCac dinh duoc to mau: ");
		inmang(vet,sodinh);
		color++;//tang mau len 1
	}
	
}

int main(){
	readfile();
	khoitao();
	sobac(dinh,sodinh);
	tomau(dinh,sodinh);
	return 0;
}
