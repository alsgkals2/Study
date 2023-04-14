// The tourist Guide.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
 struct graph {
	int linkedVertex[101][101];
	int degree[101];
	int edgeInform[101][101];
	int vertices;

};

void initGraph(graph* g) {

	g->vertices = 0;

	for (int i = 0; i < 101; i++) {
		g->degree[i] = 0;
	}
	/*for (int j = 0; j < 101; j++) {
		for (int i = 0; i < 101; i++) {
			g->linkedVertex[i][j] = 0;
			g->edgeInform[i][j] = 0;
		}
	}*/
}


graph* G;
//int parent[101] = { 0 };
bool discovered[101];
int resultmini = 0;

void dfs(int start, int desti,int minimemEdge) {
	int EdgeValue;
	discovered[start] = true; //방문표시


	if (start == desti) {
		if (minimemEdge > resultmini) resultmini = minimemEdge;
	}
	else {
		for (int i = 0; i < G->degree[start]; i++) {
			
			int Linkedver = G->linkedVertex[start][i];
			if (discovered[Linkedver] == false) {//아직 방문하지않은 상태면
				//parent[Linkedver] = start;

				EdgeValue = G->edgeInform[start][i];
				if (EdgeValue > minimemEdge) EdgeValue = minimemEdge;

				if (EdgeValue > resultmini) { //경로의 모서리최솟값이 이전경로에서 갱신된 resultmini보다 작으면 탐색하지 않아도된다.

					dfs(Linkedver, desti, EdgeValue);
					discovered[Linkedver] = false;
				}
			}
		}
	}
}


int main()
{
	int N, R;//N:도시갯수 R : 도로갯수
	G = new graph();
	int start, destination, people;
	int result;
	int scenarionum = 1;

	for (;;) {
		cin >> N >> R;
		if (N == 0 && R == 0) break;

		initGraph(G);
		//G->vertices = N; //정점갯수

		for (int i = 0; i < R; i++) {
			cin >> start >> destination >> people;

			G->linkedVertex[start][G->degree[start]] = destination;
			G->linkedVertex[destination][G->degree[destination]] = start;

			G->edgeInform[start][G->degree[start]] = people;
			G->edgeInform[destination][G->degree[destination]] = people;

			G->degree[start]++;
			G->degree[destination]++;
		}

		cin >> start >> destination >> people;
		dfs(start, destination, 2147483647);
		if (people % (resultmini - 1) != 0) result = 1;
		else result = 0;
		result += (people / (resultmini - 1));
		cout << "Scenario #" << scenarionum++ << '\n';
		cout << "Minimum Number of Trips = " << result << '\n' << '\n';
	}
    return 0;
}
