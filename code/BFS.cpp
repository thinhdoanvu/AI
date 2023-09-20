#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // K�ch thu?c t?i da c?a h�ng d?i

int adj_matrix[100][100]; // Ma tr?n k? bi?u di?n d? th?
int visited[100]; // M?ng d�nh d?u c�c d?nh d� du?c tham
int queue[MAX_QUEUE_SIZE]; // H�ng d?i d? luu tr? c�c d?nh ch? tham

void bfs(int start, int n) {
    int front = 0, rear = 0;
    queue[rear++] = start; // Th�m d?nh start v�o h�ng d?i
    visited[start] = 1; // ��nh d?u d?nh start d� du?c tham
    while (front < rear) {
        int current = queue[front++]; // L?y d?nh d?u ti�n trong h�ng d?i
        printf("%d ", current); // In ra d?nh d�
        for (int i = 0; i < n; i++) {
            if (adj_matrix[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i; // Th�m d?nh i v�o h�ng d?i
                visited[i] = 1; // ��nh d?u d?nh i d� du?c tham
            }
        }
    }
}

int main() {
    int n, start;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);
    printf("Nhap ma tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);
    bfs(start, n);
    return 0;
}

