#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void backtracking(int n, int k, int count, int current, vector<int> &str, vector<vector<int>> &result);
void main() {
	int n = 4;
	int k = 2;

	int count = 0;
	int current = 1;
	vector<int> str;
	vector<vector<int>> result;
	backtracking(n,k,count,current,str,result);
}
void backtracking(int n, int k, int count, int current, vector<int> &str, vector<vector<int>> &result) {
	if (count == k) {
		result.push_back(str);
		return;
	}
	for (int i = current;i <= n;i++) {
		str.push_back(i);
		backtracking(n, k, count+1, i+1, str, result);//ע��������i+1����Ҫ��ȵĻ���������current+1
		str.pop_back();
	}
	//return result;
}