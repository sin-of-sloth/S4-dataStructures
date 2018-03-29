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
	newNode->data = data - 48;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


struct node* createTree(char *tree, int *i)
{
	if(tree[*i] == '(')
	{
		(*i)++;
		if(tree[*i] == ')')
		{
			(*i)++;
			return NULL;
		}
		else
		{
			struct node *t = createNewNode(tree[*i]);
			(*i)++;
			if(tree[*i] == ')')
			{
				(*i)++;
				return t;
			}
			else
			{
				t->left = createTree(tree, i);
				t->right = createTree(tree, i);
				return t;
			}	
		}
	}
	else
	{
		(*i)++;
		return createTree(tree, i);
	}
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


struct node *leftRotate(struct node *t, long int data)
{
	if(t->data == data)
	{
		struct node *p = t->right;
		if(p != NULL)
		{
			struct node *q = p->left;
			p->left = t;
			t->right = q;
			return p;
		}
		else
		{
			printf("NOT POSSIBLE\n");
			return t;
		} 
	}
	else
	{
		if(t->data > data)
			t->left = leftRotate(t->left, data);
		else
			t->right = leftRotate(t->right, data);
		return t;
	}
}


struct node *rightRotate(struct node *t, long int data)
{
	if(t->data == data)
	{
		struct node *p = t->left;
		if(p != NULL)
		{
			struct node *q = p->right;
			p->right = t;
			t->left = q;
			return p;
		}
		else
		{
			printf("NOT POSSIBLE\n");
			return t;
		}
	}
	else
	{
		if(t->data > data)
			t->left = rightRotate(t->left, data);
		else
			t->right = rightRotate(t->right, data);
		return t;
	}
}


int main()
{
	char c, tree[1000];
	int i;
	long int data;
	struct node *t = NULL;
	while(1)
	{
		c = getchar();
		if(c == 'c')
		{
			i = 0;
			while(1)
			{
				c = getchar();
				if(c == 10)
					break;
				else
				{
					if(c != ' ')
						tree[i++] = c;
				}
			}
			i = 0;
			t = createTree(tree, &i);
		}
		else if(c == 'p')
		{
			printTree(t);
			printf("\n");
		}
		else if(c == 'l')
		{
			scanf("%ld", &data);
			t = leftRotate(t, data);
		}
		else if(c == 'r')
		{
			scanf("%ld", &data);
			t = rightRotate(t, data);
		}
		else if(c == 's')
			break;
		else
			continue;
	}
	
	return 0;
}