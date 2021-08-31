// LittleBishops.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

unsigned long long Allcase = 0;
bool forStopBT = false;
short beforCount = 0;

typedef struct Bignum {
	char bignum[17];
	int lastindex = 0;
};

void addOneBignum(Bignum *a, Bignum *b)
{
	int i;
	Bignum *c = new Bignum();
	int carry = 0;
	c->lastindex = a->lastindex > b->lastindex ? a->lastindex + 1 : b->lastindex + 1;

	for (i = 0; i < c->lastindex; i++) {
		c->bignum[i] = (char)(a->bignum[i] + b->bignum[i] + carry)%10;
		carry = (a->bignum[i] + b->bignum[i] + carry) / 10;
	}

	while (c->lastindex > 0 && c->bignum[c->lastindex - 1] == 0) c->lastindex--;

	for (i = 0; i < c->lastindex; i++) b->bignum[i] = c->bignum[i];
	b->lastindex = c->lastindex;

}


void BackTracking(int& N,int& k, int count,short* board,short xIndex,short yIndex, Bignum* one, Bignum* result) {
	//1 시작점 3 상향 5 하향
	short * copyBoard = new short[N];
	for (int i = 0; i < N; i++) copyBoard[i] = board[i];

	if (count == k)
	{
		addOneBignum(one, result);
		//Allcase++;
		delete copyBoard;
	}
	else {
		if (yIndex != -1) {
			copyBoard[yIndex] = 1;
		}


		while (xIndex < N) {
			while (yIndex < N - 1) {
				yIndex += 1;
				if (copyBoard[yIndex] == 0) {
					beforCount = count;
					BackTracking(N, k, count + 1, copyBoard, xIndex, yIndex,one,result);//작은비숍은 대각선에만 작용하므로 직선방향으론 제약받지않음.
				}
				if (forStopBT) {
					delete copyBoard;
					return;
				}
			}

			yIndex = -1; xIndex++;//얘증가할대 1도 상향,하향으로 나누기.
			short * copyofcopyBoard = new short[N];
			for (int i = 0; i < N; i++) copyofcopyBoard[i] = 0;

			for (int i = 0; i < N; i++) {
				if (copyBoard[i] == 1 || copyBoard[i] == 4 || copyBoard[i] == 8 || copyBoard[i] == 6)
				{
					if (i - 1 >= 0) copyofcopyBoard[i - 1] += 3;
					if (i + 1 < N) copyofcopyBoard[i + 1] += 5;
					continue;
				}
				else if (copyBoard[i] == 3)
				{
					if (i - 1 >= 0) copyofcopyBoard[i - 1] += 3;
					continue;
				}
				else if (copyBoard[i] == 5) {
					if (i + 1 < N) copyofcopyBoard[i + 1] += 5;
					continue;
				}
			}

			for (int i = 0; i < N; i++) copyBoard[i] = copyofcopyBoard[i];//다시 copyboard에 복사
			delete copyofcopyBoard;
		}
		delete copyBoard;

			if (beforCount == count && result->lastindex == 0) //ALLCASE가 변동없는경우
			forStopBT = true;
	}

}

int main()
{
	int N=0, K=0;
	short * board = new short[N];
	Bignum *one = new Bignum();
	Bignum *result = new Bignum();
	for (int i = 0; i < 17; i++) {
		one->bignum[i] = 0;
	}

	one->bignum[0] = 1;
	one->lastindex = 1;
	
	

	while (1) {

		cin >> N >> K;
		if (N == 0 && K == 0) break;
		forStopBT = false;
		Allcase = 0;
		for (int i = 0; i < N; i++) board[i] = 0;
		for (int i = 0; i < 17; i++)
			result->bignum[i] = 0;
		result->lastindex = 0;

		BackTracking(N, K, 0, board, 0, -1,one,result);
		if (forStopBT)
			cout << 0;
		else
			for(int i=result->lastindex-1; i>=0; i--)
				printf("%d",result->bignum[i]);
		
		cout << '\n';
	}

	delete board;
	return 0;
}

