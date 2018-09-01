typedef struct {
    int data;
    struct BinarySearchTree *parent;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
} BinarySearchTree;

BinarySearchTree* BinarySearchTree_init(int list[],int length);
BinarySearchTree *BinarySearchTree_insert(BinarySearchTree *tree, int data);
void BinarySearchTree_traverse_level(BinarySearchTree *root);