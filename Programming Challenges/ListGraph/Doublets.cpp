// Doublets.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <iostream>
#include <string>

#pragma once

typedef struct tagVertex {
	int Data;
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

Vertex* CreateVertex(int Data) {

	Vertex* V = new Vertex();

	V->Data = Data;
	V->Next = NULL;
	V->AdjacencyList = NULL;
	V->Visited = 0;
	//V->Index = -1;

	return V;
}

Edge* CreateEdge(Vertex* From, Vertex* Target) {//, int Weight) {
	Edge* E = new Edge();
	E->From = From;
	E->Target = Target;
	E->Next = NULL;
	//E->Weight = Weight;

	return E;
}



void AddEdge(Vertex* V, Edge* E, int Weight) {
	if (V->AdjacencyList == NULL) {
		V->AdjacencyList = E;
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

const int maximum = 1001;
using namespace std;

int* pqueueArray = new int[maximum];
int head, tail;
int maximumVertexData;
int N;

void initQueue() {
	for (int i = 0; i < maximum; i++) { pqueueArray[i] = -1; }
	head = 0; tail = 0;
}

void Enqueue(int value) {
	pqueueArray[tail%maximum] = value;
	tail++;
}
int Dequeue() {

	int forreturn = 0;
	forreturn = pqueueArray[head%maximum];
	pqueueArray[head%maximum] = -1;
	head++;

	return forreturn;
}
Vertex** Ver;
int* pVisited;

void DFS(Vertex* ver) {
	Edge* saveAddress;

	bool swit = true;
	while (swit) {
		swit = false;
		saveAddress = ver->AdjacencyList;
		int minimumEdge = maximumVertexData + 1;
		Edge* minimumEdge_obj = ver->AdjacencyList;


		while (saveAddress) {
			if (saveAddress->Weight < minimumEdge &&saveAddress->Target->Visited != 1) {
				minimumEdge = saveAddress->Weight;
				minimumEdge_obj = saveAddress;
				swit = true;
			}
			if (saveAddress->Next) {
				saveAddress = saveAddress->Next;
			}
			else break; //다음엣지가 존재하지않으면 종료
		}

		if (swit) {
			cout << " " << minimumEdge;
			minimumEdge_obj->Target->Visited = 1;
			for (int i = 0; i < N; i++) {
				if (Ver[i]->Data == minimumEdge) {
					minimumEdge = i;
					break;
				}
			}
			DFS(Ver[minimumEdge]);
		}

	}
}

int main()
{
	int M, V, F, L;

	cin >> N >> M >> V;

	int pvCount = 0;
	int pvInc = 0;
	pVisited = new int[N]; for (int i = 0; i < N; i++) pVisited[i] = -1;//방문초기화
	Ver = new Vertex*[maximum];

	for (int i = 0; i < M; i++) {
		cin >> F >> L;
		if (F > L) {
			if (F > maximumVertexData) maximumVertexData = F;
		}
		else {
			if (L > maximumVertexData) maximumVertexData = L;
		}

		int start, end;
		for (start = 0; start < N; start++) {
			if (pVisited[start] == F) {
				break;
			}
			if (pVisited[start] == -1) {
				pVisited[start] = F;
				Ver[start] = CreateVertex(F);
				break;
			}
		}

		for (end = 0; end < N; end++) {
			if (pVisited[end] == L) {
				break;
			}
			if (pVisited[end] == -1) {
				pVisited[end] = L;
				Ver[end] = CreateVertex(L);
				break;
			}
		}


		AddEdge(Ver[start], CreateEdge(Ver[start], Ver[end]), L);
		AddEdge(Ver[end], CreateEdge(Ver[end], Ver[start]), F);
	}


	////////////////DFS
	int a = V; int i;

	for (i = 0; i < N; i++) {
		if (Ver[i]->Data == V) {
			a = i;
			break;
		}
	}

	if (i != N) {
		cout <<  V;
		Ver[a]->Visited = 1;
		DFS(Ver[a]);
	}


	/////////////////BFS

	initQueue();


	//a값을 가지는 정점찾기
	for (i = 0; i < N; i++) {
		if (Ver[i]->Data == V) {
			a = i;
			break;
		}
	}


	if (i != N) {//V라는 정점이 존재하는경우
		cout << endl<< V;
		Ver[a]->Visited = 2;

		while (a != -1) {


			Edge* saveAddress = NULL;
			Edge* minimumEdge_obj = NULL;
			bool swit = true;

			//weight값이 가장 작은 엣지찾기
			while (swit) {
				swit = false;
				int minimumEdge = maximumVertexData+1;
				Edge* minimumEdge_obj = Ver[a]->AdjacencyList;
				saveAddress = Ver[a]->AdjacencyList;

				while (saveAddress) {
					if (saveAddress->Weight < minimumEdge && saveAddress->Target->Visited == 1) {
						minimumEdge = saveAddress->Weight;
						minimumEdge_obj = saveAddress;
						swit = true;
					}
					if (saveAddress->Next) {
						saveAddress = saveAddress->Next;
					}

					else break; //다음엣지가 존재하지않으면 종료

				}

				if (swit) {
					Enqueue(minimumEdge);
					cout << " " << minimumEdge;
					minimumEdge_obj->Target->Visited = 2;
				}
			}
			a = Dequeue();
			for (i = 0; i < N && a != -1; i++) {
				if (Ver[i]->Data == a) {
					a = i;
					break;
				}
			}

		}
	}

	return 0;
}

