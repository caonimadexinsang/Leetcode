#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void main() {
	vector<vector<int>> matrix;
	vector<int> mat = { 1,3,5,7 };
	vector<int> mat1 = {10,11,16,20};
	vector<int> mat2 = {23,30,34,50};
	int target = 9;
	bool result;
	matrix.push_back(mat);
	matrix.push_back(mat1);
	matrix.push_back(mat2);
	//������һ���ڰ�matrix.size()��matrix[0].size()��ֵ����֮ǰ���зǳ���Ҫ����Ϊ������������ڣ�����û�о�����������֤�͸�ֵ�Ļ����ͻ�����ָ������
	/*
	if (matrix.size() == 0)
		return false;
	if (matrix[0].size() == 0)
		return false;*/

	int r = matrix.size();//��
	int c = matrix[0].size();//��
	int low = 0;int high = r - 1;
	int mid = (r - 1) / 2;
	while (low <= high) {
		mid = (low + high) / 2;
		if (target == matrix[mid][0]) {
			result = true;
			cout << result;
			return;
		}
		else if (target > matrix[mid][0]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	low = low - 1;
	int lowin = 0;
	high = c - 1;
	int midnew;
	while (lowin <= high) {
		midnew = (lowin + high) / 2;
		if (target == matrix[low][midnew]) {
			result = true;
			cout << result;
			return;
		}
		else if (target < matrix[low][midnew]) {
			high = midnew - 1;
		}
		else
			lowin = midnew + 1;
	}
	result = false;
	cout << result;
}