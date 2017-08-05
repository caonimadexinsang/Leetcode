#include <stdio.h>
#include <iostream>
using namespace std;
#define LEN sizeof(ListNode)
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
void PrintList(ListNode *head);
ListNode *Creat();
void main() {
	ListNode* head;
	//
	int k = 1;
	head = Creat();
	if (head == NULL || k <= 0)
		return;
	//PrintList(head);
	ListNode* phead = head;
	ListNode* pre = head;
	int length = 1;
	while (head && head->next) {
		length++;
		head = head->next;
	}
	cout << length;
	head->next = pre;
	k = k % length;
	for (int i = 0;i < length - k - 1;i++) {
		pre = pre->next;
	}
	head = pre->next;
	pre->next = NULL;
	
	PrintList(head);
	while (head && head->next) {
		free(head);
		head = head->next;
	}
}
ListNode *Creat() {
	ListNode *head;
	ListNode *p1, *p2;
	head = NULL;
	p1 = (ListNode*)malloc(LEN);
	scanf("%d",&p1->val);
	int n = 0;
	while (p1->val != 0) {
		n++;
		if (n == 1) {
			head = p1;
			p2 = p1;
		}
		else {
			p2->next = p1;
			p2 = p1;
		}
		p1 = (ListNode*)malloc(LEN);
		scanf("%d",&p1->val);
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