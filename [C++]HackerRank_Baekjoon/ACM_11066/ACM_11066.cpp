// ACM_11066.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

const int INF = 2147483647;
/*
unsigned long long int TestFib(unsigned long long int n, unsigned long long int* fibTable) {//DP
	if (n == 1 || n == 2) return 1;
	if (fibTable[n] != -1)
		return fibTable[n];

	fibTable[n] = TestFib(n - 2, fibTable) + TestFib(n - 1, fibTable);
	return fibTable[n];
}


unsigned long long int TestFib(unsigned long long int n) { //무작정 재귀호출버전
	static unsigned long long int fibTable = 0;

	if (n == 1 || n == 2) return 1;
	//if (fibTable[n] != -1)
		//return fibTable[n];

	fibTable = TestFib(n - 2) + TestFib(n - 1);
	return fibTable;
}
*/
int dpTable[501][501];

void culSum(int* date,int* sum,int n)
{
	for (int i = 0; i <= n; i++) sum[i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			sum[i] += date[j];
		}
	}
}

int solve11066(int* date, int* sum, int p, int q)
{
	if (p == q) return 0;
	if (abs(p - q) == 1) return (date[p] + date[q]);
	if (dpTable[p][q] != INF) return dpTable[p][q];

	for (int i = p; i < q; i++) {
		int v = solve11066(date, sum, p, i) + solve11066(date, sum, i + 1, q) + sum[q] - sum[p - 1];
		dpTable[p][q] = v < dpTable[p][q] ? v : dpTable[p][q];
	}

	return dpTable[p][q];
}


int main()
{
	int n = 0, tc = 0;
	cin >> tc;
	//initialization
	int date[501] = { 0 };
	int sum[501] = { 0 };



	while (tc-- != 0) {
		cin >> n;
	

		for (int i = 0; i <= n; i++) {
			for (int j =0; j <= n; j++) {
				dpTable[i][j] = INF;
			}
		}

		for (int i = 1; i <= n; i++)
			cin >> date[i];


		culSum(date, sum, n);
		cout << solve11066(date, sum, 1, n) << endl;
	}

	//피보나치 테스트

	/*
	unsigned long long int* fib = new unsigned long long int[101];
	for (int i = 0; i < 101; i++) {
		fib[i] = -1;
	}
	fib[1] = 1, fib[2] = 1;

	cout << TestFib(10,fib) << '\n';

	cout << (int)(end.millitm - start.millitm) << '\n';
	*/
	    return 0;
}

