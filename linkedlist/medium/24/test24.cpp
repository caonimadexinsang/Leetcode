
#include <stdio.h>
#include <iostream>
#define LEN sizeof(ListNode)
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}//构造函数
};
ListNode *Creat();
void PrintList(ListNode *head);
void main() {
	ListNode *head;
	//ListNode result(-1);//用构造函数初始化出来的
	//result
	head = Creat();
	PrintList(head);
	ListNode *phead;
	phead = head;
	//p1 = head;
	//p2 = p1->next;
	int temp;
	while (head->next != NULL && head != NULL) {
		temp = head->val;
		head->val = head->next->val;
		head->next->val = temp;
		head = head->next->next;
	}
	PrintList(phead);
}
ListNode *Creat() {
	ListNode *head;
	ListNode *p1,*p2;
	int n = 0;
	head = NULL;
	p1 = p2 = (ListNode*)malloc(LEN);
	scanf("%d",&p1->val);
	while (p1->val != 0) {
		n++;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (ListNode*)malloc(LEN);
		scanf("%d",&p1->val);
	}
	return head;
}
void PrintList(ListNode *head) {
	while (head != NULL) {
		cout << head->val;
		head = head->next;
	}
}

