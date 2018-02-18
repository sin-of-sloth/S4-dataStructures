#include<stdio.h>
#include<stdlib.h>

#define lli long long int
#define node struct node2

node
{
        lli data;
        node* next;
};

node *beg, *newNode, *temp;

node* createNewNode(lli a)
{
        newNode = (node*)malloc(sizeof(node));
        newNode->data = a;
        newNode->next = NULL;
        return newNode;
}

void insertList(lli a)
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

void printList()
{
        temp = beg;
        while(temp->next != NULL)
        {
                printf("%lld ",temp->data);
                temp = temp->next;
        }
        printf("%lld\n", temp->data);
}

void reverseList()
{
        if(beg==NULL || beg->next==NULL)
                return;
        else
        {
                node *r;
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
        lli a=0;
        int c,cbefore = ' ', multiplier = 1;
        do
        {
          c=getchar();
          if(c=='\n')
          {
            if (cbefore != ' ')
            {
              insertList(multiplier * a);
            }
            break;
          }
          else if (c=='-')
            multiplier=-1;
          else if (c== ' ')
          {
            if (cbefore != ' ')
            {
              insertList(multiplier * a);
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
        reverseList();
        printList();
        return 0;
}                                         