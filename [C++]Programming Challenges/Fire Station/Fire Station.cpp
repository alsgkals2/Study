// Fire Station.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>


using namespace std;


typedef struct edge {
	int v;
	int weight;
}edge;

typedef struct graph {
	int vertexNum;
	edge verEdge[501][501];
	int degree[501];
}graph;

void init(graph *g) {

	g->vertexNum = 0;
	for (int i = 0; i < 501; i++) {
		g->degree[i] = 0;
	}

}
int fireState[501];
int crossNum;

int CulForMinimum(graph* G, int start) {
	int i, j;
	static bool intree[501]; //순서대로 대입
	static int distance[501]; //정점인덱스에 대입
	int v, w;
	int dist;
	int MAXd;
	bool con = true;

	for (i = 0; i <= crossNum; i++) {
		distance[i] = 2147483647;//초기화
		intree[i] = true;
	}

	int maxDistance = -1;
	distance[start] = 0;
	v = start;

	while (con) {
		intree[v] = false;
		con = false;

		for (i = 0; i < G->degree[v]; i++) {
			
			w = G->verEdge[v][i].v;

			if (intree[w] && distance[w] > distance[v] + G->verEdge[v][i].weight) {
				distance[w] = distance[v] + G->verEdge[v][i].weight;
			}
		}

		MAXd = 2147483647;
		int nextIndex;
		for (int f = 0; f < crossNum; f++) {
			if (distance[f] < MAXd && intree[f]) {
				MAXd = distance[f];
				v = f;
				con = true;
			}
		}
	}

	return maxDistance;
}

int main()
{
	int TC;
	int fireNum;
	int i;
	int state;
	graph* G = new graph();
	int input1, input2, inputD;
	int resultIndex;
	int maxD[501];
	cin >> TC;

	while (TC-- != 0) {
		for (i = 0; i < 501; i++) {
			fireState[i] = 0;
		}

		cin >> fireNum >> crossNum;


		for (i = 0; i < crossNum; i++) {
			G->degree[i] = 0;
		}


		for (i = 0; i < fireNum; i++) {
			cin >> state;
			fireState[state] = 1;//위치 체크
		}

		for (i = 0; i < crossNum; i++) {
			cin >> input1 >> input2 >> inputD;

			G->verEdge[input1][G->degree[input1]].v = input2;
			G->verEdge[input1][G->degree[input1]].weight = inputD;
			G->degree[input1]++;

			G->verEdge[input2][G->degree[input2]].v = input1;
			G->verEdge[input2][G->degree[input2]].weight = inputD;
			G->degree[input2]++;
		}


		//각 정점마다 소방서 배치하고, 배치했을 경우의 모든정점에 대해서 최단거리 계산
		for (i = 1; i <= crossNum; i++) {
			maxD[i] = -1;

			if (fireState[i] != 1) {
				fireState[i] = 1;
				for (int j = 1; j <= crossNum; j++) {
					if (fireState[j] == 1) continue;

					int r = CulForMinimum(G, j);
					if (r > maxD[i])
					{
						maxD[i] = r;
					}
				}

				fireState[i] = 0;
			}
		}

		int minD = 2147483647;
		for (i = 1; i <= crossNum; i++) {
			if (minD > maxD[i] && fireState[i] != 1) {
				resultIndex = i;
				minD = maxD[i];
			}
		}

		cout << resultIndex << '\n' << '\n';
	}

    return 0;
}

