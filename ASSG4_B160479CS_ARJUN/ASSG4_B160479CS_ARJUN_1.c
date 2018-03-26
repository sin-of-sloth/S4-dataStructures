#include<stdio.h>
#include<stdlib.h>

long int m;

struct node{
	long int element;
	struct node *next;
}*chainedHashTable;

int isPrime(long int p)
{
	int i;
	for(i = 2; i < p; i++)
	{
		if(p % i == 0)
			return 0;
	}
	return 1;
}
long int predecessorPrime(long int x)
{
	x--;
	while(x > 2)
	{
		if(isPrime(x))
			return x;
		x--;
	}
	return x;
}


void insert(long int *hashTable, long int element, char hashFunction)
{
	long int i;
	if(hashFunction == 'a')
	{
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + i) % m;
			if(hashTable[hashValue] == 0)
			{
				hashTable[hashValue] = element;
				break;
			}
		}
	}
	else if(hashFunction == 'b')
	{
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + (i * i)) % m;
			if(hashTable[hashValue] == 0)
			{
				hashTable[hashValue] = element;
				break;
			}
		}
	}
	else if(hashFunction == 'c')
	{
		long int R = predecessorPrime(m);
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + (i * (R - (element % R)))) % m;
			if(hashTable[hashValue] == 0)
			{
				hashTable[hashValue] = element;
				break;
			}
		}
	}
}

void chainedInsert(long int element)
{
	int hashValue = element % m;
	struct node *p = &chainedHashTable[hashValue];
	while(p->next != NULL)
		p = p->next;
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->element = element;
	newNode->next = NULL;
	p->next = newNode;
}


void search(long int *hashTable, long int element, char hashFunction)
{
	long int i;
	if(hashFunction == 'a')
	{
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + i) % m;
			if(hashTable[hashValue] != 0)
			{
				if(hashTable[hashValue] == element)
				{
					printf("1\n");
					break;
				}
			}
			else
			{
				printf("-1\n");
				break;
			}
		}
	}
	else if(hashFunction == 'b')
	{
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + (i * i)) % m;
			if(hashTable[hashValue] != 0)
			{
				if(hashTable[hashValue] == element)
				{
					printf("1\n");
					break;
				}
			}
			else
			{
				printf("-1\n");
				break;
			}
		}
	}
	else if(hashFunction == 'c')
	{
		long int R = predecessorPrime(m);
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + (i * (R - (element % R)))) % m;
			if(hashTable[hashValue] != 0)
			{
				if(hashTable[hashValue] == element)
				{
					printf("1\n");
					break;
				}
			}
			else
			{
				printf("-1\n");
				break;
			}
		}
	}	
}


void chainedSearch(long int element)
{
	int hashValue = element % m;
	struct node *p = &chainedHashTable[hashValue];
	p = p->next;
	while(p != NULL)
	{
		if(p->element == element)
		{
			printf("1\n");
			return;
		}
		p = p->next;
	}
	printf("-1\n");
}


void delete(long int *hashTable, long int element, char hashFunction)
{
	long int i;
	if(hashFunction == 'a')
	{
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + i) % m;
			if(hashTable[hashValue] != 0)
			{
				if(hashTable[hashValue] == element)
				{
					hashTable[hashValue] = -1;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if(hashFunction == 'b')
	{
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + (i * i)) % m;
			if(hashTable[hashValue] != 0)
			{
				if(hashTable[hashValue] == element)
				{
					hashTable[hashValue] = -1;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else if(hashFunction == 'c')
	{
		long int R = predecessorPrime(m);
		for(i = 0; i < m; i++)
		{
			int hashValue = ((element % m) + (i * (R - (element % R)))) % m;
			if(hashTable[hashValue] != 0)
			{
				if(hashTable[hashValue] == element)
				{
					hashTable[hashValue] = -1;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
}



void chainedDelete(long int element)
{
	int hashValue = element % m;
	struct node *p = &chainedHashTable[hashValue], *q;
	q = p->next;
	while(q != NULL)
	{
		if(q->element == element)
		{
			p->next = q->next;
			q->next = NULL;
			return;
		}
		p = q;
		q = q->next;
	}
	printf("-1\n");
}



void print(long int *hashTable)
{
	int i;
	for(i = 0; i < m; i++)
	{
		if(hashTable[i] > 0)
		   	printf("%d (%ld)\n", i, hashTable[i]);
		else
			printf("%d ()\n", i);
	}
}



void chainedPrint()
{
	int i;
	for(i = 0; i < m; i++)
	{
		struct node *p = &chainedHashTable[i];
		printf("%d (", i);
		p = p->next;
		while(p != NULL)
		{
			printf("%ld", p->element);
			p = p->next;
			if(p != NULL)
				printf(" ");
		}
		printf(")\n");
	}
}



int main()
{
	char hashFunction, c;
	long int element;
	scanf("%c", &hashFunction);
	scanf("%ld", &m);
	if(hashFunction != 'd')
	{
		long int hashTable[m];
		int i;
		for(i = 0; i < m; i++)
		{
			hashTable[i] = 0;
		}
		while(1)
		{
			scanf("%c", &c);
			if(c == 'i')
			{
				scanf("%ld", &element);
				insert(hashTable, element, hashFunction);
			}
			else if(c == 's')
			{
				scanf("%ld", &element);
				search(hashTable, element, hashFunction);
			}
			else if(c == 'd')
			{
				scanf("%ld", &element);
				delete(hashTable, element, hashFunction);
			}
			else if(c == 'p')
				print(hashTable);
			else if(c == 't')
				return 0;				
		}
	}
	else
	{
		int i;
		chainedHashTable = (struct node *)calloc(m, sizeof(struct node));
		for(i = 0; i < m; i++)
			chainedHashTable[i].next = NULL;
		while(1)
		{
			scanf("%c", &c);
			if(c == 'i')
			{
				scanf("%ld", &element);
				chainedInsert(element);
			}
			else if(c == 's')
			{
				scanf("%ld", &element);
				chainedSearch(element);
			}
			else if(c == 'd')
			{
				scanf("%ld", &element);
				chainedDelete(element);
			}
			else if(c == 'p')
				chainedPrint();
			else if(c == 't')
				return 0;				
		}
	}
	return 0;
}