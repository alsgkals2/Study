// Hanoi Tower Troubles Again.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int solve(int n)
{
	int f = 1;
	int a = 2;

	for (int i = 2; i <= n; i++) {
		f = f + a;

		if(i%2==0)
			a = a + 2;

	}

	return f;

}

int main()
{

	int i, j, n, t;

	scanf_s("%d", &t); //테스트케이스
	for (i = 0; i < t; i++) {
		scanf_s("%d", &n);//기둥갯수

		printf("%d\n", solve(n));
	}

    return 0;
}

