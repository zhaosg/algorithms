#include <stdio.h>
#include <stdlib.h>
#include "treenode.h"

int main() {
    BinaryTree *root = BinaryTree_init();
    BinaryTree_traverse_level(root);
    return 0;
}
