#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100 // Kích thu?c t?i da c?a hàng d?i

int adj_matrix[100][100]; // Ma tr?n k? bi?u di?n d? th?
int visited[100]; // M?ng dánh d?u các d?nh dã du?c tham
int queue[MAX_QUEUE_SIZE]; // Hàng d?i d? luu tr? các d?nh ch? tham

void bfs(int start, int n) {
    int front = 0, rear = 0;
    queue[rear++] = start; // Thêm d?nh start vào hàng d?i
    visited[start] = 1; // Ðánh d?u d?nh start dã du?c tham
    while (front < rear) {
        int current = queue[front++]; // L?y d?nh d?u tiên trong hàng d?i
        printf("%d ", current); // In ra d?nh dó
        for (int i = 0; i < n; i++) {
            if (adj_matrix[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i; // Thêm d?nh i vào hàng d?i
                visited[i] = 1; // Ðánh d?u d?nh i dã du?c tham
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

