// The Priest Mathematician.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;


typedef struct bignum {
	char num[1000];
	int lastIndex = 0;
}bignum;
bignum* saveTwo;
bignum* saveFourInform;


void add_bignum(bignum *a, bignum *b, bignum *c) {
	int carry=0;
	c->lastIndex = a->lastIndex > b->lastIndex ? a->lastIndex + 1 : b->lastIndex + 1;

	for (int i = 0; i < c->lastIndex; i++) {
		if (a->num[i] < 0 || a->num[i] >9) a->num[i] = 0;
		if (b->num[i] < 0 || b->num[i] >9) b->num[i] = 0;

		c->num[i] = (carry + a->num[i] + b->num[i]) % 10;
		carry = (carry+a->num[i] + b->num[i]) / 10;
	}

	while (c->lastIndex > 0 && c->num[c->lastIndex - 1] == 0) c->lastIndex--;
}

void digit_shift(bignum *n, int d) {
	int i;

	if ((n->lastIndex == 0) && n->num[0] == 0) return;

	for (i = n->lastIndex; i >= 0; i--)
		n->num[i + d] = n->num[i];

	for (i = 0; i < d; i++) n->num[i] = 0;
	n->lastIndex = n->lastIndex + d;
}

void multiply_bignum(bignum*a, bignum *b, bignum *c) {
	bignum row;
	bignum tmp;
	int i, j;

	for (int i = 0; i < 1000; i++) c->num[i] = 0;
	row = *a;

	for (i = 0; i <= b->lastIndex; i++) {
		for (j = 1; j <= b->num[i]; j++) {
			add_bignum(c, &row, &tmp);
			*c = tmp;
		}
		digit_shift(&row, 1);
	}
}

void numInformSave(bignum *c, bignum& saveTwo) {

	for (int i = 0; i < c->lastIndex; i++) {
		saveTwo.num[i] = c->num[i];
	}
}

//빼기
void substract_bignum(bignum *a, bignum *b, bignum *c) {
	int borrow;
	int v, i;

	if (a->lastIndex > b->lastIndex) {
		for (i = b->lastIndex; i < a->lastIndex; i++) {
			b->num[i] = 0;
		}
		c->lastIndex = a->lastIndex + 1;
	}
	else {
		for (i = a->lastIndex; i < b->lastIndex; i++) {
			a->num[i] = 0;
		}
		c->lastIndex = b->lastIndex + 1;
	}

	borrow = 0;

	for (i = 0; i < c->lastIndex; i++) {
		if (a->num[i] < 0 || a->num[i] >9) a->num[i] = 0;
		if (b->num[i] < 0 || b->num[i] >9) b->num[i] = 0;

		v = a->num[i] - borrow - b->num[i];
		if (a->num[i] > 0) borrow = 0;
		if (v < 0) {
			v = v + 10;
			borrow = 1;
		}
		c->num[i] = (char)v % 10;
	}

	while (c->lastIndex > 0 && c->num[c->lastIndex - 1] == 0) c->lastIndex--;
}
void initBignum(bignum *bignum) {
	for (int i = 0; i < 1000; i++) bignum->num[i] = 0;
}
const int b[10000] = { 0,1,3,5 };
void saveTwoMul() {
	int index = 0;
	bignum * a = new bignum() , *b = new bignum() , *c = new bignum();
	bignum forMOne; //1
	bignum *forTwo_1=new bignum();
	bignum *forTwo = new bignum();
	saveTwo = new bignum[10001];

	initBignum(a);
	initBignum(b);
	initBignum(c);
	forTwo->num[0] = 1;
	forTwo->lastIndex = 1;
	b->num[0] = 2;
	b->lastIndex = 1;
	forMOne.lastIndex = 1;
	forMOne.num[0] = 1;

	while (++index != 10001) {
		multiply_bignum(forTwo, b, forTwo_1);
		*forTwo = *forTwo_1;//다음인덱스에서 그전의값에 2를곱하기 위해
		substract_bignum(forTwo_1, &forMOne, &saveTwo[index]); // C(i-k,3)
		//saveTwo[index] = *c;
		//numInformSave(c, saveTwo[index]);
	}


}

int Compare(bignum& max, bignum& compared) {
	if (max.lastIndex > compared.lastIndex) return 1;//max 숫자가 더 크다. =>compared가 더 작다
	else if (max.lastIndex < compared.lastIndex) return 2;//compared가 더 크다 =>max가 더 작다
	
	//숫자갯수 같은경우

	for (int i = max.lastIndex - 1; i >= 0; i--) {
		if (max.num[i] > compared.num[i]) return 1;
		else if (max.num[i] < compared.num[i]) return 2;
	}

	return 1; //모두 일치하는경우
}

void printBignum(bignum& minNum) {


	for (int i = minNum.lastIndex-1; i >=0; i--) {
		printf("%c", minNum.num[i] + '0');
	}
	printf("\n");
}

void initFourInform() {
	saveFourInform = new bignum[10001];
	saveFourInform[0].lastIndex = 1;
	saveFourInform[0].num[0] = 0;
	saveFourInform[1].lastIndex = 1;
	saveFourInform[1].num[0] = 1;
}
void Hanoi4(int maxN,int N) {
	bignum twoi_k;//2의 i-k승정보
	bignum resultLeft;
	bignum resultRight; int rightResultInt = 0;
	bignum minResult;
	//bignum* finalResult = new bignum[10001];

	bignum* finalResult;
	//-1하기위한 구조체, 변동없음
	bignum forMOne; //1

	int k;
	for (int max = maxN+1; max <= N; max++) {
		finalResult = new bignum[max-1]; //min값을구하기위한 후보결과값들 저장

		for (k = 1; k < max; k++) {
			//초기화
			twoi_k.lastIndex = 0;
			initBignum(&twoi_k);
			resultRight.lastIndex = 0;
			initBignum(&resultRight);

			//우측계산(2C(k,4))
			add_bignum(&saveFourInform[k], &saveFourInform[k], &resultRight);
			add_bignum(&saveTwo[max-k], &resultRight, &finalResult[k - 1]);
		}

		//값들 비교
		saveFourInform[max] = finalResult[0];

		for (k = 1; k < max-1; k++) {
			if (Compare(saveFourInform[max], finalResult[k]) == 1) saveFourInform[max] = finalResult[k];
		}
		delete finalResult;
	}
	
}

int main()
{
	static int N;
	static int maxN=1;
	saveTwoMul();
	initFourInform();

	while (scanf_s("%d", &N) != EOF) {
		if (maxN < N) {
			Hanoi4(maxN, N);
			maxN = N;
		}
		printBignum(saveFourInform[N]);
	}



    return 0;
}

