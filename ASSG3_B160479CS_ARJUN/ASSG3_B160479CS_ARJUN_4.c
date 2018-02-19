#include<stdio.h>
#include<stdlib.h>

#define MAX 10000000

struct node
{
	long int val;
	long int pr;
}pq[MAX];

int heapSize = -1;


void pqMinHeapify(int i)
{
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int smallest;

  if(left <= heapSize && pq[left].pr < pq[i].pr)
    smallest = left;
  else
    smallest = i;
  if(right <= heapSize && pq[right].pr < pq[smallest].pr)
    smallest = right;
  if(smallest != i)
    {
      struct node temp = pq[i];
      pq[i] = pq[smallest];
      pq[smallest] = temp;
      pqMinHeapify(smallest);
    }
}


void insert(long int elem, long int pr)
{
	heapSize += 1;
	pq[heapSize].val = elem;
	pq[heapSize].pr = pr;
	int i=heapSize;
	while(i>0 && pq[(i-1)/2].pr > pq[i].pr)
	{
		struct node temp = pq[(i-1)/2];
		pq[(i-1)/2] = pq[i];
		pq[i] = temp;
		i = (i-1)/2;
	}
}

void extract_min()
{
	if(heapSize == -1)
		printf("EMPTY\n");
	else
	{
		printf("%ld (%ld)\n", pq[0].val, pq[0].pr);
		pq[0] = pq[heapSize];
		heapSize -= 1;
		pqMinHeapify(0);
	}
}

void get_min()
{
	if(heapSize == -1)
		printf("EMPTY\n");
	else
		printf("%ld (%ld)\n", pq[0].val, pq[0].pr);
}

void decrease_priority(long int elem, long int pr)
{
	int i=0;
	while(1)
	{
		if(pq[i].val == elem)
		{
			pq[i].pr = pr;
			break;
		}
		else
			i++;
	}
		
	while(i>0 && pq[(i-1)/2].pr > pq[i].pr)
	{
		struct node temp = pq[(i-1)/2];
		pq[(i-1)/2] = pq[i];
		pq[i] = temp;
		i=(i-1)/2;
	}
}


int main()
{
	char c;
	long int val, pr;
	do
	{
		c = getchar();
		if(c=='a')
	    {
	      scanf("%ld %ld", &val, &pr);
	      insert(val, pr);
	    }
	    else if (c=='e')
	    {
	      extract_min();
	    }
	    else if (c=='g')
	      get_min();
	    else if (c=='d')
		{
			scanf("%ld %ld", &val, &pr);
			decrease_priority(val, pr);
		}
		else if (c=='s')
			break;
	    else
	      ;
	}while(1);
	return 0;
}