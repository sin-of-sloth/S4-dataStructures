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


struct node* mirrorTree(struct node *t)
{
	if(t == NULL)
		return NULL;
	else
	{
		struct node *q = mirrorTree(t->right);
		t->right = mirrorTree(t->left);
		t->left = q;
		return t;
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


int main()
{
	char c, tree[1000];
	int i;
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
		else if(c == 'm')
			t = mirrorTree(t);
		else if(c == 's')
			break;
		else
			continue;
	}
	
	return 0;
}