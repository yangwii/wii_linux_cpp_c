#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

struct ListNode
{
	int m_nKey;
	struct ListNode *next;
};

struct ListNode *createList()
{
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->next = NULL;
	return node;
}

struct ListNode *insert(int data, struct ListNode* head)
{
	struct ListNode *p = head->next;
	struct ListNode *t = NULL;
	t = malloc(sizeof(struct ListNode));
	check_mem(t);
	t->m_nKey = data;
	if(NULL == p)
	{
		t->next = p;
		head->next = t;
	}
	else
	{
		t->next = p;
		head->next = t;
	}
	return head;
error:
	free(t);
	return head;
}

void print(struct ListNode *head)
{
	struct ListNode *p = head->next;
	while(p != NULL)
	{
		printf("%d\n", p->m_nKey);
		p = p->next;
	}
}

struct ListNode *reverseList(struct ListNode* head)
{
	struct ListNode *pre, *q, *p = NULL;
	pre = head->next;
	q = pre;
	if(pre->next != NULL) q = pre->next;
	p = q;
	pre->next = NULL;
	while(p != NULL)
	{
		p = q->next;
		q->next = pre;
		pre = q;
		q = p;
	}
	//q->next = pre;
	head->next = pre;
	return head;
}
	
int main(int argc, char *argv[])
{
	struct ListNode *head = createList();
	head = insert(1, head);
	head = insert(2, head);
	head = insert(3, head);
	head = insert(4, head);
	head = insert(5, head);
	head = insert(6, head);
	print(head);
	head = reverseList(head);
	print(head);
	return 0;
}
