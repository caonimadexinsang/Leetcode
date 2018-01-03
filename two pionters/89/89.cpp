#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void main() {
	vector<int> nums = {1,1,1,1,2,2,2,3,3};
	int length = nums.size();
	int count = 1;
	int result = 0;
	int pre = 1;
	int current = 0;
	for (int i = 1;i < length;i++) {
		current = i;
		if (nums[i] == nums[i - 1]) {
			if (count < 2) {
				count++;
				nums[pre] = nums[current];
				pre = pre + 1;
			}
			
		}
		
		else {
			nums[pre] = nums[current];
			count = 1;
			//nums[pre] = nums[current];
			pre = pre + 1;
		}
	}
	for (int i = 0;i < pre;i++) {
		cout << nums[i];
	}
}