// Carmichael Numbers.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
const int MAXNUM = 65000;
//소수, 합동수 검사용
void ForCheckPrime(int* informPrime) {
	int i, j;
	for (i = 0; i < MAXNUM; i++) {
		informPrime[i] = 0;
	}

	for (i = 2; i < MAXNUM; i++) {
		if (informPrime[i] == 0) {
			informPrime[i] = 2;

			for (j = i + i; j < MAXNUM; j = j + i) {
				informPrime[j] = 1;
			}
		}
	}

}

unsigned long powmod(unsigned long a, int b, int n) {
	unsigned long temp;

	if (b == 0) return 1;
	if (b == 1) return a;

	if (b % 2) return (powmod(a, b - 1, n)*a) % n;
	else {
		temp = powmod(a, b / 2, n);
		return (temp*temp) % n;
	}

}

int fermattest(int a, int n) {
	return (powmod(a, n, n) == a);
}

int main()
{
	int* informPrime = new int[MAXNUM];
	int i, j;
	int n;
	ForCheckPrime(informPrime);

	for (i = 3; i < MAXNUM; i++)
	{
		if (informPrime[i] == 1) {
			for (j = 2; j < i; j++) {
				if (!fermattest(j, i)) {
					informPrime[i] = 0;
					break;
				}
			}
		}
		else
			informPrime[i] = 0;
	}

	while (scanf_s("%d", &n), n != 0) {
		if (informPrime[n])
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
	}

    return 0;
}

