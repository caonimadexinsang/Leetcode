#include <stdio.h>
#include <iostream>
#define LEN (sizeof(struct ListNode))
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
ListNode *Creat();
void PrintList(ListNode *head);
void main() {
	int n = 2;
	ListNode *head, *font,*dummy;
	dummy = (ListNode*)malloc(LEN);
	head = Creat();
	if (head->next == NULL)
		;
	//	return NULL;
	font = head;
	int length = 0;
	int count = 0;
	while (head != NULL) {
		length++;
		head = head->next;
	}
	cout << "length" << length;
	head = font;
	dummy->next = font;
	font = dummy;
	while (count != length - n) {
		count++;
		font = font->next;
	}
	cout << "dummy" << dummy->val;
	cout << "dummy" << dummy->next->val;
	font->next = font->next->next;
	PrintList(dummy->next);
	
}
ListNode *Creat() {
	ListNode *head, *p1,*p2;
	p1 = (ListNode*)malloc(LEN);
	cin >> p1->val;
	int count = 0;
	head = NULL;
	while (p1->val != 0) {
		count++;
		if (count == 1) {
			head = p1;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = (ListNode*)malloc(LEN);
		cin >> p1->val;
	}
	p2->next = NULL;
	return head;
}
void PrintList(ListNode *head) {
	while (head != NULL) {
		cout << head->val;
		head = head->next;
	}
}