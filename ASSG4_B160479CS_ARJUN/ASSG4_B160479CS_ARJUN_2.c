#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	long int key;
	struct node *left, *right, *parent;
};

struct node *BST = NULL;

struct node* makeNode(long int key)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	return newNode;
}


struct node* insert(struct node *r, long int key)
{
	struct node *p = makeNode(key);
	if(r == NULL)
		return p;
	else
	{
		struct node *q = r;
		while(q != NULL)
		{
			if(q->key > key)
			{
				if(q->left == NULL)
				{
					p->parent = q;
					q->left = p;
					break;
				}
				q = q->left;
			}
			else
			{
				if(q->right == NULL)
				{
					p->parent = q;
					q->right = p;
					break;
				}
				q = q->right;
			}
		}
		return r;
	}
}


void search(struct node *root, long int key)
{
	if(root == NULL)
		printf("NOT FOUND\n");
	else if(root->key == key)
		printf("FOUND\n");
	else if(root->key < key)
		search(root->right, key);
	else
		search(root->left, key);
}

struct node* findMin(struct node *r)
{
	if(r == NULL)
		return NULL;
	else
	{
		while(r->left != NULL)
			r = r->left;
		return r;
	}	
}

struct node* findMax(struct node *r)
{
	if(r == NULL)
		return NULL;
	else
	{
		while(r->right != NULL)
			r = r->right;
		return r;
	}
}

struct node* findNode(struct node *r, long int key)
{
	if(r == NULL)
		return NULL;
	else if(r->key == key)
		return r;
	else
	{
		if(r->key > key)
			return findNode(r->left, key);
		else 
			return findNode(r->right, key);
	}
}

void predecessor(struct node *r, struct node *p)
{
	if(p == NULL)
		printf("NOT FOUND\n");
	else
	{
		if(p->left != NULL)
		{
			struct node *q = findMax(p->left);
			printf("%ld\n", q->key);
		}
		else
		{
			struct node *q = p->parent;
			while(q != NULL && q->left == p)
			{
				p = q;
				q = p->parent;
			}
			if(q == NULL)
				printf("NIL\n");
			else
				printf("%ld\n", q->key);
		}
	}
	
}

void successor(struct node *r, struct node *p)
{
	if(p == NULL)
		printf("NOT FOUND\n");
	else
	{
		if(p->right != NULL)
		{
			struct node *q = findMin(p->right);
			printf("%ld\n", q->key);
		}
		else
		{
			struct node *q = p->parent;
			while(q != NULL && q->right == p)
			{
				p = q;
				q = p->parent;
			}
			if(q == NULL)
				printf("NIL\n");
			else
				printf("%ld\n", q->key);
		}
	}
	
}

struct node* deleteElement(struct node *r, struct node *p)
{
	if(r == p)
	{
		if(r->right == NULL)
		{
			struct node *q = r->left;
			r->left = NULL;
			free(r);
			return q;
		}
		else if(r->left == NULL)
		{
			struct node *q = r->right;
			r->right = NULL;
			free(r);
			return q;
		}
		else
		{
			struct node *q = r->right;
			if(q->left == NULL)
			{
				struct node *x = r->left;
				r->left = NULL;
				free(r);
				q->left = x;
				return q;
			}
			else
			{
				struct node *x = q->left;
				while(x->left != NULL)
				{
					q=x;
					x=x->left;
				}
				x->left = r->left;
				r->left = NULL;
				q->left = x->right;
				x->right = r->right;
				r->right = NULL;
				free(r);
				return x;
				
			}
		}
	}
	else
	{
		if(r->key < p->key)
			r->right = deleteElement(r->right, p);
		else
			r->left = deleteElement(r->left, p);
		return r;
	}
}

void inorder(struct node *p)
{
	if(p != NULL)
	{
		inorder(p->left);
		printf("%ld ", p->key);
		inorder(p->right);
	}
}

void preorder(struct node *p)
{
	if(p != NULL)
	{
		printf("%ld ", p->key);
		preorder(p->left);
		preorder(p->right);
	}
}

void postorder(struct node *p)
{
	if(p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%ld ", p->key);
	}
}



int main()
{
	char command[4];
	long int key;
	
	while(1)
	{
		scanf("%s", command);
		if(strcmp(command, "stop") == 0)
			break;
		else if(strcmp(command, "insr") == 0)
		{
			scanf("%ld", &key);
			BST = insert(BST, key);
		}
		else if(strcmp(command, "srch") == 0)
		{
			scanf("%ld", &key);
			search(BST, key);
		}
		else if(strcmp(command, "minm") == 0)
		{
			struct node *p = findMin(BST);
			if(p == NULL)
				printf("NIL\n");
			else
				printf("%ld\n", p->key);
		}
		else if(strcmp(command, "maxm") == 0)
		{
			struct node *p = findMax(BST);
			if(p == NULL)
				printf("NIL\n");
			else
				printf("%ld\n", p->key);
		}
		else if(strcmp(command, "pred") == 0)
		{
			scanf("%ld", &key);
			struct node *p = findNode(BST, key);
			predecessor(BST, p);
		}
		else if(strcmp(command, "succ") == 0)
		{
			scanf("%ld", &key);
			struct node *p = findNode(BST, key);
			successor(BST, p);
		}
		else if(strcmp(command, "delt") == 0)
		{
			scanf("%ld", &key);
			struct node *p = findNode(BST, key);
			BST = deleteElement(BST, p);
		}
		else if(strcmp(command, "inor") == 0)
		{
			inorder(BST);
			printf("\n");
		}
		else if(strcmp(command, "prer") == 0)
		{
			preorder(BST);
			printf("\n");
		}
		else if(strcmp(command, "post") == 0)
		{
			postorder(BST);
			printf("\n");
		}
		else
			;		
	}

	return 0;
}