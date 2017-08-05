#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(struct ListNode)
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *Creat();
void PrintList(ListNode *head);
int main()
{
	ListNode *left = (ListNode*)malloc(LEN);
	ListNode *right = (ListNode*)malloc(LEN);
	ListNode *head;// = (ListNode*)malloc(LEN);

	left->next = right->next = NULL;


	ListNode *font;
	ListNode *rightfirst, *leftfirst;
	int x = 3;
	head = Creat();

#if 0 //debug info
	PrintList(head);
#endif
	rightfirst = right;
	leftfirst = left;
	while (head != NULL)
	{
		if (head->val < x)
		{
			left->next = head;
			left = head;
			//left = (ListNode*)malloc(LEN);
		}
		else
		{
			right->next = head;
			right = head;
			//	right = (ListNode*)malloc(LEN);
			//count++;
		}
		head = head->next;
	}
	{
		left->next = NULL;
		right->next = NULL;
	}
#if 1 //debug info
	{
		printf("right!\n");
		PrintList(rightfirst->next);
		printf("left!\n");
		PrintList(leftfirst->next);
		printf("end!\n");
	}
#endif

	rightfirst = rightfirst->next;
	right->next = NULL;
	left->next = rightfirst;
	leftfirst = leftfirst->next;
	if (leftfirst)
		cout << "leftfirst " << leftfirst->val << endl;
	if (rightfirst)
		cout << "rightfirst " << rightfirst->val << endl;
#if 0 //debug info
	cout << "display all list" << endl;
	PrintList(leftfirst);
#endif
	return 0;
}
ListNode *Creat()
{
	/*	ListNode *head = NULL;
		ListNode *p1 = (ListNode*)malloc(LEN);
		ListNode *p2 = p1;//这句话不对
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
		p2->next == NULL;
		return head;
		*/
	ListNode *head, *p1, *p2 = NULL;
	p1 = (ListNode*)malloc(LEN);
	p1->next = NULL;
	cin >> p1->val;
	int count = 0;
	head = NULL;
	while (p1->val != 0)
	{

		count++;
		if (count == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (ListNode*)malloc(LEN);
		p1->next = NULL;
		cin >> p1->val;
	}
	if (p2)
		p2->next = NULL;
	return head;
}
void PrintList(ListNode *head)
{
	while (head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
}
