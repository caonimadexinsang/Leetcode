#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void backtracking(vector<int> nums, vector<vector<int>> &result, vector<int> &finded);
void main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int>> result;
	vector<int> finded;
	backtracking(nums,result,finded);

}
void backtracking(vector<int> nums,vector<vector<int>> &result,vector<int> &finded) {
	//int length = nums.size();
	if (nums.size() == finded.size()) {
		result.push_back(finded);
	}
	else {
		for (int i = 0;i < nums.size();i++) {
			auto iter = finded.begin();
			iter = find(finded.begin(), finded.end(), nums[i]);//////////////////
			if (iter == finded.end()) {//////////////
				finded.push_back(nums[i]);
				backtracking(nums,result,finded);
				finded.pop_back();
			}
		}
	}
}