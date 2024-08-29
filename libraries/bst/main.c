#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

typedef struct TreeNode TreeNode;

void printInorder(TreeNode* root){
	if(!root) return;
	printInorder(getLeft(root));
	printf("%d ", getVal(root));
	printInorder(getRight(root));
}

void printPreorder(TreeNode* root){
	if(!root) return;
	printf("%d ", getVal(root));
	printPreorder(getLeft(root));
	printPreorder(getRight(root));
}

TreeNode* rightMin(TreeNode* root){
	while(getLeft(root)){
		root = getLeft(root);
	}
	return root;
}

TreeNode* deleteNode(TreeNode* root, int del){
	if(!root) return NULL;
	if(getVal(root) == del){
		//leaf node
		if(!getLeft(root) && !getRight(root)){
			free(root);
			return NULL;
		}
		else if(getLeft(root) && !getRight(root)){
			TreeNode* del = root;
			root = getLeft(root);
			free(del);
			return root;
		}
		else if(!getLeft(root) && getRight(root)){
			TreeNode* del = root;
			root = getRight(root);
			free(del);
			return root;
		}
		else if(getLeft(root) && getRight(root)){
			int value = getVal(rightMin(getRight(root)));
			setVal(root, value);
			setRight(root, deleteNode(getRight(root), value));
		}
	}
	else if(getVal(root) > del)
		setLeft(root, deleteNode(getLeft(root), del));
	else
		setRight(root, deleteNode(getRight(root), del));
	return root;
}

int main(){
	int n;
	scanf("%d", &n);
	
	int* array = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) scanf("%d", &array[i]);


	TreeNode* root = createBST(array, n);
	int del;
	scanf("%d", &del);
	root = deleteNode(root, del);

	printPreorder(root);
	return 0;
}
