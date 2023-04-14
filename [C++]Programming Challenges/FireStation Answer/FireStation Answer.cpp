// FireStation Answer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

static int numFire, numI;
static int locFire[501];
static int graph[501][501], graphCost[501][501], graphCn[501];
static int result;

void init(void)
{
	int i, j;

	for (i = 0; i < 500; i++) {
		locFire[i] = 0;
		graphCn[i] = 0;
	}

	for(i=0; i<500; i++)
		for (j = 0; j < 500; j++)
		{
			graph[i][j] = 0;
			graphCost[i][j] = 0;

		}
}

void input(void)
{
	int i;
	int a, b, c;
	char temp[100];

	scanf("%d %d", &numFire, &numI);
	for (i = 0; i < numFire; i++) {
		scanf("%d", &locFire[i]);
		locFire[i]--;
	}

	//gets(temp);

	while (1) {
		temp[0] = 0;
		gets(temp);

		if (temp[0] == '\0') break;
	}


}


int main()
{



    return 0;
}

