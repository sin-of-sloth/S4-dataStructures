#include<stdio.h>
#include<stdlib.h>

long int S[10000];
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
	char *postfix = (char*)malloc(sizeof(char));
	int symbol;
	long int length = 0, i, result, num1, num2;
	
	//INPUTTING THE postfix EXPRESSION
	do{
		length++;
		symbol = getchar();
		postfix = (char*)realloc(postfix, sizeof(char) * length);
		postfix[length-1] = symbol;
		
		if(symbol>='0' && symbol<='9')
		{
			if(length>0 && postfix[length-2]!=' ')
			{
				num1 = symbol-48 + 10*pop();
				push(num1);
			}
			else
				push(symbol-48);
		}
		else if(symbol == ' ')
			continue;
		else if(symbol == '\n')
			break;
		else
		{
			num2 = pop();
			num1 = pop();
			if(symbol == '+')
				push(num1 + num2);
			else if(symbol == '-')
				push(num1-num2);
			else if(symbol == '*')
				push(num1*num2);
			else if(symbol == '/')
				push(num1/num2);
			else if(symbol == '%')
				push(num1%num2);
		}
	}while(symbol != '\n');
	result = pop();
	printf("%ld\n%s", result, postfix);
	char infix[length];
	
	//BUILDING infix EXPRESSION
	
	
	//EVALUATING THE RESULT
	for(i=0;i<length-1;i++)
	{
		if(postfix[i]>='0' && postfix[i]<='9')
		{
			if(i>0 && postfix[i-1]>='0' && postfix[i-1]<='9')
			{
				num1 = (int)postfix[i];
				num1 = num1-48 + (10*pop());
				push(num1);
			}
			else
			{
				num1 = (int)postfix[i];
				push(num1-48);
			}
		}
		else if(postfix[i] == ' ')
			continue;
		else if(postfix[i] == '\n')
			break;
		else
		{
			num2 = pop();
			num1 = pop();
			if(postfix[i] == '+')
				push(num1 + num2);
			else if(postfix[i] == '-')
				push(num1-num2);
			else if(postfix[i] == '*')
				push(num1*num2);
			else if(postfix[i] == '/')
				push(num1/num2);
			else if(postfix[i] == '%')
				push(num1%num2);	
		}
	}

	return 0;
}