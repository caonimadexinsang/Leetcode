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
		root->val = NULL;//����д��root = NULL,��Ϊ�Ѿ�Ϊroot����ռ��ˣ����������ֵ���Ͳ�����root����null��������rootָ��null����ôroot�Ͳ�����null��0������null
		//��ʹ�������NULL��ֵ��root�ˣ��������ڵݹ������ã��ص���һ����ʱ�������ֵ����Ч�ģ��ݹ����������



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