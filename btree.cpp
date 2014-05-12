#include <iostream>

using namespace std;

typedef struct node{
	struct node* left;
	struct node* right;
	int value;
}TNode;

class BinaryTree{
public:
	TNode *root;
	BinaryTree():root(NULL){}
	void create()
	{
		root = createTree();
	}
	void printNodes()
	{
		display(root);
	}
private:
	TNode* createTree();	
	void display(TNode *t);
}; 

void BinaryTree::display(TNode *t )
{
	if(t != NULL)
	{
		cout<<t->value<<endl;
		display(t->left);
		display(t->right);
	}	
}

TNode* BinaryTree::createTree()
{
	int i;	
	cin>>i;
	if(i == 0)
	{
		return NULL;
	}
	TNode *t = new TNode;
	t->value = i;
	t->left = createTree();
	t->right = createTree();
	
	return t;
}
int main(int argc, char *argv[])
{
	BinaryTree tree;
	tree.create();
	tree.printNodes();
	return 1;
}
