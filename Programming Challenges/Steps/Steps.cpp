// Steps.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int TC = 0;
	int step = 0;
	unsigned int stepSum = 0;
	int stepCM = 0;
	unsigned int firsts, seconds;
	unsigned int distance = 0;

	cin >> TC;

	while (TC-- != 0) {
		cin >> firsts >> seconds;
		distance = seconds - firsts;

		step = 0, stepSum = 0, stepCM = 0;

		while (distance > stepSum) {
			stepCM++;

			step += 2;
			stepSum += stepCM * 2;

		}
		if (stepSum - stepCM >= distance) step--;
		if (distance == 0) step = 0;
		cout << step<<'\n';
	}
    return 0;
}

