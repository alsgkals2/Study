// Summation of Four Prime.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

const int MAXINDEX = 10000000;
int N = 0;
int *Prime;

//�Ҽ����س���
void CulPrime() {

	Prime[0] = Prime[1] = 1;

	for (int i = 2; i < MAXINDEX+1; i++) {
		if (Prime[i] == 0)
		{
			Prime[i] = 2;//2:�Ҽ�
			for (int j = i + i; j < MAXINDEX + 1; j = j + i)
				Prime[j] = 1; // 1:�ռ���
		}
	}

}

 bool continueCul = false;
bool CulFourPrime(int N,int startRange,int* saveFourPrime)
{

	startRange--;
	//saveFourPrime�� �ε����� startrange
	if (startRange != 0) {
		for (int i = 2; i <= N - (startRange * 2) && !continueCul; i++) {
			if (Prime[i] == 2) {
				saveFourPrime[startRange] = i;
				if (CulFourPrime(N - i, startRange, saveFourPrime)) return true;
			}
		}
	}
	else {//startrange�� 0�ΰ��
		if (Prime[N] == 2) {
			saveFourPrime[startRange] = N;
			continueCul = true;
			return true;
			//return saveFourPrime;
		}
	}

	return false;
}

int main()
{
	int startRange;
	int i;
	int* saveFourPrime;
	Prime = new int[MAXINDEX + 1];
	for (i = 0; i < MAXINDEX + 1; i++) Prime[i] = 0;
	//CulPrime();

	cin >> N;
	saveFourPrime = new int[4];
	for (i = 0; i < 4; i++) saveFourPrime[i] = 0;

	startRange = 4;

	continueCul = false;
	if (CulFourPrime(N, startRange, saveFourPrime)) {
		for (i = 0; i < 4; i++)
			printf("%d ", saveFourPrime[i]);
	}
	else printf("-1");

	delete saveFourPrime;

    return 0;
}

