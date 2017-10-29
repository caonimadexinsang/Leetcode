#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(4);
	int length = nums.size();
	vector<int> up(length,0);
	vector<int> down(length,0);
	for (int i = 1;i < nums.size();i++) {
		if (nums[i] > nums[i - 1]) {
			up[i] = down[i - 1] + 1;
			down[i] = down[i - 1];
		}
		else if (nums[i] < nums[i - 1]) {
			down[i] = up[i - 1] + 1;
			up[i] = up[i - 1];
		}
		else {
			up[i] = up[i - 1];
			down[i] = down[i - 1];
		}
	}
	int res = max(up[length - 1],down[length - 1]);
	cout << res;
}