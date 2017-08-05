#include <stdio.h>
#include <iostream>
using namespace std;
#define LEN sizeof(struct ListNode)
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
ListNode *Creat();
void printlist(ListNode *head);
void main() {
	ListNode *head;
	head = Creat();
	ListNode *curr, *nexttemp, *pre;
	curr = head;
	pre = NULL;
	while (curr) {
		nexttemp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = nexttemp;
		//nexttemp = nexttemp->next;
	}
	printlist(pre);
}
ListNode *Creat() {
	int n = 0;
	ListNode *head, *p1, *p2;
	head = NULL;
	p1 = p2 = (ListNode*)malloc(LEN);
	scanf("%d", &p1->val);
	while (p1->val != 0) {
		n++;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (ListNode*)malloc(LEN);
		scanf("%d", &p1->val);
	}
	p2->next = NULL;
	return head;
}
void printlist(ListNode *head) {
	//	ListNode *p;
	//p = head;
	while (head != NULL) {
		cout << head->val;
		head = head->next;
	}
}