#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
void main() {
		vector<int> result;
		int k = 2;
		int nums[] = {1,1,1,2,2,3};
		int length = sizeof(nums);
		map<int, int> hash;
		sort(nums,nums + length/sizeof(int));
	for (int i = 0;i < length/sizeof(int);i++) {
	/*if (hash.end == hash.find(nums[i])) {
	hash[]
	}*/
		cout << nums[i];
	hash[nums[i]]++;
	}
	cout << "...........";
	priority_queue<pair<int,int>> pri_que;
	for (auto it = hash.begin();it != hash.end();it++) {
	pri_que.push(make_pair(it->second,it->first));
	}
	while (result.size() < k) {
	result.push_back(pri_que.top().second);
	cout << pri_que.top().second;
	pri_que.pop();
	
	} 
}