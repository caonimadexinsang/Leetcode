#include <stdio.h>
#include <iostream>
#define LEN sizeof(TreeNode)
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
void CreateTree(TreeNode *root, int count, TreeNode *current);
void PrintTree(TreeNode* root);
void TreeSum(TreeNode *root, int res, int &Res);
void main(){
	TreeNode *root = (TreeNode*)malloc(LEN);
	TreeNode *current = root;
	int count = 0;
	CreateTree(root,count,current);
	//PrintTree(current);
	int res = 0;
	int Res = 0;
	TreeSum(root,res,Res);
	cout << "Res:" << Res;
}
void TreeSum(TreeNode *root,int res,int &Res) {
	cout << "root->val:" << root->val;
	if (root != NULL && root->val != NULL) {
		res = res * 10 + root->val;
		if (root->left->val == NULL && root->right->val == NULL) {
			//		res += res * 10 + root->val;
			Res += res;
		}
		else {
			TreeSum(root->left, res, Res);
			TreeSum(root->right, res, Res);
		}
	}
}
void CreateTree(TreeNode *root,int count,TreeNode *current) {
	int temp;
	cin >> temp;
	count++;
	if (count == 1) {
		current = root;
	}
	if (temp == 0)
		root->val = NULL;
	if (temp != 0) {
		root->val = temp;
		root->left = (TreeNode*)malloc(LEN);
		CreateTree(root->left, count, current);
		root->right = (TreeNode*)malloc(LEN);
		CreateTree(root->right, count, current);
	}
}
void PrintTree(TreeNode* root) {
	if (root->val == NULL)
		cout << "0";
	else if (root != NULL) {
		cout << root->val;
		PrintTree(root->left);
		PrintTree(root->right);
	}
}