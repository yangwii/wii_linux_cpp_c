#include <stdio.h>
#include <stdlib.h>

struct link_node
{
	int key;
	struct link_node *next;
};
typedef link_node node;

void printlinkedlist(node *head);
void insert(node *head, int val);
void reverselinkedlist(node *head, int k);

int main(int argc, char *argv[])
{
	node *head = (node *)malloc(sizeof(node));
	head->next = NULL;
	for(int i = 6; i >= 1; i--)
	{
		insert(head, i);
	}
	printlinkedlist(head);
	
	reverselinkedlist(head, 2);
	printlinkedlist(head);

	reverselinkedlist(head, 3);
	printlinkedlist(head);

	reverselinkedlist(head, 4);
	printlinkedlist(head);
	return 0;
}

void insert(node *head, int val)
{
	node *p = head;
	node *n = (node *)malloc(sizeof(node));
	if(n == NULL)
	{
		printf("malloc node failed\n");
	}
	n->key = val;
	n->next = p->next;
	head->next = n;
}

void printlinkedlist(node *head)
{
	node *p = head->next;
	while(p != NULL)
	{
		printf("%d\t", p->key);
		p = p->next;
	}
	printf("\n");
}

void reverselinkedlist(node *head, int k)
{
	node *p = head;
	node *q = head->next;
	node *pre = q;
	for(int i = 0; i < k - 1 && q != NULL; i++)
	{
		pre = q;
		q = q->next;
	}

	pre->next = q->next;
	q->next = head->next;
	head->next = q;

}
