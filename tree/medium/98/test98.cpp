#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
bool Judge(TreeNode * root, int min, int max);
bool main() {
	TreeNode *root;
	return Judge(root, 0,0);
}
bool Judge(TreeNode * root, int min, int max) {
	stack<TreeNode*> node_stack;
	TreeNode *pNode = root; 
	//int min = 0;
	//	int max = 0;
	if (root == NULL) {
		return true;
	}
	//node_stack.push(root);
	//while (!node_stack.empty()) {
		if (pNode->left) {
			if (pNode->val > pNode->left->val && pNode->left->val < min) {
					min = pNode->left->val;
			//	node_stack.push(pNode->left);
				//pNode = node_stack.top();
				Judge(pNode->left,min,max);
			}
			else
				return false;
		}
		else {
			//node_stack.pop();
			if (pNode->right) {
				if (pNode->right->val > pNode->val && pNode->right->val > max) {
					max = pNode->right->val;
					//node_stack.push(pNode->right);
					Judge(pNode->right, min, max);
				}
				else
					return false;
			}
		//	pNode = node_stack.top();
		}
	//}
	return true;
}