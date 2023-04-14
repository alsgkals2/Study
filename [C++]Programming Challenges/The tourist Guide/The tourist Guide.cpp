// The tourist Guide.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	discovered[start] = true; //�湮ǥ��


	if (start == desti) {
		if (minimemEdge > resultmini) resultmini = minimemEdge;
	}
	else {
		for (int i = 0; i < G->degree[start]; i++) {
			
			int Linkedver = G->linkedVertex[start][i];
			if (discovered[Linkedver] == false) {//���� �湮�������� ���¸�
				//parent[Linkedver] = start;

				EdgeValue = G->edgeInform[start][i];
				if (EdgeValue > minimemEdge) EdgeValue = minimemEdge;

				if (EdgeValue > resultmini) { //����� �𼭸��ּڰ��� ������ο��� ���ŵ� resultmini���� ������ Ž������ �ʾƵ��ȴ�.

					dfs(Linkedver, desti, EdgeValue);
					discovered[Linkedver] = false;
				}
			}
		}
	}
}


int main()
{
	int N, R;//N:���ð��� R : ���ΰ���
	G = new graph();
	int start, destination, people;
	int result;
	int scenarionum = 1;

	for (;;) {
		cin >> N >> R;
		if (N == 0 && R == 0) break;

		initGraph(G);
		//G->vertices = N; //��������

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
