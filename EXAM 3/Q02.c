#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};


struct node* createNewNode(int data)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


void printTree(struct node *t)
{
	if(t == NULL)
		printf("( )");
	else
	{
		printf("( %d", t->data);
		if(t->left != NULL || t->right != NULL)
		{
			printf(" ");
			printTree(t->left);
			printf(" ");
			printTree(t->right);
		}
		printf(" )");
	}
}


struct node* specialTree(int n)
{
	if(n < 1)
		return NULL;
	else
	{
		struct node *t = createNewNode(n);
		if(n != 1)
		{
			t->left = specialTree(n / 2);
			t->right = specialTree( ( n - 1 ) / 2);
		}
		return t;
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	struct node *t = specialTree(n);
	printTree(t);
	return 0;
}