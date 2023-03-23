#include<stdio.h>
//#define INPUT "doitien_1.inp"
//#define INPUT "doitien_2.inp"
#define INPUT "doitien_3.inp"
FILE *fp;
int a[100];
int m;
int n;

void readfile(){
	fp=fopen(INPUT, "r");
	if(fp==NULL){
		printf("File not found");
	}
	fscanf(fp,"%d",&m);//so tien can doi
	fscanf(fp,"%d",&n);//tong so to tien hien co
	for(int i=0; i<n;i++){
		fscanf(fp,"%d",&a[i]);
	}
	fclose(fp);
	
	//in ra danh sach so tien can doi, so to va chi tiet cac menh gia
	printf("%d  %d\n",m,n);
	for(int i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
}

void Greedy1(){
	int S[n];
	int dem=0;
	int soto=0;
	int flash[n]={0};//danh dau to tien nao da duoc doi
	for(int i=0; i<n; i++){
		if(m>=a[i]){
			S[dem]=a[i];//gan menh gia vao tap S
			soto++;//tang so luong to len 1
			m=m-a[i];
			flash[i]=1;
		}
	}
	//truong hop khong doi duoc thi m>0
	if(m>0){
		printf("\nKhong doi duoc so tien tuong ung");
	}
	else{
		printf("\nSo to doi duoc: %d\n",soto);
		for(int i=0;i<n;i++){
			if(flash[i]==1){
				printf("%d ",a[i]);	
			}
		}	
	}
}

int main(){
	readfile();
	Greedy1();
	return 0;
}
