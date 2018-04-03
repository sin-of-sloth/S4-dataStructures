#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct node
{
	int key;
	int weight;
	struct node *next;
};

struct pqNode
{
	int u, v, weight;
	struct pqNode *next;
};


struct vertexNode
{
	int key, representative, weight;
	char color;
};


struct pqNode *createPQNode(int u, int v, int weight)
{
	struct pqNode *newPQNode = (struct pqNode *)malloc(sizeof(struct pqNode));
	newPQNode->u = u;
	newPQNode->v = v;
	newPQNode->weight = weight;
	newPQNode->next = NULL;
	return newPQNode;
}

struct pqNode* priorityInsert(struct pqNode *pq, int u, int v, int weight)
{
	if(pq == NULL)
	{
		struct pqNode *newPQNode = createPQNode(u, v, weight);
		return newPQNode;
	}
	else
	{
		if(pq->weight > weight)
		{
			struct pqNode *newPQNode = createPQNode(u, v, weight);
			newPQNode->next = pq;
			return newPQNode;
		}
		else
		{
			pq->next = priorityInsert(pq->next, u, v, weight);
			return pq;
		}
	}
}

struct graph
{
	int noOfVertices;
	struct vertexNode *vertex;
	struct node **adjacencyList;
};

//CREATING A GRAPH WITH n VERTICES
struct graph* createGraph(int noOfVertices)
{
	struct graph *g = (struct graph *)malloc(sizeof(struct graph));
	g->noOfVertices = noOfVertices;
	g->adjacencyList = malloc(noOfVertices * sizeof(struct node*));
	g->vertex = malloc(noOfVertices * sizeof(struct vertexNode));
	int i;
	for( i = 0; i < noOfVertices; i++)
	{
		g->adjacencyList[i] = NULL;
		g->vertex[i].key = i;
		g->vertex[i].color = 'w';
		g->vertex[i].representative = -1;
		g->vertex[i].weight = INT_MAX;
	}
	return g;
}

//CREATING AN ADJACENCY LIST NODE
struct node* createNewNode(int key)
{
	if(key == -1)
		return NULL;
	else
	{
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->key = key;
		newNode->weight = 0;
		newNode->next = NULL;
		return newNode;
	}
}

//INSERTNG INTO AN ADJACENCNY LIST
struct node* insert(struct node *p, struct node *q)
{
	if(p == NULL)
		return q;
	else
	{
		p->next = insert(p->next, q);
		return p;
	}
}

int findSet(struct graph *g, int u)
{
	return g->vertex[u].representative;
}

struct graph* setUnion(struct graph *g, int u, int v)
{
	int i;
	for(i = 0; i < g->noOfVertices; i++)
		if(g->vertex[i].representative == v)
			g->vertex[i].representative = u;
	return g;
}

long int kruskalsAlgorithm(struct graph *g)
{
	int i, u, v;
	struct pqNode *pq = NULL;
	long int sumOfEdgeWeights = 0;
	for(i = 0; i < g->noOfVertices; i++)
	{
		g->vertex[i].weight = INT_MAX;
		g->vertex[i].color = 'w';
		g->vertex[i].representative = i;
		struct node *currentVertex = g->adjacencyList[i];
		while(currentVertex != NULL)
		{
			pq = priorityInsert(pq, i, currentVertex->key, currentVertex->weight);
			currentVertex = currentVertex->next;
		}
	}
	
	while(pq != NULL)
	{
		u = pq->u;
		v = pq->v;
		if(findSet(g, u) != findSet(g, v))
		{
			sumOfEdgeWeights += pq->weight;
			g = setUnion(g, findSet(g, u), findSet(g, v));
		}
		pq = pq->next;
	}
	return sumOfEdgeWeights;
}

void printGraph(struct graph* g)
{
    int v;
    for (v = 0; v < g->noOfVertices; v++)
    {
        struct node* currentVertex = g->adjacencyList[v];
        printf("%d %c : ", g->vertex[v].key, g->vertex[v].color);
        while (currentVertex != NULL)
        {
            printf("%d (%d)-> ", currentVertex->key, currentVertex->weight);
            currentVertex = currentVertex->next;
        }
        printf("NULL\n");
    }
}


int main()
{
	int n, i, key, digit, multiplier;
	scanf("%d", &n);
	struct graph *g = createGraph(n);	
	digit = getchar();
	for(i = 0; i < n; i++)
	{
		struct node *reachableVertex = NULL;
		key = -1;
		while(1)
		{
			digit = getchar();
			if(digit == 10)
			{
				reachableVertex = createNewNode(key);
				g->adjacencyList[i] = insert(g->adjacencyList[i], reachableVertex);
				break;
			}
			else if(digit == ' ')
			{
				reachableVertex = createNewNode(key);
				g->adjacencyList[i] = insert(g->adjacencyList[i], reachableVertex);
				key = -1;
				multiplier = 1;
			}
			else
			{
				if(key == -1)
					key = 0;
				key = key * 10 + ( (int)digit - 48 );
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		struct node *currentVertex = g->adjacencyList[i];
		key = -10001;
		multiplier = 1;
		while(1)
		{
			digit = getchar();
			if(digit == 10)
			{
				if(key != -10001)
					currentVertex->weight = multiplier * key;
				multiplier = 1;
				break;
			}
			else if(digit == ' ')
			{
				currentVertex->weight = multiplier * key;
				key = -10001;
				multiplier = 1;
				currentVertex = currentVertex->next;
			}
			else if(digit == '-')
				multiplier = -1;
			else
			{
				if(key == -10001)
					key = 0;
				key = key * 10 + ( (int)digit - 48 );
			}
		}
	}
	long int sumOfEdgeWeights = kruskalsAlgorithm(g);
	printf("%ld", sumOfEdgeWeights);
	return 0;
}
