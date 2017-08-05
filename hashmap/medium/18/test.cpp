#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void main() {
	vector<int> nums = {-3,-2,-1,0,0,1,2,3};
	vector<vector<int>> result;
	//map<int,vector<>>
	map<int, vector<int>> hasmap;
	vector<int> med;
	int length = nums.size();
	int begin, end;
	int res;
	int target = 0;
	int count = 0;
	sort(nums.begin(),nums.end());
	for (int i = 0;i < length - 3;i++) {
		for (int j = i + 1;j < length - 2;j++) {
			end = length - 1;
			begin = j + 1;
			while(begin < end) {
			res = nums[i] + nums[j] + nums[begin] + nums[end];
			if (res == target) {
				//med.push_back(nums[i]);
				//med.push_back(nums[j]);
				//med.push_back(nums[begin]);
			//	med.push_back(nums[end]);
				hasmap[count].push_back(nums[i]);
				hasmap[count].push_back(nums[j]);
				hasmap[count].push_back(nums[begin]);
				hasmap[count].push_back(nums[end]);
				count++;
				while (nums[begin] == nums[begin + 1]) {
					begin++;
				}
					begin++;
			}
			else if (res < target)
				begin++;
			else
				end--;
		 }
			while (nums[j] == nums[j + 1])
				j++;
		}
		while (nums[i] == nums[i + 1])
			i++;
	}
	for (map<int,vector<int>>::iterator iter = hasmap.begin();iter != hasmap.end();iter++) {
		result.push_back(iter->second);
		//cout << iter->second;
	}
}