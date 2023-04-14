// The Archeologist's Dilemma.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

typedef struct {
	char digits[100];
	int lastdigit;

}bignum;

void add_bignum(bignum *a, bignum *b, bignum *c) {
	int carry;
	int i;
	int charA = 0, charB = 0;

	
	c->lastdigit = a->lastdigit > b->lastdigit ? a->lastdigit+1 : b->lastdigit+1;

	carry = 0;
	for (i = 0; i <= c->lastdigit; i++) {
		charA = 0, charB = 0;
		if (a->digits[i] >= 48) charA = a->digits[i] - 48;
		if (b->digits[i] >= 48) charB = b->digits[i] - 48;

		c->digits[i] = ((carry + charA+ charB) % 10)+'0';
		carry = ((carry + charA + charB) / 10);
	}
	//if (carry > 0) c->digits[c->lastdigit] = '0' + carry;

	while (c->lastdigit > 0 && c->digits[c->lastdigit-1] == '0') c->lastdigit--;

}

bool CheckConferm(bignum* result,char* N,int size) {//입력한 값이 있는지여부검사
	int startIndex = result->lastdigit - 1;
	bool checkResult = true;

	for (int i = startIndex, nInc = 0; i > startIndex-size; i--,nInc++) {
		if (result->digits[i] != N[nInc]) {
			return false;
		}
	}
	return true;
}


int main()
{
	char* N= new char[11];
	int nSize = 0;//숫자길이
	int neededSize = 0;//N값에 대한 최소자릿수
	bignum* twoNum;
	bignum* result;
	int forOutputCount = 1;

	while (1) {
		nSize = 0;
		neededSize = 0;
		forOutputCount = 1;
		N = new char[11];
		twoNum = new bignum();
		result = new bignum();


		cin >> N;
		while (N[nSize] != NULL)nSize++;
		neededSize = (nSize * 2) + 1;

		twoNum->digits[0] = '2';
		twoNum->lastdigit = 1;

		while (1) {
			add_bignum(twoNum, twoNum, result);
			forOutputCount++;

			if (result->lastdigit >= neededSize && CheckConferm(result, N, nSize)) {
				cout << forOutputCount << endl;
				break;
			}
			else if (result->lastdigit == 99) {
				cout << "no power of 2" << endl; break;
			}
			else {
				twoNum = result;
				result = new bignum();
			}
		}
	}
    return 0;
}

