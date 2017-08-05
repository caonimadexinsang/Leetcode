#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void dfs(TreeNode* root);
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
map<int, int> hashmap;
void main() {
	TreeNode* root;
	vector<int> result;
	int Max = 0;
	int man = 0;
	dfs(root);
	for (auto iter = hashmap.begin();iter != hashmap.end();iter++) {
		Max = max(Max,iter->second);
	}
	for (auto iter = hashmap.begin();iter != hashmap.end();iter++) {
		if (iter->second == Max) {
			result.push_back(iter->first);
		}
	}
}
void dfs(TreeNode* root) {
	if (root == NULL)
		return;
	if (root->left != NULL) {
		dfs(root->left);
		root->val += root->left->val;
	}
	if (root->right != NULL) {
		dfs(root->right);
		root->val += root->right->val;
	}
	hashmap[root->val] ++;
}