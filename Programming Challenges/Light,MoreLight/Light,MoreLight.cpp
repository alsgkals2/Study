// Light,MoreLight.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
 int divisorNum=0;
 unsigned long long N=0;
unsigned long long devideValue;

void Divisor() {
	//나중에 해보기 : 나누는 값이 static이면?
	
	unsigned int test1 = N%devideValue;
	unsigned int test2 = N / devideValue;

		if (N%devideValue == 0) {
		if (N / devideValue == devideValue) { divisorNum += 1; return; } //ex) 6곱하기 6
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

