// ACM_9252.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int** dpTable;
stack<char> result;

void solve(string a, string b, int aSize, int bSize)
{
	int i = 0, j = 0;
	
	for (j = 0; j < aSize; j++) {
		for (i = 0; i < bSize; i++)
		{
				if (dpTable[j][i + 1] > dpTable[j+ 1][i])dpTable[j+ 1][i + 1] = dpTable[j][i + 1];
				else dpTable[j+ 1][i + 1] = dpTable[j + 1][i];

				if (a[j] == b[i]) {
					for (int k = i; k < bSize; k++) {
						dpTable[j + 1][k + 1] = dpTable[j + 1][i + 1]+1;
					}
					
					break;
				}
		}
	}

	j = aSize, i = bSize;

	while (j != 0 || i != 0) {
		if ( dpTable[j - 1][i] < dpTable[j][i] && dpTable[j][i - 1] < dpTable[j][i])
		{
			result.push(a[j-1]);
			j--; i--;
		}
		else if (dpTable[j - 1][i] < dpTable[j][i] && dpTable[j][i-1] == dpTable[j][i])
			i--;
		else
			j--;
	}
	

}



int main()
{
	string input1, input2;

	cin >> input1 >> input2;
	int input1Size = input1.size();
	int input2Size = input2.size();

	dpTable = new int*[input1Size+1];
	
	for (int i = 0; i < input1Size+1; i++)
	{
		dpTable[i] = new int[input2Size+1];
		for (int j = 0; j < input2Size+1; j++) {
			dpTable[i][j] = 0;
		}
	}

	solve(input1, input2, input1Size, input2Size);

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		printf("%c", result.top());
		result.pop();
	}

	    return 0;
}

