#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct node
{
	int key;
	int distance;
	struct node *next;
};

struct vertexNode
{
	int key, parent, distance;
	char color;
};


struct node *createPQNode(int key, int distance)
{
	struct node *newPQNode = (struct node *)malloc(sizeof(struct node));
	newPQNode->key = key;
	newPQNode->distance = distance;
	newPQNode->next = NULL;
	return newPQNode;
}

struct node* priorityInsert(struct node *pq, int key, int distance)
{
	if(pq == NULL)
	{
		struct node *newPQNode = createPQNode(key, distance);
		return newPQNode;
	}
	else
	{
		if(pq->distance > distance)
		{
			struct node *newPQNode = createPQNode(key, distance);
			newPQNode->next = pq;
			return newPQNode;
		}
		else
		{
			pq->next = priorityInsert(pq->next, key, distance);
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
		g->vertex[i].parent = -1;
		g->vertex[i].distance = INT_MAX;
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
		newNode->distance = 0;
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

struct graph* dijkstrasAlgorithmSingleSourceAllDestinations(struct graph *g, int n, int s, int d)
{
	int i;
	for(i = 0; i < n; i++)
	{
		g->vertex[i].distance = INT_MAX;
		g->vertex[i].color = 'w';
		g->vertex[i].parent = -1;
	}
	g->vertex[s].distance = 0;
	g->vertex[s].color = 'g';
	struct node *priorityQ = NULL;
	priorityQ = priorityInsert(priorityQ, g->vertex[s].key, g->vertex[s].distance);
	while(priorityQ != NULL)
	{
		int u = priorityQ->key;				//same as
		priorityQ = priorityQ->next;		//extractMin
		struct node *currentVertex = g->adjacencyList[u];
		while(currentVertex != NULL)
		{
			int v = currentVertex->key;
			if(g->vertex[v].color != 'b')
			{
				if(g->vertex[v].distance > g->vertex[u].distance + currentVertex->distance)
				{
					g->vertex[v].parent = u;
					g->vertex[v].distance = g->vertex[u].distance + currentVertex->distance;
					g->vertex[v].color = 'g';
					priorityQ = priorityInsert(priorityQ, g->vertex[v].key, g->vertex[v].distance);
				}
			}
			currentVertex = currentVertex->next;
		}
		g->vertex[u].color = 'b';
	}
	
	if(d == -1)
	{
		for( i = 0; i < n; i++)
		{
			if(g->vertex[i].distance != INT_MAX)
				printf("%d ", g->vertex[i].distance);
			else
				printf("INF ");
		}
		printf("\n");
	}
	return g;
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
            printf("%d (%d)-> ", currentVertex->key, currentVertex->distance);
            currentVertex = currentVertex->next;
        }
        printf("NULL\n");
    }
}


int main()
{
	int n, i, s, d, key, digit;
	char command[4];
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
		key = -1;
		while(1)
		{
			digit = getchar();
			if(digit == 10)
			{
				if(key != -1)
					currentVertex->distance = key;
				break;
			}
			else if(digit == ' ')
			{
				currentVertex->distance = key;
				key = -1;
				currentVertex = currentVertex->next;
			}
			else
			{
				if(key == -1)
					key = 0;
				key = key * 10 + ( (int)digit - 48 );
			}
		}
	}
	while(1)
	{
		scanf("%s", command);
		if(strcmp(command, "stop") == 0)
			break;
		else if(strcmp(command, "apsp") == 0)
		{
			scanf("%d", &s);
			g = dijkstrasAlgorithmSingleSourceAllDestinations(g, n, s, -1);
		}
		else if(strcmp(command, "sssp") == 0)
		{
			scanf("%d %d", &s, &d);
			g = dijkstrasAlgorithmSingleSourceAllDestinations(g, n, s, d);
			if(g->vertex[d].distance != INT_MAX)
				printf("%d\n", g->vertex[d].distance);
			else
				printf("UNREACHABLE\n");
		}
		else
			;
	}
	return 0;
}
