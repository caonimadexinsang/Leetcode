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
void main() {
	//	TreeNode *root = (TreeNode*)malloc(sizeof(struct TreeNode));
	TreeNode *root = NULL;//由于CreateTree需要root作为参数，那么root必须被初始化。重要！！！！
	root = CreateTree(root);
	vector<vector<int>> result;
	vector<int> inner;
	queue<TreeNode*> q;
	if(root != NULL)
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		inner.clear();
		while (size > 0) {
			TreeNode *current = q.front();
			q.pop();
			inner.push_back(current->val);
			if (current->left != NULL)
				q.push(current->left);
			if (current->right != NULL)
				q.push(current->right);
			size--;
		}
		result.push_back(inner);
	}
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