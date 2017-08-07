#include <stdio.h>
#include <iostream>
#define LEN (sizeof(TreeNode))
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
void CreateTree(TreeNode *root, int count, TreeNode *current,int &Max);
void PrintTree(TreeNode *root);
int CountDeepth(TreeNode *root);
void main() {
	TreeNode *root = (TreeNode*)malloc(LEN);
	TreeNode *current;
	current = root;
	int count = 0;
	int Max = 0;
	CreateTree(root,count,current,Max);
//	cout << "max:" << Max;
	//PrintTree(current);
	Max = 0; 
	count = 0;
	/*if (root != NULL&&root->val == 0)
		cout << "1";
	return;*/
	//CountDeepth(current, count, Max);
	Max = CountDeepth(current)-1;
	cout << "Max:" << Max;
}
//createTree的深度计数不准确
void CreateTree(TreeNode *root, int count, TreeNode *current, int &Max) {
	count++;
/*	if (count == 1) {
		
	}*/
	int temp;
	cin >> temp;
	root->val = temp;
	if (temp == 0) {
		root->right = root->left = NULL;
		count--;
		Max = max(Max,count);
	}
	else {
		root->left = (TreeNode*)malloc(LEN);
		CreateTree(root->left,count,current,Max);
		count--;
		root->right = (TreeNode*)malloc(LEN);
		CreateTree(root->right,count,current,Max);
	}
}
void PrintTree(TreeNode *root) {
	if (root->val == 0) {
		cout << "0";
		return;
	}
	else {
		cout << root->val;
		PrintTree(root->left);
		PrintTree(root->right);
	}
}
int CountDeepth(TreeNode *root) {
	if (root == NULL)
		return 0;
	else {
		int left = CountDeepth(root->left);
		int right = CountDeepth(root->right);
		return 1 + (left > right ? left : right);
	}
}