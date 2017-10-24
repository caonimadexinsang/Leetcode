#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
void main() {
	vector<int> nums;
	int target = 2;
	int index;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
//	nums.push_back(6);
	if (nums.size() < 1) {
		index = 0;
	}
	else if (nums.size() == 1) {
		if (target == nums[0])
			index = 0;
		else if (target > nums[0])
			index = 1;
		else
			index = 0;
	}
	else {
		if (target < nums[0])
			index = 0;
		else if (target > nums[nums.size() - 1])
			index = nums.size();
		else {
			for (int i = 0;i < nums.size();i++) {
				if (target == nums[i]) {
					index = i;
					//return;
				}
				else if (target < nums[i]) {
					index = i;
					//return;
				}
				else if (target > nums[i]) {
					index = i + 1;
				}
			}
		}
	}
	cout << index;
}