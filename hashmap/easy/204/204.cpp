#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int countPrimes(int n);
void main() {
	int n = 120;
	int count = countPrimes(n);
	cout << count;
}
int countPrimes(int n) {
	int count = 0;
	int *flag = new int[n];
	if (n <= 1)
		return 0;
	flag[0] = 1;
	flag[1] = 1;
	flag[2] = 0;
	//去掉的标记为1
	for (int i = 3;i < n;i++) {
		if (i % 2 == 0)
			flag[i] = 1;
		else
			flag[i] = 0;
	}
	for (int i = 3;i < sqrt(n);i++) {
		if (flag[i] == 0 && i*i <= n) {
			for (int j = 2;j * i <= n;j++) {
				flag[i*j] = 1;
			}
		}
	}
	for (int i = 2;i < n;i++) {
		if (flag[i] == 0)
			count++;
	}
	return count;
}