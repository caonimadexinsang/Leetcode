#include <stdio.h>
#include <iostream>
#include <queue>
#define LEN (sizeof(TreeNode))
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution {
void CreateTree(TreeNode *root, int count, TreeNode *current);
void PrintTree(TreeNode* root);
void DFS(TreeNode* root, int curDepth);
private:
	vector<int> result;
	int depth = 0;
void main() {
	TreeNode *root = (TreeNode*)malloc(LEN);
	TreeNode *current = root;
	int count = 0;
	CreateTree(root,count,current);
	//PrintTree(current);
	queue<TreeNode*> que;
	int currt = 1;
	//que.push(root);
	//while (!que.empty()) {
	//	int length = que.size();
	//	while (length > 0) {
		//	TreeNode node = que.pop();

		//}
//	}
	DFS(root,1);
}
void DFS(TreeNode* root, int curDepth) {
	if (!root)
		return;
	if (depth < curDepth) {
		depth++;
		result.push_back(root->val);
	}
	DFS(root->right,curDepth + 1);
	DFS(root->left,curDepth + 1);
}
void CreateTree(TreeNode *root,int count,TreeNode *current) {
	int temp;
	cin >> temp;
	count++;
	if (temp == 0)
		root->val = NULL;
	if (count == 1) {
	//	root->val = temp;
		current = root;
	}
	if(temp != 0) {
		root->val = temp;
		root->left = (TreeNode*)malloc(LEN);
		CreateTree(root->left,count,current);
		root->right = (TreeNode*)malloc(LEN);
		CreateTree(root->right,count,current);
	}
}
void PrintTree(TreeNode* root) {
	if (root != NULL) {
		if (root->val == NULL)
			cout << "0";
		else {
			cout << root->val;
			PrintTree(root->left);
			PrintTree(root->right);
		}
	}
}
};