#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)

// Định nghĩa trạng thái của cây tìm kiếm
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Hàm tính giá trị minimax cho cây trạng thái
int minimax(struct Node* node, int depth, int isMax) {
    if (node == NULL) {
        return 0;
    }

    if (depth == 0) {
        return node->data;
    }

    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 2; i++) {
            int val = minimax(node->right, depth - 1, 0);
            best = max(best, val);
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 2; i++) {
            int val = minimax(node->left, depth - 1, 1);
            best = min(best, val);
        }
        return best;
    }
}

// Hàm thực hiện cắt tỉa Alpha-Beta
int alpha_beta(struct Node* node, int depth, int alpha, int beta, int isMax) {
    if (node == NULL) {
        return 0;
    }

    if (depth == 0) {
        return node->data;
    }

    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 2; i++) {
            int val = alpha_beta(node->right, depth - 1, alpha, beta, 0);
            best = max(best, val);
            alpha = max(alpha, best);
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 2; i++) {
            int val = alpha_beta(node->left, depth - 1, alpha, beta, 1);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    }
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 3;

    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 5;
    root->left->left = NULL;
    root->left->right = NULL;

    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 6;
    root->right->left = NULL;
    root->right->right = NULL;

    int depth = 2;

    printf("Minimax value: %d\n", minimax(root, depth, 1));
    printf("Alpha-Beta value: %d\n", alpha_beta(root, depth, INT_MIN, INT_MAX, 1));

    return 0;
}
