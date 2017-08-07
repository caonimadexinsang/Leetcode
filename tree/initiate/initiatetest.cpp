#include <stdio.h>
#include <iostream>
using namespace std;
#define LEN (sizeof(TreeNode))
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
void CreatBiTree(TreeNode *root, int count, TreeNode *curent);
void PrintTree(TreeNode * root);
void main() {
	TreeNode *root = (TreeNode*)malloc(LEN);
	TreeNode *current = root;
	//TreeNode *root;
	int count = 0;
	CreatBiTree(root,count,current);
	//TreeNode *
	PrintTree(current);
}
void CreatBiTree(TreeNode *root,int count,TreeNode *curent) {
	int temp;
	count++;
	if (count == 1)
		curent = root;
	//root = (TreeNode*)malloc(LEN);
	cin >> temp;
	if (temp == 0) {
		//cout << "null";
		root->val = NULL;//不能写成root = NULL,因为已经为root分配空间了，如果这样赋值，就不是让root等于null，而是让root指向null，那么root就不等于null即0，等于null
		//即使在这儿把NULL赋值给root了，但是由于递归是引用，回到上一级的时候，这个赋值是无效的，递归的引用问题



	//	root->left = root -> right = NULL;
		//cout << "root" << root << endl;
		//cout << "root->val" << root->val << endl;
	}
	else {
		root->val = temp;
		root->left = (TreeNode*)malloc(LEN);
		CreatBiTree(root->left, count,curent);
		root->right = (TreeNode*)malloc(LEN);
		CreatBiTree(root->right,count, curent);
	}
}
void PrintTree(TreeNode* root) {
	if (root->val == NULL)
		cout << "0";
	else if(root != NULL) {
		cout << root->val;
		PrintTree(root->left);
		PrintTree(root->right);
	}
}