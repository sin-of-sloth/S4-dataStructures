#include<stdio.h>
#include<stdlib.h>

#define MAX 100000

long int S[MAX];
int top = -1;

void push(long int a)
{
	S[++top] = a;
}

long int pop()
{
	return S[top--];
}


int main()
{
	int infix[MAX];
	char *postfix = (char*)malloc(sizeof(char)), ch;
	int i, j, inLen = -1, postLen = -1;
	long int a = 0, res, num1, num2;
	for(i=0;i<MAX;i++)
		infix[i] = -1;
	while((ch = getchar()) != '\n')
	{
		postLen+=1;
		postfix = (char*)realloc(postfix, sizeof(char) * (postLen + 1));
		postfix[postLen] = ch;
	}
	
	i=0;
	for(i=0; i<=postLen; i++)
	{
		if(postfix[i] == ' ')
		{
			if((i>0) && (postfix[i-1]>='0') && (postfix[i-1]<='9'))
			{
				push(a);
				infix[++inLen] = a;
				a=0;
				inLen++;
			}
		}
		else if((postfix[i]>='0') && (postfix[i]<='9'))
		{
			a = a*10 + (int)postfix[i] - 48;
		}
		else
		{
			j = inLen-2;
			while(infix[j] != -1)
				j-=2;
			infix[j] = (int)postfix[i];
			num2 = pop();
			num1 = pop();
			if(postfix[i] == '+')
				push(num1 + num2);
			else if(postfix[i] == '-')
				push(num1 - num2);
			else if(postfix[i] == '*')
				push(num1 * num2);
			else if(postfix[i] == '/')
				push(num1/num2);
			else if(postfix[i] == '%')
				push(num1%num2);
			else if(postfix[i] == '^')
			{
				a=num1;
				for(j=0;j<num2-1;j++)
					num1 = num1 * a;
				push(num1);
			}
		}
	}
	res = pop();
	for(i=0;i<=inLen;i++)
	{
		if(i%2 == 0)
			printf("%d", infix[i]);
		else
			printf("%c", infix[i]);
	}
	printf("\n%ld", res);
	return 0;
}