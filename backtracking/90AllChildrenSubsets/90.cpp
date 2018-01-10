#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void helper(vector<int> &nums, int temp, vector<int> &res, vector<vector<int>> &result);
void main() {
	vector<int> nums = {1,2,2};
	sort(nums.begin(),nums.end());
	int temp = 0;
	vector<int> res = {};
	vector<vector<int>> result;
	result.push_back(res);
	helper(nums,temp,res,result);
	for (auto iter = result.begin();iter < result.end();iter++) {
		vector<int>::iterator it;
		for (it = (*iter).begin();it < (*iter).end();it++) {
			cout << *it << "";
		}
		cout << endl;
	}
}
void helper(vector<int> &nums, int temp, vector<int> &res, vector<vector<int>> &result) {
	if (temp == nums.size()) {
		return;
	}
	for (int i = temp;i < nums.size();i++) {
		res.push_back(nums[i]);
		result.push_back(res);
		helper(nums,i + 1,res,result);
		res.pop_back();
	while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
			i++;
		}
	}
	
}