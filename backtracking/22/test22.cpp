#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
vector<string> generate(int n,int leftcount, int rightcount, vector<string> &result, string resultstr);
void main() {
	int n = 3;
	char lefty = '(';
	char righty = ')';
	string left, right;
/*	for (int i = 0;i < n;i++) {
		left.push_back(lefty);
		right.push_back(righty);
	}*/
	int count = 0;
	vector<string> result;
	string resultstr;
	generate(n,0,0,result,resultstr);

}
vector<string> generate(int n,int leftcount,int rightcount,vector<string> &result, string resultstr) {
	//string resultstr;
	if (rightcount == n) {
		result.push_back(resultstr);
		return result;
	}
	else if (leftcount < n) {
		leftcount++;
		generate(n,leftcount,rightcount,result,resultstr + '(');
		if(&resultstr != NULL)
		resultstr.pop_back();
	//	leftcount--;
		return result;
	}
	if (leftcount > rightcount && rightcount < n) {
	
		rightcount++;
		generate(n,leftcount,rightcount,result,resultstr+ ')');
		resultstr.pop_back();
	//	rightcount--;
		return result;
	}
			
}