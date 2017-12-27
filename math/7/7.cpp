#include <stdio.h>
#include <iostream>
using namespace std;
void main() {
	int x;
	cin >> x;
	int result = 0;
	bool tt;
	while (x != 0) {
		if (result > INT_MAX / 10 || result < INT_MIN / 10)
		//	return 0;
		result = result * 10 + x % 10;
		x = x / 10;
	}
	//if (tt == true)
	//	result = result;
//	else
	//	result = 0 - result;
	cout << result;
}