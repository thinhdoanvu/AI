#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define INPUT "BFS_DFS_1.txt"
//#define INPUT "BFS_DFS_2.txt"
//#define INPUT "BFS_DFS_3.txt"
//#define INPUT "BFS_DFS_4.txt"
//#define INPUT "BFS_DFS_5.txt"

int dothi[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];

int path[MAX_SIZE];
int len = 0;

void dfs(int current, int end, int n) {
    visited[current] = 1;
    path[len++] = current; //Them dinh hien tai vao duong di
    if (current == end) {
        //Hien thi duong di khi gap dinh ket thuc
        for (int i = 0; i < len; i++) {
            printf("%d ", path[i]);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (dothi[current][i] == 1 && visited[i] == 0) {
            dfs(i, end, n);
        }
    }
    len--; //Xoa dinh hien tai ra khoi duong di khi tro lai dinh truoc do
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
    dfs(start, end, n);
    return 0;
}

