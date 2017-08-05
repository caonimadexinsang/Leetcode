#include <stdio.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
bool isMirror(TreeNode *root, TreeNode *root1);
void main() {
	TreeNode *root;
	isMirror(root, root);
}
bool isMirror(TreeNode *root, TreeNode *root1) {
	if (root == NULL && root1 == NULL)
		return true;
	else if (root == NULL && root1 != NULL)
		return false;
	else if (root != NULL && root1 == NULL)
		return false;
	return((root->val == root1->val) && (isMirror(root->left,root1->right) && (root->right,root1->left)));
}