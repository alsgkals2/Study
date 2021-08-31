// ServiceCenter.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int vertexCounting = 0;

typedef struct vertex {
	int data;
	int check;

	struct vertex* Next;
	struct edge* adjacencylist;
}vertex; //����

typedef struct edge {
	int weight;
	struct edge* next;
	vertex* from;
	vertex* target;
}edge;

typedef struct tagGraph {
	vertex* vertices;
	int vertexCount;
}tagGraph;
typedef struct neighborvertexNum {
	int vertexNum = -1;
	int neighborNum = 0;
}nVertexNum;
////////////////////////////////////////


tagGraph* CreateGraph()
{
	tagGraph* graph = new tagGraph();
	graph->vertices = NULL;
	graph->vertexCount = 0;
	return graph;
}

void DestroyVertex(vertex *V)
{
	while (V->adjacencylist != NULL) {
		edge* edge = V->adjacencylist->next;
		delete V->adjacencylist;
		V->adjacencylist = edge;
	}

	delete V;
}
void DestroyGraph(tagGraph* G)
{
	while (G->vertices != NULL)
	{
		vertex* vertices = G->vertices->Next;
		DestroyVertex(G->vertices);
		G->vertices = vertices;
	}

	delete G;
}

edge* CreateEdge(vertex* from, vertex* target, int weight)
{
	edge* E = new edge();
	E->from = from;
	E->target = target;
	E->next = NULL;
	E->weight = weight;

	return E;
}

void addVertex(tagGraph* G, vertex* V)
{
	vertex* vertexList = G->vertices;
	if (vertexList == NULL) { G->vertices = V; }
	else {
		while (vertexList->Next != NULL)
			vertexList = vertexList->Next;

		vertexList->Next = V;
	}
}

void addEdge(vertex* V, edge* E)
{
	if (V->adjacencylist == NULL) V->adjacencylist = E;
	else {
		edge* adjacencyList = V->adjacencylist;
		while (adjacencyList->next != NULL)
			adjacencyList = adjacencyList->next;

		adjacencyList->next = E;
	}
}

vertex* FindorAddVertex(tagGraph* graph, int data) {
	if (!graph->vertices) {
		graph->vertices = new vertex();
		graph->vertices->data = data;
		graph->vertices->Next = NULL;
		graph->vertexCount++;
	}
	vertex* v = graph->vertices;

	if (v && v->data == data) return v;

	while (1) {
		//find
		if (v->Next && v->Next->data == data)
			return v->Next;

		//add
		if (v->Next == NULL) {
			v->Next = new vertex();
			v->Next->data = data;
			v->Next->Next = NULL;
			v->Next->check = false;
			graph->vertexCount++;
			return v->Next;
		}

		v = v->Next;
	}

}
nVertexNum* nvNum;
void NOfNeghiborDec(vertex* neghibor)//checkvertex�Լ����� �̿�Ž���Ǹ� �̿��� �̿��� check=false�̸� nvnum�� �̿��� ����
{
	edge* nofn = neghibor->adjacencylist;
	while (nofn) {
		nvNum[nofn->target->data].neighborNum--;
		nofn = nofn->next;
	}
}


void CheckVertex(tagGraph* graph, int data, int& counting, int* groupNum)
{
	vertex* v = graph->vertices;
	edge* edge;
	if (v && v->data == data)
	{
		if (!v->check) {
			v->check = true;
			//vertexCounting++;
			counting--;
			groupNum[v->data] = -1;
		}
		//���� check
		edge = v->adjacencylist;
		while (edge)
		{
			if (!edge->target->check) {//false�̸�
				edge->target->check = true;
				//vertexCounting++;
				counting--;
				
				NOfNeghiborDec(edge->target);
				groupNum[edge->target->data] = -1;
			}
			edge = edge->next;
		}
		return;

	}

	while (v->Next)
	{
		if (v->Next->data == data)
		{
			if (!v->Next->check) {
				v->Next->check = true;
				//vertexCounting++;
				counting--;
				groupNum[v->Next->data] = -1;

			}
			//���� check
			edge = v->Next->adjacencylist;
			while (edge)
			{
				if (!edge->target->check) {
					edge->target->check = true;
					//vertexCounting++;
					counting--;
					NOfNeghiborDec(edge->target);
					groupNum[edge->target->data] = -1;
				}
				edge = edge->next;
			}

			return;
		}
		v = v->Next;
	}
}

