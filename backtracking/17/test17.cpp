#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> letterCombinations(string digits, map<char, string> Map, vector<string> &result, int current, string moment);
void main() {
	string digits = "23";
	map<char, string> hashmap;
	hashmap.insert(make_pair('2', "abc"));//�ǳ�ע�⣡�������д��2�����ǡ�2����map����Ϊ����int
	hashmap.insert(make_pair('3', "def"));
	hashmap.insert(make_pair('4',"ghi"));
	hashmap.insert(make_pair('5',"jkl"));
	hashmap.insert(make_pair('6', "mno"));
	hashmap.insert(make_pair('7', "pqrs"));
	hashmap.insert(make_pair('8', "tuv"));
	hashmap.insert(make_pair('9', "wxyz"));
	int len = hashmap[3].size();
	cout << "len" << len;
	int current = 0;//digits������ѭ��������
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
//���溯�������ǵݹ飬ÿ�εݹ������Ȼ�Ǵ���ȥ�ˣ����ǲ�����ʵ��һ����ֵ��copy���µĵݹ麯������ռ��һ���µĿռ���
//��������ֵ������ÿһ���ӵݹ麯��ִ���귵�ظ����ݹ麯����ʱ����ֵ�������ݹ麯��֮ǰ�Ķ������ӵݹ�ı���
//�ӵݹ�ı��Ĳ���������ӵݹ���µ��ڴ��У����������Ҫ�ݹ�ı�һ����������ôӦ�ô��������ĵ�ַ
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
		//int len = Map[digits[digits[i]]].size();//2��3��Ϊ����ֵ�ĳ���
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
