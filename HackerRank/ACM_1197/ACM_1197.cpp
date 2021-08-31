// ACM_1197.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct edge {
	int v =- 1;
	int weight = 0;
	edge* nextE = NULL;
}Edge;

int MST(Edge** E, int V) {

	int startV;
	int sum;
	int* distance = new int[V+1];
	bool* check = new bool[V+1];
	Edge* p;

	//초기화
	for (int v = 0; v < V+1; v++) {
		distance[v] = 2147483647;
		check[v] = false;
	}

	//
	sum = 0;
	startV = 1;


	while (startV != -1) {
		check[startV] = true;
		p = E[startV];

		while (p != NULL && p->v != -1) {
			if (check[p->v] == false && p->weight < distance[p->v]) {
				distance[p->v] = p->weight;
			}
			p = p->nextE;
		}

		//가장 거리가 가까운 애들 탐색
		startV = -1;
		for (int v = 1; v < V + 1; v++)
		{
			if (check[v] == false && (startV == -1 || distance[v] < distance[startV])) {
				startV = v;
			}
		}

	}


	for (int v = 2; v < V + 1; v++)
	{
		sum += distance[v];
	}

	return sum;
}


int main()
{
	//V=정점의 갯수 , E=간선의 갯수
	int V, E;
	int A, B, C;
	cin >> V >> E;
	Edge** g = new Edge*[V+1]; //첫번째 엣지포인터
	Edge** lastE = new Edge*[V + 1];//마지막 엣지포인터

	for (int v = 0; v < V+1; v++) {

		g[v] = NULL;
		lastE[v] = new Edge();
	}

	for (int e = 0; e < E; e++) {
		cin >> A >> B >> C;

		if (g[A] == NULL) {
			g[A] = new Edge();
			g[A]->v = B;
			g[A]->weight = C;
			g[A]->nextE = new Edge();
			lastE[A] = g[A]->nextE;
		}
		else {
			lastE[A]->v = B;
			lastE[A]->weight = C;
			lastE[A]->nextE = new Edge();
			lastE[A] = lastE[A]->nextE;
		}

		if (g[B] ==NULL) {
			g[B] = new Edge();
			g[B]->v = A;
			g[B]->weight = C;
			g[B]->nextE = new Edge();
			lastE[B] = g[B]->nextE;
		}
		else {
			lastE[B]->v = B;
			lastE[B]->weight = C;
			lastE[B]->nextE = new Edge();
			lastE[B] = lastE[B]->nextE;
		}
	}

	cout<<MST(g, V);


    return 0;
}

