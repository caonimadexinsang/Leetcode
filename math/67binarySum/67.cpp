#include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
void main() {
	string a = "11";
	string b = "1";
//	int aa = atoi(a.c_str());
	//cout << aa;
	int lenA = a.length();
	int lenB = b.length();
	int len = max(lenA,lenB);
	string result;
	char temp = '0';
	for (int i = 0;i < len;i++) {
		char avalue = lenA > i ? a[lenA - i - 1] : '0';
		char bvalue = lenB > i ? b[lenB - i - 1] : '0';
		char equal = (avalue == bvalue?'0':'1');
		if (equal == '0' && avalue == '0') {
			result = result + temp;
			temp = '0';
		}
		else if (equal == '0' && avalue == '1') {
			if (temp == '0')
				result = result + '0';
			else
				result = result + temp;
			temp = '1';
		}
		else if (equal == '1' && temp == '0') {
			result = result + '1';
			temp = '0';
		}
		else if (equal == '1' && temp == '1') {
			result = result + '0';
			temp = '1';
		}
	}
	if (temp == '1')
		result += temp;
	reverse(result.begin(),result.end());
	for (int i = 0;i < result.length();i++) {
		cout << result[i];
	}
}