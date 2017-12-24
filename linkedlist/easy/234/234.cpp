#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {};
};
ListNode *ReverseList(ListNode *head);
ListNode *Create();
void PrintList(ListNode *head);
void main() {
	ListNode *head;
	ListNode *phead = (ListNode*)malloc(sizeof(struct ListNode));
	head = Create();
	phead->next = head;
   // PrintList(head);
	ListNode *slow, *fast;
	ListNode *medium;
	slow = fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	//��������
	if (fast != NULL) {
		medium = ReverseList(slow->next);
	}
	//ż������
	else {
		medium = ReverseList(slow);
	}
	bool result;
	PrintList(medium);
	while (medium) {
		if (medium->val != head->val)
			result = false;
		medium = medium->next;
		head = head->next;
	}
	result = true;
	cout << endl;
	cout << result;

//	head = ReverseList(head);
	//PrintList(head);
}
ListNode *ReverseList(ListNode *head) {
	ListNode *before = head->next;
	ListNode *after = head;
	int count = 0;
	while (before != NULL) {
		count++;	
		head = before;
			before = before->next;
		head->next = after;
		if (count == 1)//��ͷ�ڵ��next�ÿ�
			after->next = NULL;
		after = head;
	}
	return head;
}
//right create and print,important!!!!!!!!!!!!!!
//���create������p2,��Ϊp2���ܰ���������������ֻ��p1�Ļ�p1ÿ��p1=p1->next,����p1֮�����������һ���ڴ�ռ䣬�����µ��ڴ�λ�ã���֮ǰ�Ĳ�û����������
ListNode *Create() {
	ListNode *head;
	ListNode *p1,*p2;
	head = NULL;
	int val;
	int count = 0;
	p1 = (ListNode*)malloc(sizeof(struct ListNode));
	scanf("%d",&val);
	p1->val = val;
	while (p1->val != 0) {
		count++;
		if (count == 1) {
			head = p1;
			p2 = p1;
		}
		else {
			p2->next = p1;
			p2 = p1;
		}
		p1 = (ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d",&p1->val);
	}
	p2->next = NULL;
	return head;
}
void PrintList(ListNode *head) {
	ListNode *p;
	p = head;
	while (p) {
		cout << p->val;
		p = p->next;
	}
}