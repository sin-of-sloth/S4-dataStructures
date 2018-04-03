#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct vertexNode
{
	int u, parent, distance;
};

struct edgeNode
{
	int u, v, weight;
};

struct graph
{
	int noOfVertices;
	int noOfEdges;
	struct vertexNode *vertices;
	struct edgeNode *edges;
};


struct graph createGraph(int n, int m)
{
	int i;
	struct graph g;
	g.noOfVertices = n;
	g.noOfEdges = m;
	g.vertices = malloc(n * sizeof(struct vertexNode));
	g.edges = malloc(m * sizeof(struct edgeNode));
	for(i = 0; i < n; i++)
	{
		g.vertices[i].u = i;
		g.vertices[i].parent = -1;
		g.vertices[i].distance = INT_MAX;
	}
	return g;
}


struct graph initializeSingleSource(struct graph g, int s)
{
	int i;
	for(i = 0; i < g.noOfVertices; i++)
	{
		g.vertices[i].distance = INT_MAX;
		g.vertices[i].parent = -1;
	}
	g.vertices[s].distance = 0;
	return g;
}

struct graph relax(struct graph g, int u, int v, int w)
{
	if(g.vertices[v].distance > g.vertices[u].distance + w)
	{
		g.vertices[v].distance = g.vertices[u].distance + w;
		g.vertices[v].parent = u;
	}
	return g;
}

int bellmanFordAlgorithm(struct graph g, int s)
{
	g = initializeSingleSource(g, s);
	int i, j, u, v, w;
	for(i = 0; i < g.noOfVertices; i++)
	{
		for( j = 0; j < g.noOfEdges; j++)
			g = relax(g, g.edges[j].u, g.edges[j].v, g.edges[j].weight);
	}
	for( i = 0; i < g.noOfEdges; i++)
	{
		u = g.edges[i].u;
		v = g.edges[i].v;
		w = g.edges[i].weight;
		if(g.vertices[v].distance > g.vertices[u].distance + w)
			return 1;
	}
	return -1;
}


int main()
{
	int n, m, i, x, y, w, cycle;
	scanf("%d %d", &n, &m);
	struct graph g = createGraph(n, m);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		g.edges[i].u = x;
		g.edges[i].v = y;
		g.edges[i].weight = w;
	}
	cycle = bellmanFordAlgorithm(g, 0);
	printf("%d", cycle);
	return 0;
}