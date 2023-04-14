// Marbles.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//최대 공약수 구하기
int gcd(int marble1, int marble2) {

	if (marble2 > marble1) {
		int	temp = marble1;
		marble1 = marble2;
		marble2 = temp;
	}

	if (marble2 == 0) return marble1;

	return gcd(marble2, marble1%marble2);
}


bool JudgeDivisor(int marbleNum, int divisorNum) {//divisor은 두 구슬의 최대공약수
	//return true:약수에 수가 존재
	//false:약수에 수가 존재x

	for (int i = 1; i <= sqrt(marbleNum); i++) {
		if (marbleNum%i == 0) {
			if (i == divisorNum) return true;
			if (marbleNum / i == divisorNum) return true;
		}
	}

	return false;
}

int CulBoxNum(int marble1,int marbleNum0) {
	return (marbleNum0 / marble1);
}

void SolveIf_1(int marbleNum0, int daller1,int marble1,int daller2, int marble2) {

	int boxNumofMarble1 = 0;
	bool changeSw = false;
	int forDecMarble1 = 0;
	int vaildMarble1Num = 0; //최대치의 marble1구슬부터 조금씩줄여나가면서 적절한해를 찾기위한변수
	//효율성높은애를 마블1,달러1로 지정
	if ((double)marble1 / (double)daller1 < (double)marble2 / (double)daller2) {
		int tempMarble = marble1;
		int tempDaller = daller1;
		marble1 = marble2;
		daller1 = daller2;
		marble2 = tempMarble;
		daller2 = tempDaller;
		changeSw = true;
	}

	boxNumofMarble1 = CulBoxNum(marble1, marbleNum0);
	vaildMarble1Num = (marble1*boxNumofMarble1);


	while (vaildMarble1Num >= 0) {
		if ((marbleNum0 - vaildMarble1Num) % marble2 == 0)
		{
			if (changeSw) {
				printf("%d %d\n", (marbleNum0- vaildMarble1Num) / marble2, boxNumofMarble1);
				return;
			}
			else {
				printf("%d %d\n", boxNumofMarble1, (marbleNum0 - vaildMarble1Num) / marble2);
				return;
			}
		}
		else {
			boxNumofMarble1--;
			vaildMarble1Num = marble1 * boxNumofMarble1;
		}
	}

	printf("failed");
}



int main()
{
	int marbleNum0;
	int daller1, marble1;
	int daller2, marble2;
	int maxDivorse = 0;


	while (1) {
		cin >> marbleNum0;
		if (marbleNum0 == 0) break;
		cin >> daller1 >> marble1;
		cin >> daller2 >> marble2;

		maxDivorse = gcd(marble1, marble2);

		if (!JudgeDivisor(marbleNum0, maxDivorse))printf("failed\n"); //해존재 안하는경우

		else if (marble1 <= marbleNum0 && marble2 <= marbleNum0) {
			SolveIf_1(marbleNum0, daller1, marble1, daller2, marble2);
		}
		//하나의 마블만 갯수가 작거나 같은경우
		else if (marble1 <= marbleNum0) {
			if (marbleNum0 % marble1 == 0)
				printf("%d %d\n", marbleNum0 / marble1, 0);
			else
				printf("failed\n");
		}
		else if (marble2 <= marbleNum0) {
			if (marbleNum0 % marble2 == 0)
				printf("%d %d\n", 0, marbleNum0 / marble2);
			else
				printf("failed\n");
		}
	}

    return 0;
}

