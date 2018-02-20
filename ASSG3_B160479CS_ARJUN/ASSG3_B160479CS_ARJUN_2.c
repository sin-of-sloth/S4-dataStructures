#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* next;
};

struct node *temp, *large;

void insertSLL(struct node** head, int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next=NULL;
	if((*head)==NULL)
		(*head) = newNode;
	else
	{
		temp = (*head);
		while((temp)->next != NULL)
		temp = temp->next;
		temp->next = newNode;
	}
}

void difference_of_digits(struct node** head1, struct node* head2)
{
	if((*head1)->data < head2->data)
	{
		(*head1)->data +=10;
		(*head1)->next->data -= 1;
	}
	(*head1)->data = (*head1)->data - (head2->data);
	if(head2->next != NULL)
		difference_of_digits(&((*head1)->next), head2->next);
}

void reverseSLL(struct node** head)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;
	else
	{
		struct node *temp2;
		temp = (*head)->next;
		(*head)->next = NULL;
		while(temp->next != NULL)
		{
			temp2 = temp->next;
			temp->next = (*head);
			(*head) = temp;
			temp = temp2;
		}
		temp->next = (*head);
		(*head) = temp;
	}
}


void printSLL(struct node *head, int n)
{
	temp = head;
	while(temp->data == 0)
	{
		temp = temp->next;
		n--;
	}
	if(n==0)
	{
		printf("0");
	}
	while(n>0)
	{
		printf("%d", temp->data);
		temp = temp->next;
		n--;
	}
}


int main()
{
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	struct node *small;
	int ch, n = 0;
	//INPUT SLL 1
	do{
		ch=getchar();
		if(ch=='\n')
			break;
		else
		{
			n++;
			ch-=48;
			insertSLL(&head1, ch);
		}
	}while(1);
	
	//INPUT SLL 2
	do{
		ch=getchar();
		if(ch=='\n')
			break;
		else
		{
			ch-=48;
			insertSLL(&head2, ch);
		}
	}while(1);
	
	//ASSIGNING LARGEST AND SMALLEST
	large = head1;
	small = head2;
	while(head1 != NULL)
	{
		if(head1->data == head2->data)
		{
			head1 = head1->next;
			head2 = head2->next;
			n--;
		}
		else if(head1->data < head2->data)
		{
			large = head2;
			small = head1;
			break;
		}
		else
			break;
	}
	
	//REVERSING AND SUBTRACTING
	reverseSLL(&large);
	reverseSLL(&small);
	difference_of_digits(&large, small);
	//REVERSING RESULT
	reverseSLL(&large);
	//PRINTING RESUKT
	printSLL(large, n);
	return 0;
}