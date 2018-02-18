#include<stdio.h>
#include<stdlib.h>
#define lli long long int

int *Q, head, tail, length;

int isEmptyQ()
{
  if(head == tail)
    return 1;
  else return 0;
}

int qFull()
{
  if((tail+1)%(length) == head)
    return 1;
  else return 0;
}

int enqueue(int element)
{
  if(qFull())
    return -2;
  else
    {
      Q[tail]=element;
      tail = (tail+1)%(length);
      return 1;
    }
}

lli dequeue()
{
  if(isEmptyQ())
    return -1;
  else
    {
      lli p = Q[head];
      head = (head+1)%(length);
      return p;
    }
}

void print_queue()
{
  if(isEmptyQ())
    printf("-1");
  else
  {
  	  int i=head;
  	  while(i != tail)
  	  {
    	printf("%d ", Q[i]);
    	i = (i+1)%(length);
  	  }
  }
  printf("\n");
}

int main()
{
  char c;
  scanf("%d", &length);
  length+=1;
  Q=(int*)malloc(sizeof(int) * length);
  lli i, res;
  do
  {
    c=getchar();
    
    if(c=='e')
    {
      scanf("%lld", &i);
      res=enqueue(i);
      if(res == -2)
        printf("-2\n");
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