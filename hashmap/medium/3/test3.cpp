#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
void main() {
	string s = "jbpnbwwd";
	int length = s.size();
	map<char, int> hashmap;
	int Max = 0;
	if (length == 1) {
		Max = 1;
	}
	int t = 0;
	while (t <= length) {
		for (int i = t;i < length;i++) {//从0开始每个字符都要作为开始
			auto iter = hashmap.begin();
			iter = hashmap.find(s[i]);
			if (iter == hashmap.end()) {
				//hashmap.insert(pair<char,int>(s[i],i));
				hashmap.insert(make_pair(s[i], i));
				

			}
			else {
				//int len = hashmap.size();
			//	Max = max(Max,len);
				int len = hashmap.size();
				Max = max(Max, len);
			//	i = i - 1;
				hashmap.clear();
				break;
			}
		}
		t++;
	}
	cout << Max;
}