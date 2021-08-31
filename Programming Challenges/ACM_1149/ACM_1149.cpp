// ACM_1149.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool** checkAndSum;
int N;

int solve(int num, int sum, int** inputA,int neighborNum) // num : �� A,B,C...
{
	static int result = 2147483647;

	if (num == N) {
		if (result > sum) {
			result = sum;
		}
		
		return -1;
	}
	
		for (int i = 0; i < 3; i++) {
			if (num != 0) {
				if (neighborNum== i) {
					continue;
				}
				else {
					solve(num + 1, sum + inputA[num][i], inputA,i);
				}
			}
			else { // num==0�ΰ��
				solve(num + 1, sum + inputA[num][i], inputA,i);
			}
		}

		return result;
	
}

int** input(int N) {
	int** input = new int*[N];
	for (int i = 0; i < N; i++) {
		input[i] = new int[3];

		for (int j = 0; j < 3; j++)
			cin >> input[i][j];
	}

	return input;

}

int main()
{
	cin >> N;

	int** inputArray;
	inputArray = input(N);

	cout << solve(0, 0, inputArray,-1);

    return 0;
}

