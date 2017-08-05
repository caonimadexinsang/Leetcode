#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void main() {
	int n = 3;
//	vector<int> f(n + 1, 0);
//	int f[] = new int[n + 1];
	f[0] = 1;
	f[1] = 1;
	int countnum = 0;

	for (int i = 2;i < n;i++) {
		for (int j = 0;j < n;j++) {
			f[i] = f[j] * f[i - j - 1];
		}
	}
	cout << f[n];
}