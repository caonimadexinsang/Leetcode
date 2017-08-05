#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
void main() {
	vector<int> prices;
	prices.push_back(5);
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(3);
	prices.push_back(4);
	int length = prices.size();
	int profit = 0;
	for (int i = 1;i < length;i++) {
		if (prices[i] > prices[i - 1]) {
			profit = profit + (prices[i] - prices[i - 1]);
		}
	}
	cout << profit;
}