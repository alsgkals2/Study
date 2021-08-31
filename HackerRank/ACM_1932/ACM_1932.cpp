// ACM_1932.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int* inputTri(int n) {
	
	int arraySize = n*((n + 1)) / 2 + 1;

	int* tri = new int[arraySize];

	for (int i = 1; i < arraySize; i++) {
		cin >> tri[i];
	}
	
	return tri;
}

void Solve(int* tri, int lfIndex,int n) {
	for (int range = lfIndex; range > lfIndex - n + 1; range--) { // ������� 12~15��������(range-1������ 12����)
		int parentIndex = range - (n);
		if (tri[range] + tri[parentIndex] >= tri[range - 1] + tri[parentIndex])
		{
			tri[parentIndex] = tri[range] + tri[parentIndex]; //�޸������̼�
		}
		else
			tri[parentIndex] = tri[range -1] + tri[parentIndex]; //�޸������̼�
	}

	if (n == 2) return;
	Solve(tri, lfIndex - n, n - 1);
}

int main()
{
	int n;
	cin >> n;//�ﰢ�� ũ��
	int* tri;
	tri = inputTri(n);
	int lastFirstIndex = (n * (n + 1)) / 2;
	Solve(tri, lastFirstIndex, n);
	cout << tri[1] << endl;

    return 0;
}

