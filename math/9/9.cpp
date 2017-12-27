#include <stdio.h>
#include <iostream>
using namespace std;
void main() {
	int x;
	int temp = x;
	cin >> x;
//	if (x < 0)
		//return 0;
//	if (x < 10)
	//	return true;
	int res = 0;
	while (x != 0) {
		res = res * 10 + x % 10;
		x = x / 10;
	}
	if (res == temp)
		cout << "true";
	else
		cout << "false";
}