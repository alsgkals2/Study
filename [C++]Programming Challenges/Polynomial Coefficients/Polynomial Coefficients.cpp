// Polynomial Coefficients.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	unsigned long k = 0, n=0;
	int a = 0;

	while (scanf("%d", &n) == 1) {
		scanf("%lu", &k);
	
		int underValue = 1;
		for (int i = 0; i < k; i++) {
			scanf("%d", &a);

			for (int u = 2; u <= a; u++) {
				underValue = underValue *u;
			}
		}
		int result = 1;
		for (int i = n; i >= 1; i--) {
			result = result*i;
		}

		printf("%d\n", result/underValue);
	}

    return 0;

}

