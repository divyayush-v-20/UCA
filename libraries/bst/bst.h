#include <stdbool.h>

typedef struct TreeNode TreeNode;

TreeNode* insert(TreeNode* root, int val);

TreeNode* createBST(int* array, int n);

TreeNode* getLeft(TreeNode* root);

TreeNode* getRight(TreeNode* root);

int getVal(TreeNode* root);

void setVal(TreeNode* root, int val);

void setLeft(TreeNode* a, TreeNode* b);

void setRight(TreeNode* a, TreeNode* b);

