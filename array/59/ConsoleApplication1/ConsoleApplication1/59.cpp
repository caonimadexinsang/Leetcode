#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void main() {
	int n = 3;
	int height = n, width = n;
	int count = 1;
	vector<vector<int>> current(n, vector<int>(n,0));
	for (int i = 0, j = 0;i < width && j < height;i++, j++) {
		for (int y = j;y < width;y++) {
			//if(count <= n*n)
			current[i][y] = count;
			count++;
		}
		for (int x = i + 1;x < height;x++) {
			current[x][width - 1] = count;
			count++;
		}
		for (int y = width - 2;y >= i && width - i > 1;y--) {
			current[height - 1][y] = count;
			count++;
		}
		for (int x = height - 2;x > i && height - j >1;x--) {
			current[x][j] = count;
			count++;
		}
		width--;
		height--;
	}
	/*for (auto iter = current.begin();iter != current.end();iter++) {
		for (auto it = *iter.begin();it != *iter.end();it++) {
			
		}
	}*/
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << current[i][j];
		}
	}
}