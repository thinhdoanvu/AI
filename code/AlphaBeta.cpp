#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_DEPTH 10
#define INF INT_MAX

typedef struct Node {
    int value;
    int alpha;
    int beta;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value, int alpha, int beta) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->alpha = alpha;
    node->beta = beta;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int alphaBeta(Node* node, int depth, int alpha, int beta, int maximizingPlayer) {
    if (depth == MAX_DEPTH || node == NULL) {
        return node->value;
    }
    if (maximizingPlayer) {
        int bestValue = -INF;
        Node* child = node->left;
        while (child != NULL) {
            int value = alphaBeta(child, depth+1, alpha, beta, 0);
            bestValue = (value > bestValue) ? value : bestValue;//tim max
            alpha = (alpha > bestValue) ? alpha : bestValue;
            if (beta <= alpha) {
                break;
            }
            child = child->left;
        }
        return bestValue;
    } 
	else {
        int bestValue = INF;
        Node* child = node->right;
        while (child != NULL) {
            int value = alphaBeta(child, depth+1, alpha, beta, 1);
            bestValue = (value < bestValue) ? value : bestValue;
            beta = (beta < bestValue) ? beta : bestValue;
            if (beta <= alpha) {
                break;
            }
            child = child->right;
        }
        return bestValue;
    }
}

int main() {
    Node* node1 = createNode(3, -INF, INF);
    Node* node2 = createNode(5, -INF, INF);
    Node* node3 = createNode(6, -INF, INF);
    Node* node4 = createNode(9, -INF, INF);
    Node* node5 = createNode(1, -INF, INF);
    Node* node6 = createNode(2, -INF, INF);
    Node* node7 = createNode(0, -INF, INF);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    int result = alphaBeta(node1, 0, -INF, INF, 1);
    printf("Best value: %d", result);
    return 0;
}

