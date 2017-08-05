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
	ListNode* l1;
	ListNode* l2;
	ListNode* temp;
	ListNode result(-1);
	temp = &result;
	//...............................
	l1 = Creat();
	printlist(l1);
	l2 = Creat();
	printlist(l2);
	//...............................
	while (l1 && l2) {
		if (l1->val <= l2->val) {
			temp->next = l1;
			l1 = l1->next;
		}
		else if (l1->val > l2->val) {
			temp->next = l2;
			l2 = l2->next;
		}
		temp = temp->next;
	}
	if (l1)
		temp->next = l1;
	if (l2)
		temp->next = l2;
	//..............................
	printlist(&result);
	//return result.next;
}
ListNode *Creat() {
	int n = 0;
	ListNode *head,*p1,*p2;
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