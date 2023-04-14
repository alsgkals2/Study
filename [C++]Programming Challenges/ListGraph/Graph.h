#pragma once

typedef char ElementType;
typedef struct tagVertex {
	ElementType Data;
	int Visited;
	//int Index;

	struct tagVertex* Next;
	struct tagEdge* AdjacencyList;
}Vertex;

typedef struct tagEdge {
	int Weight;
	struct tagEdge* Next;
	Vertex* From;
	Vertex* Target;

}Edge;

typedef struct tagGraph
{
	Vertex* Vertices;
	int VertexCount;

}Graph;

Graph* CreateGraph() {
	Graph* graph = new Graph();
	graph->Vertices = NULL;
	graph->VertexCount = 0;

	return graph;
}

Vertex* CreateVertex(ElementType Data) {

	Vertex* V = new Vertex();

	V->Data = Data;
	V->Next = NULL;
	V->AdjacencyList = NULL;
	V->Visited = 0;
	//V->Index = -1;

	return V;
}

Edge* CreateEdge(Vertex* From, Vertex* Target){//, int Weight) {
	Edge* E = new Edge();
	E->From = From;
	E->Target = Target;
	E->Next = NULL;
	//E->Weight = Weight;

	return E;
}

void addVertex(Graph* G, Vertex* V) {
	Vertex* VertexList = G->Vertices;

	if (VertexList == NULL) G->Vertices = V;
	else {
		while (VertexList->Next != NULL) VertexList = VertexList->Next;

		VertexList->Next = V;
	}
	//V->Index = G->VertexCount++;
}

void AddEdge(Vertex* V, Edge* E,int Weight) {
	if (V->AdjacencyList == NULL) { V->AdjacencyList = E; 
	V->AdjacencyList->Weight = Weight;
	}

	else {
		bool swit = false;
		Edge* AdjacencyList = V->AdjacencyList;
		
		if (V->AdjacencyList != NULL && AdjacencyList->From == E->From && AdjacencyList->Target == E->Target)
			swit = true;
		
		while (AdjacencyList->Next != NULL)
		{
			if (AdjacencyList->Next->From == E->From && AdjacencyList->Next->Target == E->Target) {
				swit = true;  break;
			}
			AdjacencyList = AdjacencyList->Next;
		}
		if (!swit) {
			AdjacencyList->Next = E;
			AdjacencyList->Next->Weight = Weight;
		}

	}

}

	





