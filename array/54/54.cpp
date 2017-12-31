#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void main() {
	vector<vector<int>> matrix;
	vector<int> matrix1  = {7};
	vector<int> matrix2 = {9};
	vector<int> matrix3 = {6};
	matrix.push_back(matrix1);
	matrix.push_back(matrix2);
	matrix.push_back(matrix3);
	int high = matrix.size();
	int width = matrix[0].size();
	vector<int> order;
	for (int i = 0, j = 0;i < high, j < width;i++, j++) {
		for (int y = j;y < width;y++) {
			order.push_back(matrix[i][y]);
		}
		for (int x = i + 1;x < high;x++) {
			order.push_back(matrix[x][width - 1]);
		}
		for (int y = width - 2;y >= i && i != high - 1;y--) {
			order.push_back(matrix[high - 1][y]);
		}
		for (int x = high - 2;x > i && j != width - 1;x--) {
			order.push_back(matrix[x][j]);
		}
		high--;
		width--;
	}
	for (auto iter = order.begin();iter != order.end();iter++) {
		cout << *iter;
	}
}