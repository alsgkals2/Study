// SmithNumbers.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
//const int MAXRANGE = 1000000000;
int* primeArray = new int[100001];

//�Ҽ����س���
/*void CulPrime()
{
	int i;
	for (i = 0; i <= 100000; i++)
		primeArray[i] = 0;

	for (i = 2; i <= 100000; i++) {
		if (primeArray[i] == 0)
		{
			primeArray[i] = 2;//�Ҽ���
			for (int j = i + i; j <= 100000; j = j + i)
				primeArray[j] = 1;//�Ҽ��� �ƴϴ�
		}
	}
}*/


int isPrime(int num) {
	if (num == 0 || num == 1) return 0;//�Ҽ��� �ƴϴ�

	for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0) return 0;
	}

	return 1;//�Ҽ��̴�.
}

int SumEachState(int num) {
	int eachSum = 0;

	while (num != 0) {
		eachSum = eachSum + num % 10;
		num = num / 10;
	}

	return eachSum;
}

//���μ�����
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
			//�ռ����� �ɶ����� N�� 1������
			while (isPrime(N))//�Ҽ��̸�
			{
				N++;
			}
			eachSum = SumEachState(N);//�� �ڸ��� �� ���

			//���μ�����
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

