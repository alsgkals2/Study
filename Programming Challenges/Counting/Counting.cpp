// Counting.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct bignum{
	char num[1000];
	int lastIndex;
};

void initBignumStruct(bignum &c) {
	for (int i = 0; i < 1000; i++) {
		c.num[i] = -1;
	}
	c.lastIndex = 1;
}

void add(bignum &a, bignum &b, bignum &c) {
	int carry = 0;
	initBignumStruct(c);

	c.lastIndex = a.lastIndex > b.lastIndex ? a.lastIndex + 1 : b.lastIndex + 1;

	for (int i = 0; i < c.lastIndex; i++) {
		if (a.num[i] < 0 || a.num[i] >9) a.num[i] = 0;
		if (b.num[i] < 0 || b.num[i] >9) b.num[i] = 0;

		c.num[i] = (carry + a.num[i] + b.num[i]) % 10;
		carry = (a.num[i] + b.num[i]) / 10;
	}

	while (c.lastIndex > 0 && c.num[c.lastIndex - 1] == 0) c.lastIndex--;
}

void CInitializing(bignum* c) {
	initBignumStruct(c[0]);
	initBignumStruct(c[1]);
	initBignumStruct(c[2]);
	c[0].num[0] = 2;
	c[1].num[0] = 5;
	c[2].num[0] = 3;
	c[2].num[1] = 1;
	c[2].lastIndex = 2;
}

void printNum(bignum& c) {
	for (int i = c.lastIndex - 1; i >= 0; i--) {
		printf("%c", '0' + c.num[i]);
	}
	printf("\n");
}

int main()
{
	int N = 0;
	while (scanf_s("%d", &N) !=EOF) {
		bignum C[4];
		bignum forAddLeft, forAddRight;
		CInitializing(C);

		for (int n = 3; n <= N - 1; n++)
		{
			add(C[(n - 1) % 4], C[(n - 1) % 4], forAddLeft);
			add(C[(n - 2) % 4], C[(n - 3) % 4], forAddRight);
			add(forAddLeft, forAddRight, C[(n) % 4]);
		}

		printNum(C[(N - 1) % 4]);
	}
    return 0;
}

