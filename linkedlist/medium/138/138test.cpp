#include <stdio.h>
#include <iostream>
#define LEN sizeof(struct RandomListNode)
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};
void main() {
	RandomListNode *head, *l1, *l2;
	if (head == NULL)
		//return NULL;
		;
	for (l1 = head;l1 != NULL;l1 = l1->next->next) {
		l2 = (RandomListNode*)malloc(LEN);
		l2->label = l1->label;
		l2->next = l1->next;
		l1->next = l2;
	}
	for (l1 = head;l1 != NULL;l1 = l1->next->next) {
		if (l1->random != NULL) {
			l1->next->random = l1->random->next;
		}
	}
	for (l1 = head;l1 != NULL;l1 = l1->next) {
		l2 = l1->next;
		l1->next = l1->next->next;
		if (l2->next != NULL)
			l2->next = l2->next->next;
	}
}