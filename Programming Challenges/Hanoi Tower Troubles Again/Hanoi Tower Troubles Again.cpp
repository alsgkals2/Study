// Hanoi Tower Troubles Again.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	scanf_s("%d", &t); //�׽�Ʈ���̽�
	for (i = 0; i < t; i++) {
		scanf_s("%d", &n);//��հ���

		printf("%d\n", solve(n));
	}

    return 0;
}

