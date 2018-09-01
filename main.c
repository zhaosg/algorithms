#include <stdio.h>
#include <stdlib.h>
#include "lib/BinaryTree.h"

int main() {
    BinaryTree *root = BinaryTree_init();
    BinaryTree_traverse_level(root);
    return 0;
}
