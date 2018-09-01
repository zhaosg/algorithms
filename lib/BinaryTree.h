typedef struct {
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
} BinaryTree;

BinaryTree *BinaryTree_init();

void BinaryTree_visit(BinaryTree *node);

void BinaryTree_destroy(BinaryTree *node);

void BinaryTree_traverse_lrd(BinaryTree *node);

void BinaryTree_traverse_ldr(BinaryTree *node);

void BinaryTree_traverse_dlr(BinaryTree *node);

void BinaryTree_traverse_level(BinaryTree *root);