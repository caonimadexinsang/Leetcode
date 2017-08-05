#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
bool main() {
	char board[9][9] = {};
/*	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			board[i][j] = 0;
			//cout << board[i][j];
		}
	}*/
	board[0][0] = 5;
	board[0][1] = 3;
	board[0][4] = 7;
	board[1][0] = 6;
	board[1][3] = 1;
	board[1][4] = 9;
	board[1][5] = 5;
	for (int i = 0;i < 9;i++) {
		unordered_map<char, bool> rowmap;
		unordered_map<char, bool> colmap;
		for (int j = 0;j < 9;j++) {
			if (board[i][j] != '\0') {
				if (rowmap[board[i][j]] != true)
					rowmap[board[i][j]] = true;
				else
					return false;
			}
			if (board[j][i] != '\0') {
				if (colmap[board[j][i]] != true)
					colmap[board[j][i]] = true;
				else
					return false;
			}
		}
	}
	for (int i = 0;i < 9;i += 3) {
		for (int j = 0;j < 9;j += 3) {
			unordered_map<char, bool> gridmap;
			for (int row = i;row < i + 3;row++) {
				for (int col = j;col < j + 3;col++) {
					if (board[row][col] != '\0') {
						if (gridmap[board[row][col]] != true)
							gridmap[board[row][col]] = true;
						else
							return false;
					}
				}
			}
		}
	}
	cout << "true";
	return true; 
}
