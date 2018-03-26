#include<stdio.h>
#include<stdlib.h>

struct node
{
	long int data;
	struct node *left, *right;
};

struct node* createNewNode(long int data)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct node* createBT(long int *preOrder, long int preStart, long int preEnd, long int *inOrder, long int inStart, long int inEnd)
{
	if(!((preStart > preEnd) || (inStart > inEnd)))
	{
		struct node *root = createNewNode(preOrder[preStart]);
		long int divIndex, i;
		for(i = inStart; i <= inEnd; i++)
		{
			if(inOrder[i] == preOrder[preStart])
			{
				divIndex = i;
				break;
			}
		}
		long int leftSubTreeSize = divIndex - inStart;
		long int rightSubTreeSize = inEnd - divIndex;
		root->left = createBT(preOrder, preStart + 1, preStart + leftSubTreeSize, inOrder, inStart, divIndex - 1);
		root->right = createBT(preOrder, preStart + leftSubTreeSize + 1, preStart + leftSubTreeSize + rightSubTreeSize, inOrder, divIndex + 1, inEnd);
		return root;
	}
	else
		return NULL;
}

void printBT(struct node *root)
{
	if(root == NULL)
		printf("( )");
	else
	{
		printf("( %ld ", root->data);
		printBT(root->left);
		printf(" ");
		printBT(root->right);
		printf(" )");
	}
}

int main()
{
	long int n, i;
	scanf("%ld", &n);
	long int preOrder[n], inOrder[n];
	for(i = 0; i < n; i++)
		scanf("%ld", &preOrder[i]);
	for(i = 0; i < n; i++)
		scanf("%ld", &inOrder[i]);
	struct node *BT = createBT(preOrder, 0, n-1, inOrder, 0, n-1);
	printBT(BT);
	return 0;
}