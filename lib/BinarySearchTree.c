#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

BinarySearchTree *BinarySearchTree_init(int list[], int length) {
    BinarySearchTree *root = NULL;
    for (int i = 0; i < length; i++) {
        root = BinarySearchTree_insert(root, list[i]);
    }
    return root;
}

BinarySearchTree *BinarySearchTree_rootNode(int data) {
    BinarySearchTree *subTree = (BinarySearchTree *) malloc(sizeof(BinarySearchTree));
    subTree->data = data;
    subTree->left = NULL;
    subTree->right = NULL;
    subTree->parent = NULL;
    return subTree;
}

BinarySearchTree *BinarySearchTree_insert(BinarySearchTree *tree, int data) {
    BinarySearchTree *root = tree;
    if (root == NULL) {
        root = BinarySearchTree_rootNode(data);
    } else {
        if (data < tree->data) {
            if (tree->left == NULL) {
                BinarySearchTree *subTree = BinarySearchTree_rootNode(data);
                tree->left = subTree;
                subTree->parent = tree;
            } else {
                BinarySearchTree_insert(tree->left, data);
            }
        } else {
            if (tree->right == NULL) {
                if (tree->left == NULL && tree->parent == NULL) {
                    BinarySearchTree *subTree = BinarySearchTree_rootNode(data);
                    tree->parent = subTree;
                    subTree->left = tree;
                    root = subTree;
                } else {
                    BinarySearchTree *subTree = BinarySearchTree_rootNode(data);
                    tree->right = subTree;
                    subTree->parent = root;
                }
            } else {
                BinarySearchTree_insert(tree->right, data);
            }
        }
    }

    return root;
}

void BinarySearchTree_visit(BinarySearchTree *node) {
    if (node == NULL)
        return;
    printf(" %d ", node->data);
}

void BinarySearchTree_traverse_level(BinarySearchTree *root) {
    if (root == NULL)
        return;
    int c = 0, v = 0;
    BinarySearchTree *p[100];
    p[v] = root;
    while (c <= v) {
        BinarySearchTree *current = p[c++];
        if (current != NULL) {
            BinarySearchTree_visit(current);
            if (current->left != NULL)
                p[++v] = (current->left);
            if (current->right != NULL)
                p[++v] = (current->right);
        }

    }
}