#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 2

typedef struct  db_node rbnode;
struct db_node
{
	rbnode *p;
	rbnode *left;
	rbnode *right;
	int key;
	int color;
};

void rbtree_insert(rbnode **root, rbnode *z);
void rbtree_insert_fixed(rbnode **root, rbnode *z);
void left_roate(rbnode **root, rbnode *x);
void right_roate(rbnode **root, rbnode *x);
void rbtree_print(rbnode *root);

int main(int argc, char **argv)
{
	rbnode *root = NULL;
	rbnode *z = (rbnode*)malloc(sizeof(rbnode));
	z->key = 13;
	rbtree_insert(&root, z);
	rbnode *z1 = (rbnode*)malloc(sizeof(rbnode));
	z1->key = 8;
	rbnode *z2 = (rbnode*)malloc(sizeof(rbnode));
	z2->key = 17;
	rbnode *z3 = (rbnode*)malloc(sizeof(rbnode));
	z3->key = 15;
	rbtree_insert(&root, z1);
	rbtree_insert(&root, z2);
	rbtree_insert(&root, z3);
	rbtree_print(root);
	printf("\n");
	return 0;
}

void rbtree_print(rbnode *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d\t", root->key);
	rbtree_print(root->left);
	rbtree_print(root->right);
}

void rbtree_insert(rbnode **root, rbnode *z)
{
	rbnode *x = *root;
	rbnode *y = NULL;

	while(x != NULL)
	{
		y = x;
		if(z->key > x->key)
		{
			x = x->right;
		}
		else
		{
			x = x->left;
		}
	}
	
	z->p = y;
	if(y == NULL)
	{
		*root = z;
	}
	else if(z->key > y->key)
	{
		y->right = z;
	}
	else
	{
		y->left = z;
	}

	z->left = NULL;
	z->right = NULL;
	z->color = RED;
	
	/*
	if(z->p == NULL || z->p->p == NULL)
	{
		return;
	}
	*/
	rbtree_insert_fixed(root, z);
}

void left_roate(rbnode **root, rbnode *x)
{
	rbnode *y = x->right;
	x->right = y->left;
	if(y->left != NULL)
	{
		y->left->p = x;
	}
	y->p = x->p;
	if(x->p == NULL)
	{
		*root = y;
	}
	else if(x == x->p->left)
	{
		x->p->left = y;
	}
	else
	{
		x->p->right = y;
	}
	y->left = x;
	x->p = y;
}

void right_roate(rbnode **root, rbnode *x)
{
	rbnode *y = x->left;
	x->left = y->right;
	if(y->right != NULL)
	{
		y->right->p = x;
	}
	y->p = x->p;
	if(x->p = NULL)
	{
		*root = y;
	}
	else if(x == x->p->left)
	{
		x->p->left = y;
	}
	else
	{
		x->p->right = y;
	}
	y->right = x;
	x->p = y;
}

void rbtree_insert_fixed(rbnode **root, rbnode *z)
{
	rbnode *y = NULL;
	if(z->p != NULL && z->p->p != NULL)
	while(z->p->color == RED)
	{
		if(z->p == z->p->p->left)
		{
			y = z->p->p->right;
			if(y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
				if(z->p == NULL)
					break;
				if(z->p->p == NULL)
					break;
			}
			else if(z == z->p->right)
			{
				z = z->p;
				left_roate(root, z);
			}
			z->p->color= BLACK;
			z->p->p->color = RED;
			right_roate(root, z->p->p);
		}
		else
		{
			y = z->p->p->left;
			if(y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
				if(z->p == NULL)
					break;
				if(z->p->p == NULL)
					break;
			}
			else if(z == z->p->right)
			{
				z = z->p;
				left_roate(root, z);
			}
			z->p->color= BLACK;
			z->p->p->color = RED;
			right_roate(root, z->p->p);
		}
		if(z->p == NULL)
			break;
		if(z->p->p == NULL)
			break;
	}

	(*root)->color = BLACK;
}
