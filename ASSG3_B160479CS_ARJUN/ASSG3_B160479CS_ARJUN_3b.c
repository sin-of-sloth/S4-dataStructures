#include<stdio.h>
#include<stdlib.h>

struct node
{
	long long int data;
	struct node* next;
}*head, *tail;


void enqueue(long long int element)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = element;
	newNode->next = NULL;
	if(tail == NULL)
	{
		tail = newNode;
		head = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

long long int dequeue()
{
	if(head == NULL)
	{
		return -1;
	}
	else if(head != tail)
	{
		long long int p = head->data;
		head = head->next;
		return p;
	}
	else
	{
		long long int p = head->data;
		head = NULL;
		tail = NULL;
		return p;
	}
}

void print_queue()
{
	struct node *temp = head;
	if(temp == NULL)
		printf("-1");
	else
	{
		while(temp != NULL)
		{
			printf("%lld ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}

int main()
{
	char c;
	long long int i, res;
	do
  	  {
    	c=getchar();
    
    	if(c=='e')
    	{
      	  scanf("%lld", &i);
 	      enqueue(i);
	    }
    	else if (c=='d')
    	{
      	  res=dequeue();
      	  printf("%lld\n", res);
    	}
    	else if (c=='p')
      	  print_queue();
    	else if (c=='s')
      	  break;
    	else
      	  ;
  	  }while(1);
	return 0;
}