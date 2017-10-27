#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void main() {
	int nums[8] = {10,9,2,5,3,7,101,18};
	int length = 8;
	int res = 0;
	vector<int> count(length,1);
	for (int i = 0;i < length;i++) {
		for (int j = 0;j < i;j++) {
			if (nums[j] < nums[i]) {
				count[i] = max(count[j]+1,count[i]);
			}
		}
		res = max(res,count[i]);
	}
	cout << res;
}