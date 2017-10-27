#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Build(int left, int right, vector<string>& result, string str);
void main(){
	int n = 2;
	vector<string> res;
	string str;
	Build(n,n,res,str);
	for (int i = 0;i < res.size();i++) {
		cout << res[i];
	}
}
void Build(int left, int right,vector<string>& result,string str) {
	if (left == 0 && right == 0) {
		result.push_back(str);
		return;
	}
	if (left != 0) {
		Build(left - 1,right,result,str+"(");
	}
	if (right != 0 && left < right) {
		Build(left, right - 1,result,str+")");
	}
}