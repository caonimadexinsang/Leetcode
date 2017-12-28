#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void main() {
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);
	sort(nums.begin(),nums.end());
	vector<vector<int>> result;
	int length = nums.size();
	int before;
	int after;
	for (int i = 0;i < length - 2;i++) {
		before = i + 1;
		after = length - 1;
		while (before < after) {
			if (nums[i] + nums[before] + nums[after] > 0) {
				after--;
			}
			else if (nums[i] + nums[before] + nums[after] < 0)
			{
				before++;
			}
			else {
				vector<int> current;
				current.push_back(nums[i]);
				current.push_back(nums[before]);
				current.push_back(nums[after]);
				result.push_back(current);
				before++;
				while (nums[before] == nums[before - 1])
					before++;
				after--;
				while (nums[after] == nums[after + 1])
					after--;
			}
		}
		while (i < length - 2 && nums[i] == nums[i + 1])
			i++;
	}
	//用迭代器读取二维,vector<vector<int>> result;
	for (auto iter = result.begin();iter < result.end();iter++) {
		vector<int>::iterator it;
		for (it = (*iter).begin();it < (*iter).end();it++) {
			cout << *it << "";
		}
		cout << endl;
	}
}