#include <stdio.h>
#include <iostream>
#define LEN sizeof(struct ListNode)
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
ListNode *Creat();
void PrintList(ListNode *head);
void main() {
	ListNode *left = (ListNode*)malloc(LEN);
	ListNode *right = (ListNode*)malloc(LEN);
	ListNode *head;
	ListNode *font;
	ListNode *rightfirst, *leftfirst;
	int x = 3;
	head = Creat();
	font = head;
	PrintList(head);
//	head = font;
	//int count = 0;
	rightfirst = right;
	leftfirst = left;
	while (head != NULL) {
	 	if (head->val < x) {
			left->next = head;
			left = head;
			//left = (ListNode*)malloc(LEN);
		}
		else {
			right->next = head;
			right = head;
		//	right = (ListNode*)malloc(LEN);
			//count++;
		}
		head = head->next;
	}
	//font = font->next;
	rightfirst = rightfirst->next;
	right->next = NULL;
	left->next = rightfirst;
	leftfirst = leftfirst->next;
	cout << "leftfirst" << leftfirst->next->val;
	cout << "rightfirst" << rightfirst->val;
	cout << "..............";
	PrintList(leftfirst);
}
ListNode *Creat() {
	ListNode *head = NULL;
	ListNode *p1 = (ListNode*)malloc(LEN);
	ListNode *p2 = p1;
	cin >> p1->val;
	int count = 0;
	while (p1->val != 0) {
		count++;
		if (count == 1) {
			head = p1;
		}
		else
			p2->next = p1;
		p2 = p1;
		p1 = (ListNode*)malloc(LEN);//一定要为下一个p1申请内存
		cin >> p1->val;
	}
	if(p2)
	p2->next = NULL;//是之前把这儿写成==了
	return head;
	/*
	ListNode *head, *p1, *p2;
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
	return head;*/
}
void PrintList(ListNode *head) {
	while (head != NULL) {
		cout << head->val;
		head = head->next;
	}
}