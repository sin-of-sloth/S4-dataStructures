#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void push(struct node** S, int a)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = a;
	newNode->next = *S;
	*S = newNode;
}

int pop(struct node** S)
{
	int q = (*S)->data;
	*S = (*S)->next;
	return q;
}


int main()
{
	char *prefix = (char*)malloc(sizeof(char)), symbol;
	int length = 0, i, result, num1, num2;
	
	//INPUTTING THE prefix EXPRESSION
	do{
		length++;
		symbol = getchar();
		prefix = (char*)realloc(prefix, sizeof(char) * length);
		prefix[length-1] = symbol;
	}while(symbol != '\n');
	
	printf("%s", prefix);
	char infix[length];
	
	//BUILDING infix EXPRESSION
	int k = 0, j;
	for(i=0;i<length-1;i++)
	{
		if(prefix[i]>='0' && prefix[i]<='9')
			infix[k]=prefix[i];
		else if(prefix[i] == ' ')
			infix[k]='~';
		else
		{
			j=k-3;
			while(infix[j] != '~')
			{
				if(infix[j-1]>='0' && infix[j-1]<='9')
					j--;
				else
					j-=3;
			}
			infix[j]=prefix[i];
			k--;
		}
		
	printf("%s\n", infix);
		k++;
	}
	
	//EVALUATING THE RESULT
	
	
	return 0;
}