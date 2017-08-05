#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
struct compare {
	bool operator()(pair<char, int> a, pair<char, int> b) const {
		return a.second > b.second;
	}
};
/*static bool compare(pair<char,int> a,pair<char,int> b){
	return a.second > b.second;
};*/
void main() {
	string s = "Aabb";
	string res;
	map<char, int> hash_map;
	vector<pair<char, int>> sortvec;
	vector<char> result;
	int length = s.size();
	//int length = sizeof(s)/sizeof(s[0]);
	//cout << length;
	
	for (int i = 0;i < length;i++) {
		hash_map[s[i]]++;
	}
	
	for (auto iter = hash_map.begin();iter != hash_map.end();iter++) {
		//sortvec.insert(iter->first,iter->second);
		//result.push_back(iter->first);
	//	sortvec.insert(pair<char,int>(iter->first,iter->second));
	//	sortvec.push_back(pair<char,int>(iter->first,iter->second));//这句也是对的
		sortvec.push_back(make_pair(iter->first,iter->second));
	//	cout << iter->first;
	}
	sort(sortvec.begin(), sortvec.end(), compare());
	for (int i = 0;i < sortvec.size();i++) {
		string str(sortvec[i].second, sortvec[i].first);
		res += str;
	}
	cout << res;
}