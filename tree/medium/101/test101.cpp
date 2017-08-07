#include <stdio.h>
#include <iostream>
#define LEN (sizeof(TreeNode))
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
void CreatTree(TreeNode *root, int count, TreeNode *current);
void PrintTree(TreeNode *root);
bool isMirror(TreeNode *root, TreeNode *root1);
void main() {
	TreeNode *root;
	TreeNode *current;
	int count = 0;
	root = (TreeNode*)malloc(LEN);
	current = root;//记住一定要先给root申请内存，并且要给current初始化
	CreatTree(root,count,current);
	root = current;
	PrintTree(current);
	bool result = isMirror(root->left, root->right);
	cout << "result:" << result;
}
bool isMirror(TreeNode *root, TreeNode *root1) {
	if (root == NULL && root1 == NULL)
		return true;
	else if (root == NULL && root1 != NULL)
		return false;
	else if (root != NULL && root1 == NULL)
		return false;
	//return((root->val == root1->val) && (isMirror(root->left,root1->right) && (root->right,root1->left)));
	if (root->val == root1->val) {
		bool isSame1 = isMirror(root->left,root1->right);
		bool isSame2 = isMirror(root->right,root1->left);
		return isSame1&&isSame2;
	}
	return false;
}
void CreatTree(TreeNode *root, int count, TreeNode *current) {
	int temp;
	count++;
	if (count == 1)
		current = root;
		cin >> temp;
		if (temp == 0) {
			root->val = NULL;
			root->left = root->right = NULL;
		}
		else {
			root->val = temp;
			root->left = (TreeNode*)malloc(LEN);
			CreatTree(root->left,count,current);
			root->right = (TreeNode*)malloc(LEN);
			CreatTree(root->right,count,current);
	}
}
void PrintTree(TreeNode *root) {
	if (root->val == NULL)
		cout << "0";
	else if (root != NULL) {
		cout << root->val;
		PrintTree(root->left);
		PrintTree(root->right);
	}
}