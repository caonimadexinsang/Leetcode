#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void main() {
	vector<int> prices;
	prices.push_back(7);
	prices.push_back(6);
	prices.push_back(4);
	prices.push_back(3);
	prices.push_back(3);
	prices.push_back(1);
	int length = prices.size();
	if (length == 0) {
		return;
	}
	int curmin = prices[0];
	int profit = 0;
	for (int i = 0;i < length;i++) {
		int temp = prices[i];
		curmin = min(curmin,temp);
		profit = max(profit,temp - curmin);
	}
	cout << profit;
}