#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
void main() {
	string s = "AAAAACCCCCAAAAACCCCCAAAAAGGGTTT";
	int length = sizeof(s);
	string temp;
	vector<string> result;
	if (length < 10)
		return;
	unordered_map<string, int> all;
	
	for (int i = 0;i < length-9;i++) {
		temp = s.substr(i,10);
		if (all.find(temp) == all.end()) {
			all[temp] = 1;
		}
		else
			result.push_back(temp);
	}
}