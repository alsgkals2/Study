// Necklace.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int** input = new int*[1000];
int colorNum[51];
int result[1000][2];
bool check[1000];
int n;
bool finished = false;
void dfs(int index, int count, int direction) {

	result[count-1][0] = input[index][direction%2];
	result[count-1][1] = input[index][(direction+1)%2];

	if (count == n && input[index][direction] == input[0][0]) //목걸이 다 끼운경우
	{
		finished = true;
	}

	else {
		for (int i = 1; i < n; i++) {
			if (check[i] == true) continue;
			for (int j = 0; j < 2; j++) {
				if (input[i][j] == input[index][(direction+1)%2]) {

					check[i] = true;
					dfs(i, count + 1, j);
					//check[i] = false;
					
					if (finished) return;
					
				}
			}
		}
	}
}



int main()
{
	int i;
	int tc;
	cin >> tc;
	for (i = 0; i < 1000; i++) {
		input[i] = new int[2];
	}

	for (int t = 1; t <= tc; t++) {
		cin >> n;
		if (n == 0) continue;
		finished = false;
		for (i = 0; i < 1000; i++) {
			input[i][0] = 0;
			input[i][1] = 0;
			check[i] = false;
		}

		for (i = 0; i < 51; i++) {
			colorNum[i] = 0;
		}

		for (i = 0; i < n; i++) {
			cin>>input[i][0]>>input[i][1];
			colorNum[input[i][0]]++;
			colorNum[input[i][1]]++;
		}
	
		for (i = 1; i < 51; i++) {
			if (colorNum[i] % 2 == 1) {
				cout << "Case #" << t << '\n';
				cout << "Some beads may be lost" << '\n';
				break;
			}
		}

		if (i == 51) {//오일러 사이클인경우
			check[0] = true;
			dfs(0, 1, 0);

			cout << "Case #" << t << '\n';
			for (int i = 0; i < n; i++) {
				cout << result[i][0] << " " << result[i][1] << '\n';
			}
		}
	
		cout << '\n';
	}


	return 0;
}