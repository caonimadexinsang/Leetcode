#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void main() {
	vector<vector<int>> grid;
	vector<int> a = { 1,3,1 };
	vector<int> b = { 1,5,1 };
	vector<int> c = { 4,2,1 };
	grid.push_back(a);
	grid.push_back(b);
	grid.push_back(c);
	if (grid.size() == 0)
		return;
	if (grid[0].size() == 0)
		return;
	int rows = grid.size();
	int cols = grid[0].size();

	if (grid.size() == 1 && grid[0].size() == 1)
		int result = grid[0][0];
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++)
		{
			if (i == 0 && j == 0)
				continue;
			else if (i == 0) {
				grid[0][j] += grid[0][j - 1];
			}
			else if (j == 0) {
				grid[i][0] += grid[i - 1][0];
			}
			else {
				grid[i][j] += min(grid[i - 1][j],grid[i][j - 1]);
			}
		}
	}
	int result = grid[rows - 1][cols - 1];
	cout << result;
}