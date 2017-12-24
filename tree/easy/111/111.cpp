#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
TreeNode* CreateTree(TreeNode *root);
void PrintTree(TreeNode *root);
int Depth(TreeNode *root);
void main() {
	//	TreeNode *root = (TreeNode*)malloc(sizeof(struct TreeNode));
	TreeNode *root = NULL;//由于CreateTree需要root作为参数，那么root必须被初始化。重要！！！！
	root = CreateTree(root);
	//PrintTree(root);
	int depth = Depth(root);
	cout << endl;
	cout << depth;
}
int Depth(TreeNode *root) {
	if (root == NULL)
		return 0;
	 int r = Depth(root->left);
	 int l = Depth(root->right);
	 if (r == 0)
		 return l + 1;
	 if (l == 0)
		 return r + 1;
	 return min(l,r)+1;
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