// 줄queuee.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

long combi(int n, int r)//nCr
{
	int i; long t = 1;

	for (i = r + 1; i <= n; i++) t *= i;
	for (i = 1; i <= n - r; i++) t /= i;

	return t;
}

long perm(int n)
{
	long i, t = 1;
	for (i = 1; i <= n; i++) t *= i;

	return t;
}

long visit(int n, int k, int s, int x, int y)
{
	int i;
	long t = 0;

	if (k == 0) {
		if (n == 0) return 1;
		else return 0;
}
	if (s == 0) //왼
		for (i = x + k - 1; i < y; i++)
			t += visit(i - x, k - 1, 0, x, i) * combi(n - 1, i - x) * perm(y - i - 1);
	else
		for (i = x; i < y - k + 1; i++)
			t += visit(n - (i - x) - 1, k - 1, 1, i + 1, y) * combi(n - 1, i - x) * perm(i - x);

	return t;


}


int main()
{
	int tn, ti, n, p, r, i;
	long t;

	scanf_s("%d", &tn);
	
	for (ti = 0; ti < tn; ti++) {
		t = 0;
		scanf_s("%d %d %d", &n, &p, &r);

		for (i = p - 1; i < n - r + 1; i++)
			t += visit(i, p - 1, 0, 0, i) * visit(n - i - 1, r - 1, 1, i + 1, n) * combi(n - 1, i);

		printf("%ld\n", t);
	}
    return 0;
}

