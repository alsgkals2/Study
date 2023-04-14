// Self-describing Sequence.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int i, count, f;
	const int arraysize = 1000000;
	static long sequence[arraysize];
	unsigned long sum,n;

	while (scanf_s("%lu", &n), n != 0) {

		sequence[1] = 1;
		sequence[2] = 2;//2가 2개
		sequence[3] = 2;//3이 2개
		f = 3; count = 3;
		i = 4;
		sum = 5;

		while (sum < n) {
			for (int num = sequence[f]; num > 0; num--) {
				sequence[i] = f;
				sum = sum + f;
				if (sum >= n) break;
				i++;
			}
			f++;
		}
		if (n == 1) i = 1;
		else if (n == 2 || n == 3) i = 2;
		else if (n == 4 || n == 5) i = 3;
		printf("%d\n", i);

	}

    return 0;
}