vertex* FindVertex(tagGraph* graph, int data)
{
	vertex* v = graph->vertices;
	while (v->data != data)
	{
		v = v->Next;
	}

	return v;
}

vertex*** vertexAddress = new vertex**[36]; //�׷캰 ù���� �ּ� ����

void PartitionGroup(int* groupNum, tagGraph* graph, int data, int& gNumber)
{
	vertex* v = new vertex();
	static int inc;

	if (vertexAddress[gNumber][0] == NULL) {
		inc = 0;
	}

	//0�� �ε����� ������������ �׷쳪����

	v = FindVertex(graph, data); //�ش�����ã��

	vertexAddress[gNumber][inc] = new vertex();
	vertexAddress[gNumber][inc] = v;
	groupNum[data] = gNumber;
	inc++;

	edge* e = v->adjacencylist;
	while (e) {
		if (groupNum[e->target->data] == 0) {
			PartitionGroup(groupNum, graph, e->target->data, gNumber);
		}
		e = e->next;
	}

}

int main()
{
	int i;
	int N, M;
	int vilige1, vilige2;
	int minimumNum = 0;
	int targetCounting[36];
	tagGraph *graph;
	int groupNum[36]; // -1�̸� �ƿ� �ش������� ����x 0�̸� ����o,check�Ǹ� -1
	int GNumber = 1;
	int groupCounting[36];
	for (i = 0; i < 36; i++)
		vertexAddress[i] = new vertex*[36];

	while (1) {
		cin >> N >> M;
		minimumNum = 0;
		if (N == 0 && M == 0) break;
		else if (M == 0) {
			cout << N << '\n'; continue;
		}
		vertexCounting = 0;
		GNumber = 1;
		for (int i = 0; i < 36; i++) {
			//targetCounting[i] = 0;
			groupNum[i] = -1;
			groupCounting[i] = 0;
		}
		nvNum = new nVertexNum[36];
		graph = new tagGraph();
		graph = CreateGraph();

		for (i = 0; i < 36; i++)
			for (int j = 0; j < 36; j++)
				vertexAddress[i][j] = NULL;

		for (i = 0; i < M; i++) {
			cin >> vilige1 >> vilige2;
			groupNum[vilige1] = 0;
			groupNum[vilige2] = 0;

			vertex* v1 = new vertex();
			vertex* v2 = new vertex();

			//vilige1 ����
			v1 = FindorAddVertex(graph, vilige1);
			nvNum[vilige1].vertexNum = vilige1;
			if (vilige1 != vilige2) nvNum[vilige1].neighborNum++;

			//vilige2 ����
			v2 = FindorAddVertex(graph, vilige2);
			nvNum[vilige2].vertexNum = vilige2;
			if (vilige1 != vilige2) nvNum[vilige2].neighborNum++;


			//�����߰�
			addEdge(v1, CreateEdge(v1, v2, 0));
			addEdge(v2, CreateEdge(v2, v1, 0));
		}


		//���� �׷쳪����
		for (i = 0; i <= N; i++)
		{
			if (groupNum[i] == 0)
			{
				PartitionGroup(groupNum, graph, i, GNumber);
				GNumber++;
			}
		}

		//�׷캰 �������� ����
		for (i = 0; i <= N; i++)
		{
			if (groupNum[i] != -1) {
				groupCounting[groupNum[i]]++;
			}
		}


		//�� �׷츶�� �̿����� ���帹�� ���� ã��
		int maxV;
		for (int g = 1; g < GNumber; g++) {
			while (groupCounting[g] != 0) {
				for (i = 1; i <= N; i++) if (groupNum[i] == g) { maxV = i; break; }

				for (i = maxV + 1; i <= N; i++) {
					if (groupNum[i] == g && nvNum[i].neighborNum > nvNum[maxV].neighborNum)
						maxV = i;
				}


				//����ó���� ���������ϸ��� ���������ؼ� �켱ó��(����ġ��)
				minimumNum++;
				//����ã�Ƽ� ���������� check = true
				CheckVertex(graph, nvNum[maxV].vertexNum, groupCounting[g], groupNum);

			}
		}

	
		cout << minimumNum << '\n';
		DestroyGraph(graph);
		delete nvNum;

	}
	return 0;

}