// Light,MoreLight.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
 int divisorNum=0;
 unsigned long long N=0;
unsigned long long devideValue;

void Divisor() {
	//���߿� �غ��� : ������ ���� static�̸�?
	
	unsigned int test1 = N%devideValue;
	unsigned int test2 = N / devideValue;

		if (N%devideValue == 0) {
		if (N / devideValue == devideValue) { divisorNum += 1; return; } //ex) 6���ϱ� 6
		else divisorNum += 2;
	}

	devideValue++;

	if (N /devideValue >= devideValue) {
		Divisor();
	}
}

int main()
{
//	 unsigned int devideValue;

	while (1) {
		cin >> N;
		if (N == 0) break;

		devideValue = 1;
		divisorNum=0;
		Divisor();

		if (divisorNum % 2 == 0) cout << "no" << '\n';
		else cout << "yes" << '\n';
	}

    return 0;
}

