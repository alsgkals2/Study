// SmithNumbers.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
//const int MAXRANGE = 1000000000;
int* primeArray = new int[100001];

//소수구해놓기
/*void CulPrime()
{
	int i;
	for (i = 0; i <= 100000; i++)
		primeArray[i] = 0;

	for (i = 2; i <= 100000; i++) {
		if (primeArray[i] == 0)
		{
			primeArray[i] = 2;//소수다
			for (int j = i + i; j <= 100000; j = j + i)
				primeArray[j] = 1;//소수가 아니다
		}
	}
}*/


int isPrime(int num) {
	if (num == 0 || num == 1) return 0;//소수가 아니다

	for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0) return 0;
	}

	return 1;//소수이다.
}

int SumEachState(int num) {
	int eachSum = 0;

	while (num != 0) {
		eachSum = eachSum + num % 10;
		num = num / 10;
	}

	return eachSum;
}

//소인수분해
void FactorizationOfPrime(int num,int* fopArray) {
	int incIndex = 0;
	int sqrtNum = sqrt(num);
	for (int i = 2; i <= sqrtNum && num != 1; i++) {
	
		while (num%i == 0) {
			fopArray[incIndex++] = i;
			num = num / i;
		}
	}
	if (num > 1) fopArray[incIndex] = num;

}


int main()
{
	int N;
	int eachSum;
	int* fopArray = new int[100];
	int incIndex;

	while(1) {
		cin >> N;
		if (N == 0) {
			delete fopArray;
			break;
		}
		while (1) {
			N = N + 1;
			eachSum = 0;
			//합성수가 될때까지 N값 1씩증가
			while (isPrime(N))//소수이면
			{
				N++;
			}
			eachSum = SumEachState(N);//각 자릿수 합 계산

			//소인수분해
			for (int i = 0; i < 100; i++) fopArray[i] = 0;
			FactorizationOfPrime(N, fopArray);

			incIndex = 0;
			while (fopArray[incIndex] != 0) {

				eachSum = eachSum - SumEachState(fopArray[incIndex]);
				incIndex++;
			}

			if (eachSum == 0) {
				printf("%d\n", N);

				break;
			}
		}
	}
    return 0;
}

