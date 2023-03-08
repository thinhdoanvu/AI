#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100 // Kich thuoc toi da cua hang doi
//#define INPUT "BFS_DFS_1.txt"
//#define INPUT "BFS_DFS_2.txt"
//#define INPUT "BFS_DFS_3.txt"
//#define INPUT "BFS_DFS_4.txt"
#define INPUT "BFS_DFS_5.txt"

//front ---> rear
int dothi[100][100];//tap cac dinh cua do thi
int visited[100];//tap cac dinh da xet: Close
int queue[MAX_QUEUE_SIZE];//hang doi chua cac dinh chua xet: Open

//IN RA DANH SACH CAC NUT CHA
void bfs2(int start, int end, int n) {
    int front = 0, rear = 0;
    queue[rear++] = start; // Them dinh vao hang doi
    visited[start] = 1; // Danh dau dinh Start da duoc tham
    int parent[n];
    parent[start] = -1; // Khoi tao dinh cha co nut goc la -1
    while (front < rear) {
        int current = queue[front++]; // Lay dinh dau tien trong hang doi
        if (current == end) break; // Neu tim thay dinh end thi ket thuc
        for (int i = 0; i < n; i++) {
            if (dothi[current][i] == 1 && visited[i] == 0) {//Cac dinh co lien ket voi dinh dang xet va chua duoc duyet
                queue[rear++] = i; // Them dinh i vao hang doi
                visited[i] = 1; // Danh dau dinh i da duoc duyet
                parent[i] = current; // Luu tru dinh cha la dinh hien tai
            }
        }
    }
    if (visited[end] == 0) {
        printf("Khong tim thay duong di tu %d den %d\n", start, end);
        return;
    }
    // In ra duong di bang cach in nguoc danh sach tu start
    int path[n], len = 0;
    for (int i = end; i != -1; i = parent[i]) {
        path[len++] = i;
    }
    printf("Duong di tu %d den %d: ", start, end);
    for (int i = len - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
}

//IN RA HANG DOI LA CAC DINH DUOC DUYET
void bfs(int start, int end, int n){//n la so dinh = so lan lap
	int front = 0;//chi so dau hang doi
	int rear = 0;//chi so cuoi hang doi
	queue[rear++] = start;//dinh dau tien duoc chon
	visited[start]=1;//dua dinh khoi tao vao danh sach da tham
	while(front < rear){//stack con phan tu
		int current = queue[front ++];//lay ra phan tu ra khoi hang doi
		printf("%d ", current);//in ra dinh vua duyet
		if(current == end){//dinh dang duyet la dinh ket thuc
			break;
		}
		for(int i=0; i<n; i++){
			if(dothi[current][i]==1 && visited[i]==0){//dua cac dinh noi voi current va chua duoc duyet vao hang doi
				queue[rear++] = i;//dua dinh hien tai vao hang doi
				visited[i]=1;//dua danh sach dinh dang xet vao mang da duyet
			}
		}
	}
	
}
int main() {
    int n, start, end;
    //nhap cac dinh cua do thi
    FILE *fp;
    fp = fopen(INPUT, "r");
    if(fp==NULL){
    	printf("File not found");
    }
    fscanf(fp,"%d",&n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp,"%d", &dothi[i][j]);
        }
    }
    fclose(fp);
	//in ra cac dinh cua do thi
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dothi[i][j]);
        }
        printf("\n");
    }
    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);
    printf("Nhap dinh ket thuc: ");
    scanf("%d", &end);
    bfs2(start, end, n);
    return 0;
}

