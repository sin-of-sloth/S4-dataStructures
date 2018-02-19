#include<stdio.h>
#include<stdlib.h>

struct node
{
        long long int data;
        struct node* next;
};

struct node *beg, *newNode, *temp;

struct node* createNewNode(long long int a)
{
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = a;
        newNode->next = NULL;
        return newNode;
}

void insertSLL(long long int a)
{
        newNode = createNewNode(a);
        if(newNode == NULL)
                printf("\nNo memory allocated.");
        else if(beg == NULL)
                beg = newNode;
        else
        {
                temp = beg;
                while(temp->next != NULL)
                        temp = temp->next;
                temp->next = newNode;
        }
}

void printSLL()
{
        temp = beg;
        while(temp->next != NULL)
        {
                printf("%lld ",temp->data);
                temp = temp->next;
        }
        printf("%lld\n", temp->data);
}

void reverseSLL()
{
        if(beg==NULL || beg->next==NULL)
                return;
        else
        {
                struct node *r;
                temp=beg->next;
                beg->next=NULL;
                while(temp->next != NULL)
                {
                        r=temp->next;
                        temp->next=beg;
                        beg=temp;
                        temp=r;
                }
                temp->next=beg;
                beg=temp;
        }
}

int main()
{
        long long int a=0;
        int c,cbefore = ' ', multiplier = 1;
        do
        {
          c=getchar();
          if(c=='\n')
          {
            if (cbefore != ' ')
            {
              insertSLL(multiplier * a);
            }
            break;
          }
          else if (c=='-')
            multiplier=-1;
          else if (c== ' ')
          {
            if (cbefore != ' ')
            {
              insertSLL(multiplier * a);
              a=0;
              multiplier = 1;
            }
            cbefore = c;
          }
          else
          {
            c -= 48;
            a = a*10 + c;
            cbefore = c;
          }
        }while(1);
        reverseSLL();
        printSLL();
        return 0;
}                                         