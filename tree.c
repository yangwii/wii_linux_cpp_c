#include <stdio.h>
#include <stdlib.h>

struct node *createTree();
void printNode_First(struct node *t);
void freeNodes(struct node *t);
struct node{
	struct node *left;
	struct node *right;
	int value;
};

int main(int argc, char *argv[])
{
	struct node *root = NULL;
	root = createTree();
	printNode_First(root);
	freeNodes(root);
	return 1;
}


struct node *createTree(){
	struct node *t = (struct node *)malloc(sizeof(struct node));
	int i = 0;
	scanf("%d", &i);
	if(i == 0){
		free(t);
		return NULL;
	}
	t->value = i;
	t->left = createTree();
	t->right = createTree();

	return t;
}
void printNode_First(struct node *t){
	if(t == NULL){
		return;
	}
	printf("%d\n", t->value);
	printNode_First(t->left);
	printNode_First(t->right);
}
void freeNodes(struct node *t){
	if(t != NULL){
		freeNodes(t->left);
		freeNodes(t->right);
		free(t);
	}
}
