// ACM_10159.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int arr[100][100];
int V, m;
/*void floyd()
{
	for (int i = 1; i <= V; ++i) arr[i][i] = 0;

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (arr[i][k] == 1 && arr[k][j] == 1)
					arr[i][j] = 1;
			}
		}
	}
}
int main()
{
	cin >> V >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	floyd();

	int cnt;
	for (int i = 1; i <= V; i++)
	{
		cnt = 0;
		for (int j = 1; j <= V; j++)
		{
			if (!arr[i][j] && !arr[j][i])
				cnt++;
		}
		printf("%d\n", cnt - 1);
	}
}


*/


int main()
{
	bool ar[101][101];
	bool checkLinked[101][101];
	int outputNum[100];
	int N, M;
	int f, s;
	int i, j = 1;

	cin >> N >> M;

	for (i = 1; i <= N; i++) {
		outputNum[i-1] = 0;
		for (j = 1; j <= N; j++) {
			
			ar[i][j] = false;
			
		}
	}

	for (int m = 0; m < M; m++) {
		cin >> f >> s;
		ar[f][s] = true;
	}

	for (i = 1; i <= N; i++) {
		ar[i][i] = false;

		for (int s = 1; s <= N; s++) {

			for (j = 1; j <= N; j++) {
				if (ar[s][i] == true && ar[i][j] == true) {
					ar[s][j] = true;
				}
			}
		}
	}


	for (i = 1; i <= N; i++) {
		ar[i][i] = true;
		for (j = 1; j <= N; j++) {
			if (ar[i][j] == false && ar[j][i]==false)
				outputNum[i - 1]++ ;
		}
	}

	for (i = 0; i < N; i++) {
		cout << outputNum[i] << '\n';
	}

		return 0;
}






