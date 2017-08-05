#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> letterCombinations(string digits, map<char, string> Map, vector<string> &result, int current, string moment);
void main() {
	string digits = "23";
	map<char, string> hashmap;
	hashmap.insert(make_pair('2', "abc"));//非常注意！！！如果写成2而不是‘2’，map会认为这是int
	hashmap.insert(make_pair('3', "def"));
	hashmap.insert(make_pair('4',"ghi"));
	hashmap.insert(make_pair('5',"jkl"));
	hashmap.insert(make_pair('6', "mno"));
	hashmap.insert(make_pair('7', "pqrs"));
	hashmap.insert(make_pair('8', "tuv"));
	hashmap.insert(make_pair('9', "wxyz"));
	int len = hashmap[3].size();
	cout << "len" << len;
	int current = 0;//digits的内容循环计数器
	vector<string> result;
	string moment;
	result = letterCombinations(digits, hashmap, result, current, moment);
	for (auto iter = result.begin();iter != result.end();iter++) {
		//string s = iter;
		//printf("%s",&s);
		cout << "111111111111";
		cout << &iter;
	}

}
//下面函数由于是递归，每次递归参数虽然是传过去了，但是参数其实是一个数值的copy，新的递归函数会另占用一个新的空间来
//存放这个数值，所以每一个子递归函数执行完返回给主递归函数的时候，数值都是主递归函数之前的而不是子递归改变后的
//子递归改变后的参数存放在子递归的新的内存中，所以如果想要递归改变一个向量，那么应该传该向量的地址
//especially   vector<string> &result
vector<string> letterCombinations(string digits, map<char, string> Map, vector<string> &result, int current,string moment) {
	int length = digits.size();
	string temp;
	char digitpos = digits[current];
	cout << "digitpos" << digitpos;
	cout << digits[current];
	cout << Map[digitpos].size();
	for (int i = 0;i < Map[digits[current]].size();i++){
		moment += Map[digits[current]][i];
		//int len = Map[digits[digits[i]]].size();//2或3作为键，值的长度
		if (current < length - 1) {
			current++;
			letterCombinations(digits, Map, result, current, moment);
			current--;
			moment.pop_back();
		}
		else {
			result.push_back(moment);
			printf("%s",moment);
			moment.pop_back();
		}
		
	}
	//current--;
	return result;
}
