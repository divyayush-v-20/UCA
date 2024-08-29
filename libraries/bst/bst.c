#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TreeNode;

TreeNode* insert(TreeNode* root, int val){
	if(!root){
		TreeNode* newNode = (TreeNode *)malloc(sizeof(TreeNode));
		newNode -> left = NULL;
		newNode -> right = NULL;
		newNode -> val = val;
		return newNode;
	}
	if(root -> val > val) root -> left = insert(root -> left, val);
	else root -> right = insert(root -> right, val);
	return root;
}

TreeNode* createBST(int* array, int n){
	TreeNode* root = NULL;
	for(int i = 0; i < n; i++){
		root = insert(root, array[i]);
	}
	return root;
}

TreeNode* getLeft(TreeNode* root){
	return root -> left;
}

TreeNode* getRight(TreeNode* root){
	return root -> right;
}

int getVal(TreeNode* root){
	return root -> val;
}

void setVal(TreeNode* root, int val){
	root -> val = val;
}

void setLeft(TreeNode* root, TreeNode* left){
	root -> left = left;
}

void setRight(TreeNode* root, TreeNode* right){
	root -> right = right;
}

