// ACM_1932.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	for (int range = lfIndex; range > lfIndex - n + 1; range--) { // 예를들어 12~15범위까지(range-1때문에 12까지)
		int parentIndex = range - (n);
		if (tri[range] + tri[parentIndex] >= tri[range - 1] + tri[parentIndex])
		{
			tri[parentIndex] = tri[range] + tri[parentIndex]; //메모이제이션
		}
		else
			tri[parentIndex] = tri[range -1] + tri[parentIndex]; //메모이제이션
	}

	if (n == 2) return;
	Solve(tri, lfIndex - n, n - 1);
}

int main()
{
	int n;
	cin >> n;//삼각형 크기
	int* tri;
	tri = inputTri(n);
	int lastFirstIndex = (n * (n + 1)) / 2;
	Solve(tri, lastFirstIndex, n);
	cout << tri[1] << endl;

    return 0;
}

