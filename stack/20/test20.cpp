#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
bool main() {
	string s = "()";
	stack<char> leftchar;
	int length = s.size();
	char temp;
	for (int i = 0;i < length;i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			leftchar.push(s[i]);
		}
		else {
			if (leftchar.empty())
				return false;
			temp = leftchar.top();
			if ((temp == '(' && s[i] == ')') || (temp == '[' && s[i] == ']') || (temp == '{'&& s[i] == '}')) {
				leftchar.pop();
			}
			else
				return false;//这种情况是出现的右符号与左边的不匹配，例如((]

		}
	}
	if (leftchar.empty()) {
		cout << "true";
		return true;
	}
	else
		return false;
}