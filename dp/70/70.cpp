#include <stdio.h>
#include <iostream>
using namespace std;
void main() {
	int n = 5;
	int ret = 0;
	int *r = new int[n];
	if (n <= 0) {
		ret = 0;
		return;
	}
	else if (n == 1) {
		ret = 1;
		return;
	}
	else if (n == 2) {
		ret = 2;
		return;
	}
	r[0] = 1;
	r[1] = 2;
	for (int i = 2;i < n;i++) {
		r[i] = r[i - 1] + r[i - 2];
	}
	ret = r[n - 1];
	cout << ret;
	delete []r;
}