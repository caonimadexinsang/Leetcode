#include <stdio.h>
#include <iostream>
#include <stack>
//#include <deque>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
void main() {
	TreeNode *root;
	stack<TreeNode> Stackk;
	Stackk.push(*root);
	while (!Stackk.empty()) {
		TreeNode node = Stackk.pop();

	}
}