#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linknode
{
	int key;
	struct linknode *next;
};

typedef linknode node;

void printlinkedlist(node *head);
void insert(node *head, int val);
void walklist(node *head);
node* reverselist(node *head);

int main(int argc, char *argv[])
{
	node *head = (node *)malloc(sizeof(node));
	head->next = NULL;
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 3);
	insert(head, 2);
	insert(head, 1);
	printlinkedlist(head);

	walklist(head);
	return 0;
}

node *reverselist(node* head)
{
	node *pre, *q, *p = NULL;
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

	head->next = pre;
	return head;
}

void walklist(node *head)
{
	node *slow = head->next;//使用快慢指针
	node *fast = head->next;
	node *preslow = slow;//slow用于处理节点个数奇偶数的问题

	if(fast->next == NULL)
	{
		return;
	}
	//fast = fast->next->next;
	while(fast->next != NULL)
	{
		fast = fast->next->next;
		preslow = slow;
		if(fast == NULL)
		{
			break;
		}
		slow = slow->next;
	}

	//if(fast != NULL)
	//{
		//printf("%d\n", slow->key);
		//printf("%d\n", slow->next->key);
	//}
	//else
	//{
		printf("%d\n", preslow->key);
		printf("%d\n", preslow->next->key);
	//}
	
	//node *tail = preslow;
	node *mid = NULL;
	if(fast != NULL)
	{
		mid = reverselist(slow);//奇数个节点，slow相当于头节点
	}
	else
	{
		mid = reverselist(preslow);//偶数个节点
	}
	printlinkedlist(mid);

	node *p = head->next;
	mid = mid->next;
	while(mid != NULL)
	{
		printf("%d-%d\n", p->key, mid->key);
		if(p->key != mid->key)
		{
			printf("NO\n");
			return;
		}
		p = p->next;
		mid = mid->next;
	}
	printf("YES\n");
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

