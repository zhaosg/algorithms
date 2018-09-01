#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
} BinaryTree;

BinaryTree *BinaryTree_init() {
    BinaryTree *root = (BinaryTree *) malloc(sizeof(BinaryTree));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    BinaryTree *left = (BinaryTree *) malloc(sizeof(BinaryTree));
    left->data = 2;
    left->left = NULL;
    left->right = NULL;


    BinaryTree *right = (BinaryTree *) malloc(sizeof(BinaryTree));
    right->data = 3;
    right->left = NULL;
    right->right = NULL;
    root->left = left;
    root->right = right;

    BinaryTree *left1 = (BinaryTree *) malloc(sizeof(BinaryTree));
    left1->data = 4;
    left1->left = NULL;
    left1->right = NULL;


    BinaryTree *right1 = (BinaryTree *) malloc(sizeof(BinaryTree));
    right1->data = 5;
    right1->left = NULL;
    right1->right = NULL;
    left->left = left1;
    left->right = right1;

    BinaryTree *left2 = (BinaryTree *) malloc(sizeof(BinaryTree));
    left2->data = 6;
    left2->left = NULL;
    left2->right = NULL;

    BinaryTree *right2 = (BinaryTree *) malloc(sizeof(BinaryTree));
    right2->data = 7;
    right2->left = NULL;
    right2->right = NULL;
    right->left = left2;
    right->right = right2;
    return root;
}

void BinaryTree_visit(BinaryTree *node) {
    if (node == NULL)
        return;
    printf(" %d ", node->data);
}

void BinaryTree_destroy(BinaryTree *node) {
    if (node == NULL)
        return;
    BinaryTree_destroy(node->left);
    BinaryTree_destroy(node->right);
    free(node);
}

void BinaryTree_traverse_lrd(BinaryTree *node) {
    if (node == NULL)
        return;
    BinaryTree_traverse_lrd(node->left);
    BinaryTree_traverse_lrd(node->right);
    BinaryTree_visit(node);
}

void BinaryTree_traverse_ldr(BinaryTree *node) {
    if (node == NULL)
        return;
    BinaryTree_traverse_ldr(node->left);
    BinaryTree_visit(node);
    BinaryTree_traverse_ldr(node->right);
}

void BinaryTree_traverse_dlr(BinaryTree *node) {
    if (node == NULL)
        return;
    BinaryTree_visit(node);
    BinaryTree_traverse_dlr(node->left);
    BinaryTree_traverse_dlr(node->right);
}

void BinaryTree_traverse_level(BinaryTree *root) {
    if (root == NULL)
        return;
    int c = 0, v = 0;
    BinaryTree *p[100];
    p[v] = root;
    while (c <= v) {
        BinaryTree *current = p[c++];
        if (current != NULL) {
            BinaryTree_visit(current);
            if (current->left != NULL)
                p[++v] = (current->left);
            if (current->right != NULL)
                p[++v] = (current->right);
        }

    }
}