#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
ListNode *Create(ListNode *head);
void PrintList(ListNode *list);
void main() {
	ListNode *l1 = NULL;
	ListNode *l2 = NULL;
	l1 = Create(l1);
	cout << "second linklist:"<<endl;
	l2 = Create(l2);
	cout << endl;
	cout << "Print:" << endl;
//	PrintList(l1);
	//PrintList(l2);
	ListNode *result = new ListNode(-1);
	ListNode *resulthead = result;
	int count = 0;
	int number = 0;
	//vector<int> nums;
	int sumnew = 0;
	ListNode *p = result;
	while (l1 != NULL || l2 != NULL || count != 0) {
		number++;
		if (l1 != NULL) {
			sumnew += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			sumnew += l2->val;
			l2 = l2->next;
		}
		int sum = sumnew + count;
		sumnew = sum % 10;
	//	sumnew = sumnew%10 + count;
		if (sum / 10 == 1)
			count = 1;
		else
			count = 0;
		//nums.push_back(sumnew);
		if (number == 1) {
			result->val = sumnew;
			sumnew = 0;
			continue;
		}
		result = new ListNode(-1);
		result->val = sumnew;
		p->next = result;
		p = result;
		sumnew = 0;
	}
	PrintList(resulthead);
//	int length = nums.size();
	//cout << "length:" << length;
	//ListNode *p;
	/*for (vector<int>::iterator it = nums.end();it != nums.begin();it--) {
		result->val = *it;
		if (it == nums.end()) {
			p = result;
			result = new ListNode(-1);
			p->next = result;
			continue;
		}
		p = result;
		result = new ListNode(-1);
		p->next = result;
	}
	if (result->val == -1)
		result = NULL;
	cout <<"resulthead:" << endl;
	//PrintList(&resulthead);*/
}
ListNode *Create(ListNode *head) {
	int temp;
	cin >> temp;
	ListNode *p;
	int count = 0;
	while (temp != 0) {
		count++;
		ListNode *current = new ListNode(temp);
		if (count == 1) {
			p = current;
			head = current;
			cin >> temp;
			continue;
		}
		p->next = current;
		p = current;
		cin >> temp;
	}
	return head;
}
void PrintList(ListNode *list) {
	while (list != NULL) {
		cout << list->val;
		list = list->next;
	}
	cout << endl;
}