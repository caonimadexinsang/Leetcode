#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void main() {
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(-2);
	/*nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);*/
	//vector<int> 
	int length = nums.size();
	//if (length == 1)
		//return nums[0];
	int count = nums[0];
	int maxsum = nums[0];
	for (int i = 1;i < length;i++) {
		count = max(count + nums[i],nums[i]);
		maxsum = max(maxsum,count);
	}
	cout << maxsum;
}