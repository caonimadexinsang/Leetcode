#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
void main() {
	vector<int> nums1(11);
	nums1 = { 1,2,2,3,4,6,8 };
	//vector<int> nums1 = {1,2,2,3,4,6,8};
	vector<int> nums2 = {3,5,7,8};
	int m = nums1.size();
	int n = nums2.size();
	int x = m - 1;
	int y = n - 1;
	for (int i = m + n - 1;i >= 0;i--) {
		if (x >= 0 && y >= 0) {
			if (nums1[x] >= nums2[y]) {
				nums1[i] = nums1[x];
				x--;
			}
			else {
				nums1[i] = nums2[y];
				y--;
			}
		}
		else if (x < 0 && y >= 0) {
			nums1[i] = nums2[y];
			y--;
		}
		else if (y < 0) {
			break;
		}
	}
	for (int i = 0;i < m + n;i++) {
		cout << nums1[i];
	}
}