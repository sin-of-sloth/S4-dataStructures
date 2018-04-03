#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct node
{
	int key;
	struct node *next;
};

struct vertexNode
{
	int key, parent, distance;
	char color;
};


struct graph
{
	int noOfVertices;
	struct vertexNode *vertex;
	struct node **adjacencyList;
};


//STACK OPERATIONS
void push(int *stack, int *top, int data)
{
	*top += 1;
	stack[*top] = data;
}

int pop(int *stack, int *top)
{
	int elem = stack[*top];
	*top -= 1;
	return elem;
}


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

//BREADTH FIRST SEARCH
void breadthFirstSearch(struct graph *g, int n, int s, int key)
{
	int i;
	for( i = 0; i < n; i++)
	{
		g->vertex[i].parent = -1;
		g->vertex[i].color = 'w';
		g->vertex[i].distance = INT_MAX;
	}
	g->vertex[s].color = 'g';
	g->vertex[s].distance = 0;
	printf("%d ", g->vertex[s].key);
	if(g->vertex[s].key == key)
	{
		printf("\n");
		return;
	}
	int stack[n], top = -1;
	push(stack, &top, s);
	while(top != -1)
	{
		int u = pop(stack, &top);
		struct node *currentVertex = g->adjacencyList[u];
		while(currentVertex != NULL)
		{
			int v = currentVertex->key;
			if(g->vertex[v].color == 'w')
			{
				printf("%d ", g->vertex[v].key);
				if(g->vertex[v].key == key)
				{
					printf("\n");
					return;
				}
				g->vertex[v].color = 'g';
				g->vertex[v].distance = g->vertex[u].distance + 1;
				g->vertex[v].parent = g->vertex[u].key;
				push(stack, &top, g->vertex[v].key);
			}
			currentVertex = currentVertex->next;
		}
		g->vertex[u].color = 'b';
	}
	printf("\n");
}

//DEPTH FIRST SEARCH
void depthFirstSearch(struct graph *g, int n, int s, int key)
{
	int i;
	for( i = 0; i < n; i++)
	{
		g->vertex[i].parent = -1;
		g->vertex[i].color = 'w';
		g->vertex[i].distance = INT_MAX;
	}
	int stack[n], top = -1;
	g->vertex[s].color = 'g';
	push(stack, &top, s);
	while(top != -1)
	{
		int u = pop(stack, &top);
		printf("%d ", g->vertex[u].key);
		if(g->vertex[u].key == key)
			break;
		struct node *currentVertex = g->adjacencyList[u];
		while(currentVertex != NULL)
		{
			int v = currentVertex->key;
			if(g->vertex[v].color == 'w')
			{
				g->vertex[v].color = 'g';
				g->vertex[v].parent = 'u';
				push(stack, &top, v);
			}
			currentVertex = currentVertex->next;
		}
		g->vertex[u].color = 'b';
	}
	printf("\n");
}


void printGraph(struct graph* g)
{
    int v;
    for (v = 0; v < g->noOfVertices; v++)
    {
        struct node* currentVertex = g->adjacencyList[v];
        printf("%d %d %c : ", g->vertex[v].key, g->vertex[v].distance, g->vertex[v].color);
        while (currentVertex != NULL)
        {
            printf("%d -> ", currentVertex->key);
            currentVertex = currentVertex->next;
        }
        printf("NULL\n");
    }
}



int main()
{
	int n, i, key, s, digit;
	char command[3];
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
	
	while(1)
	{
		scanf("%s", command);
		if(strcmp(command, "stp") == 0)
			break;
		else if(strcmp(command, "bfs") == 0)
		{
			scanf("%d %d", &s, &key);
			breadthFirstSearch(g, n, s, key);
		}
		else if(strcmp(command, "dfs") == 0)
		{
			scanf("%d %d", &s, &key);
			depthFirstSearch(g, n, s, key);
		}
		else
			;
	}
	return 0;
}