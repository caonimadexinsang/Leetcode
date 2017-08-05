#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
struct TreeNodeWrapper {
	struct TreeNode *pNode;
	bool lVisited;
	bool rVisited;
	TreeNodeWrapper(TreeNode *p) { pNode = p;lVisited = false;rVisited = false;}
};
void main() {
	TreeNode *root;
	vector<int> result;
	stack<TreeNodeWrapper*> node_stack;
	node_stack.push(new TreeNodeWrapper(root));
	if (node_stack.top() == NULL)
		//return result;
	while (!node_stack.empty()) {
		TreeNodeWrapper *pNode = node_stack.top();
		if (pNode->lVisited || (pNode->pNode != NULL && pNode->pNode->left == NULL)) {//注意一定要判断
			node_stack.pop();
			if (pNode->pNode != NULL)//注意一定要判断
				result.push_back(pNode->pNode->val);
			if (pNode->pNode != NULL)//注意一定要判断
				if (pNode->pNode->right) {
					node_stack.push(new TreeNodeWrapper(pNode->pNode->right));
				}
			delete pNode;
		}
		else {
			if (pNode->pNode != NULL)//注意一定要判断
				node_stack.push(new TreeNodeWrapper(pNode->pNode->left));
			pNode->lVisited = true;
		}
	}
	//return result;
	
}