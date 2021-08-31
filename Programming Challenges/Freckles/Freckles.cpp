// Freckles.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;


typedef struct Graph{
	double vertex[100][2];
	double edges[100][100];
}G;

bool intree[100];
void init() {
	for (int i = 0; i < 100; i++)
		intree[i] = false;


}


int n = 0;

double solve(G* graph, int start) {
	int minimumV = start;
	static double minimumW[100];
	double addedWeight=0;
	bool con = true;
	intree[start] = true;

	//초반 무게들 갱신
	for (int i = 0; i < n; i++) {
		minimumW[i] = graph->edges[start][i];
	}
	minimumW[0] = 2147483647;

	while (con) {
		con = false;
		
		for (int j = 0; j < n; j++) {
			if (intree[j] == false && start != j && minimumW[j] >= graph->edges[start][j])
			{
				minimumW[j] = graph->edges[start][j];
				if (!con) minimumV = j;
				else if(minimumW[j] < minimumW[minimumV]){
					minimumV = j;
				}

				con = true;
			}
		}

		if (con) {
			intree[minimumV] = true;
			start = minimumV;
			addedWeight += minimumW[minimumV];
		}
	}

	return addedWeight;

}


int main()
{
	double X, Y;
	G* graph = new G();
	int TC;
	cin >> TC;

	while (TC-- != 0) {
		cout << '\n';
		init();

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> graph->vertex[i][0] >> graph->vertex[i][1];
			for (int j = 0; j <= i; j++) {
				if (i != j) {
					graph->edges[j][i] = graph->edges[i][j] = sqrt(pow(graph->vertex[j][0] - graph->vertex[i][0], 2) + pow(graph->vertex[j][1] - graph->vertex[i][1], 2));
				}
			}
		}

		double result = (int)(solve(graph, 0) * 100);
		cout << result / 100 << '\n';
	}

    return 0;
}

