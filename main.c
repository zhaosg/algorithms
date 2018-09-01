#include <stdio.h>
#include <stdlib.h>
#include "lib/BinaryTree.h"
#include "lib/BinarySearchTree.h"

int main() {
    BinaryTree *root = BinaryTree_init();
    BinaryTree_traverse_level(root);
    int list[] = {1, 4, 6, 5, 10};
    BinarySearchTree *pBinarySearchTree = BinarySearchTree_init(list, 5);
    printf("\n");
    BinarySearchTree_traverse_level(pBinarySearchTree);
    return 0;
}
