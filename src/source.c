#include <stdio.h>
#include <stdlib.h>

//#include "Stack.c"

typedef enum Graph_Type
{
	DIRECTED_GRAPH,
	UNDIRECTED_GRAPH
}Graph_Type;

typedef struct Node
{
	int iVertexNo;
	struct Node* next;
}Node;

typedef struct AdjList
{
	struct Node* head;
}AdjList;

typedef struct Graph
{
	int iVertexCount;
	Graph_Type iDirected;
	struct AdjList *NodeList;
}Graph;

Node* GetAdjacentVertex(int xVal)
{
	Node *retVal = (Node*)malloc(sizeof(struct Node));

	if (!retVal)
		return NULL;

	retVal->iVertexNo = xVal;
	retVal->next = NULL;

	return retVal;
}

Graph* CreateGraph(int iCountVertex, Graph_Type gType)
{
	Graph *graph = (Graph*)calloc(1,sizeof(struct Graph));
	if (graph == NULL)
		return NULL;

	graph->iVertexCount = iCountVertex;
	graph->iDirected = gType;
	graph->NodeList = (AdjList*)calloc(iCountVertex,sizeof( struct AdjList));

	return graph;
}

void AddEdge(Graph *graph, int xVertex, int yVertex)
{
	Node* temp = GetAdjacentVertex(yVertex);
	temp->next = graph->NodeList[xVertex].head;
	graph->NodeList[xVertex].head = temp;

	if (graph->iDirected == UNDIRECTED_GRAPH)
	{
		temp = GetAdjacentVertex(xVertex);
		temp->next = graph->NodeList[yVertex].head;
		graph->NodeList[yVertex].head = temp;
	}
}

void PrintGraph(Graph *g)
{
	int i = 0;

	for (i = 0; i < g->iVertexCount; i++)
	{
		Node *temp = g->NodeList[i].head;
		printf("List %d", i);
		while (temp!= NULL)
		{
			printf("-> %d", temp->iVertexNo);
			temp = temp->next;
			
		}
		printf("\n");
	}
}

void FreeNodes(Node **ptr)
{
	Node *Curr	=	*ptr;
	Node* next;

	while(Curr != NULL)
	{
		next = Curr->next;
		free(Curr);
		Curr = next;
	}
	*ptr = NULL;
}

void FreeList(AdjList *list)
{
	FreeNodes(&list->head);
}

void FreeGraph(Graph *g)
{
	int i;

	for(i = 0; i < g->iVertexCount;i++)
	{
		FreeList(&g->NodeList[i]);
	}

	free(g);
}

void TraverseBFS(Graph *g, int iVertex)
{

}

void main_simple_graph_creation()
{
	Graph *gGraph = CreateGraph(5, UNDIRECTED_GRAPH);

	AddEdge(gGraph, 0, 1);
	AddEdge(gGraph, 0, 4);
	AddEdge(gGraph, 1, 2);
	AddEdge(gGraph, 1, 3);
	AddEdge(gGraph, 1, 4);
	AddEdge(gGraph, 2, 3);
	AddEdge(gGraph, 3, 4);

	PrintGraph(gGraph);

	FreeGraph(gGraph);

}

void main_()
{
	main_simple_graph_creation();
}