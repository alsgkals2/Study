// A Multiplication Game.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
bool BandArray(int* saveA,int maxIndex) {
	bool swit = false;
	int tied = 1;

	for (int i = 0; i < maxIndex; i++) {
		tied = tied * saveA[i];

		if (tied > 9) {
			tied = saveA[i];

			if (swit) swit = false;
			else { swit = true; }//true:stan
		}
		if (i == maxIndex - 1) {
			if (swit) swit = false;
			else { swit = true; }//true:stan
		}
	}

	return swit;
}
*/
int main()
{
	unsigned long long n;
	bool so = false;

	while (scanf("%llu", &n) == 1) {
		int a = 9;
		unsigned long long value = 1;
		so = false;

		while (1) {
			if (value*a <= n) {
				value = value*a;
				if (so) so = false;
				else { so = true; }

				if (n == value) break;

				a = 9;
			}
			else if (value * 9 > n) {
				if (so) so = false;
				else {
					so = true;
				}
				break;
			}

			else if (a == 2) {
				if (so) so = false;
				else { so = true; }
				break;
			}
			else if (a > 2) { a--; }
		}
		break;
	}

		if (so) printf("%s\n", "Stan wins."); //Baekjoon
		else { printf("%s\n", "Ollie wins."); }//Donghyuk
	

    return 0;
}

