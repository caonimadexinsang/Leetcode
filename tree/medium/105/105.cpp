#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
TreeNode* CreateTree(TreeNode *root);
void PrintTree(TreeNode *root);
TreeNode* build(int prestart, int instart, int inend, int preorder[], int inorder[]);
void main() {
	//	TreeNode *root = (TreeNode*)malloc(sizeof(struct TreeNode));
	TreeNode *root = NULL;//由于CreateTree需要root作为参数，那么root必须被初始化。重要！！！！
//	root = CreateTree(root);
	vector<int> result;
	//cout << result;
	int preorder[7] = {4,2,1,3,7,6,9};
	int inorder[7] = {1,2,3,4,6,7,9};
	root = build(0,0,6,preorder,inorder);
	PrintTree(root);
}
TreeNode* build(int prestart, int instart, int inend, int preorder[], int inorder[]) {
	if (instart > inend || inend >= 7) {
		return NULL;
	}
	TreeNode *root = new TreeNode(preorder[prestart]);
	int index = 0;
//	if (inend > sizeof(preorder) - 1)
	//	inend = sizeof(preorder) - 1;
	for (int i = instart;i <= inend;i++) {
		if (root->val == inorder[i]) {
			index = i;
			break;
		}
	}
	root->left = build(prestart + 1,instart,index -1,preorder,inorder);
	root->right = build(prestart + index + 1 - instart,index + 1,inend,preorder,inorder);
	return root;
}
TreeNode* CreateTree(TreeNode *root) {
	int temp;
	cin >> temp;
	if (temp == 0) {
		root = NULL;
		return root;
	}
	else {
		//root = (TreeNode*)malloc(sizeof(struct TreeNode));
		root = new TreeNode(-1);
		root->val = temp;
		root->left = CreateTree(root->left);
		root->right = CreateTree(root->right);
	}
	return root;
}
void PrintTree(TreeNode *root) {
	if (root) {
		cout << root->val;
		PrintTree(root->left);
		PrintTree(root->right);
	}
}