#include <iostream>
#include <algorithm>
#include <limits.h>
#include <iterator>
#include <ostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    int sum = 0;
    int mod = 0;
    ListNode *head = NULL;
    ListNode *p = l1;
    ListNode *q = l2;
    ListNode* n = NULL;
    ListNode* s = NULL;
    
    while(p != NULL && q != NULL){
        int a = p->val + q->val;
        sum = (a + mod) % 10;
        mod = ((a + mod) / 10);
        if(head == NULL){
            head = new ListNode(sum);
            s = head;
        }
        else{
            n = new ListNode(sum);
            s->next = n;
            s = n;
        }
        p = p->next;
        q = q->next;
    }
    
    while(p != NULL){
        int a = p->val;
        sum = (a + mod) % 10;
        mod = ((a + mod) / 10);
        if(head == NULL){
            head = new ListNode(sum);
            s = head;
        }
        else{
            n = new ListNode(sum);
            s->next = n;
            s = n;
        }
        p = p->next;
    }
    
    while(q != NULL){
        int a = q->val;
        sum = (a + mod) % 10;
        mod = ((a + mod) / 10);
        if(head == NULL){
            head = new ListNode(sum);
            s = head;
        }
        else{
            n = new ListNode(sum);
            s->next = n;
            s = n;
        }
        q = q->next;
    }
    
    if(mod != 0){
        n = new ListNode(mod);
        s->next = n;
        s = n;
    }
    
    return head;
}

void printList(ListNode *head){ 
	ListNode *p = head;
	while(p != NULL){ 
		cout<<p->val<<endl;
		p = p->next;
	}
}

int main(void){
	ListNode *l1 = new ListNode(9); 
	ListNode *l1_1 = new ListNode(1);
	ListNode *l1_2 = new ListNode(6);
	ListNode *l2 = new ListNode(0);

	l1->next = l1_1;
	l1_1->next = l1_2;

	ListNode *p = addTwoNumbers(l1, l2);
	printList(p);
	return 0;
}