// HowManyPiecesofLanad.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
struct bignum {
	char num[100];
	int lastindex = 0;
};
void AddNum(bignum *a, bignum *b, bignum *c) {
	int carry;
	int i;

	c->lastindex = a->lastindex > b->lastindex ? a->lastindex + 1 : b->lastindex + 1;
	carry = 0;

	int anum, bnum;
	for (i = 0; i < c->lastindex; i++) {
		anum = a->num[i] >= 48 ? a->num[i] - 48 : 0;
		bnum = b->num[i] >= 48 ? b->num[i] - 48 : 0;

		c->num[i] = ((carry + anum + bnum) % 10) + 48;
		carry = (anum + bnum) / 10;
	}

	while (c->lastindex > 0 && c->num[c->lastindex-1] == '0') c->lastindex--;
}

void digit_shift(bignum *n, int d) {
	int i;
	if ((n->lastindex == 0) && (n->num[0] == 0)) return;

	for (i = n->lastindex; i >= 0; i--)
		n->num[i + d] = n->num[i];

	for (i = 0; i < d; i++) n->num[i] = 0;

	n->lastindex = n->lastindex + d;
}


void Multiple(bignum *a, bignum *b, bignum *c) {
	bignum row;
	bignum tmp;
	int i, j;

	row = *a;

	for (i = 0; i <= b->lastindex; i++) {
		for (j = 1; j <= b->num[i]; j++) {
			AddNum(c, &row, &tmp);
			*c = tmp;
		}
		digit_shift(&row, 1);
	}
}

int Comparenum(bignum *a, bignum *b) {
	int i;

	if (b->lastindex > a->lastindex) return 1;
	if (b->lastindex < a->lastindex) return -1;

	for (i = a->lastindex; i >= 0; i--) {
		if (a->num[i] > b->num[i]) return -1;
		if (b->num[i] > a->num[i]) return 1;
	}
	return 0;
}

void substract(bignum *a, bignum *b, bignum *c) {
	int borrow;
	int v;
	int i;

	c->lastindex = a->lastindex > b->lastindex ? a->lastindex : b->lastindex;
	borrow = 0;

	for (i = 0; i <= c->lastindex; i++) {
		v = (a->num[i]-48) - borrow - (b->num[i]-48);
		if (a->num[i] > 48) borrow = 0;
		if (v < 0) {
			v = v + 10;
			borrow = 1;
		}
		c->num[i] = v % 10 + 48;
	}

	while (c->lastindex > 0 && c->num[c->lastindex] == '0') c->lastindex--;
}

void divde(bignum *a, bignum *b, bignum *c) {
	bignum row;
	bignum tmp;
	int i, j;

	c->lastindex = a->lastindex;

	for (i = a->lastindex; i >= 0; i--) {
		digit_shift(&row, 1);
		row.num[0] = a->num[i];
		c->num[i] = 0;
		while (Comparenum(&row, b) != 1) {
			c->num[i]++;
			substract(&row, b, &tmp);
			row = tmp;
		}
	}

	while (c->lastindex > 0 && c->num[c->lastindex] == '0') c->lastindex--;
}

//inputtochar 크기
void SizeAndReverse(char* inputtochar,int &size) {
	char temp;

	for (; inputtochar[size] != NULL; size++) {}
}

void copyInform(const bignum* from,bignum* to) {
	to->lastindex = from->lastindex;
	for (int i = 0; i < from->lastindex; i++)
		to->num[i] = from->num[i];
}

int main()
{
	int TC = 0;
	cin >> TC;
	unsigned long input;
	char* inputTochar = new char();
	bignum *An = new bignum();
	bignum *result = new bignum();
	bignum* exceptedStruct;
	int size = 0;
	char* output;
	unsigned long long exceptedA;
	int i, j,inc;

	while (TC-- != 0) {
		cin >> input;
		An->num[0] = '1';
		An->lastindex = 1;

		for (i = 1; i < input; i++) {

			exceptedStruct = new bignum();
			inputTochar = new char();
			int i_1 = i - 1;
			itoa(i_1, inputTochar, 10);
			SizeAndReverse(inputTochar, size);
			exceptedStruct->lastindex = size;
			for (j = size - 1, inc = 0; j >= 0; j--) exceptedStruct->num[inc++] = inputTochar[j];//대수덧샘을위해 역순으로 정렬해서 삽입


			exceptedA = i+(((i - 1)*i*(2 * i - 1) / 12) - (i*(i - 1) / 4));
			itoa(exceptedA, inputTochar, 10);
			SizeAndReverse(inputTochar, size);
			exceptedStruct->lastindex = size;
			for (j = size - 1, inc = 0; j >= 0; j--) exceptedStruct->num[inc++] = inputTochar[j];//대수덧샘을위해 역순으로 정렬해서 삽입

			AddNum(An, exceptedStruct, result);
			copyInform(result, An);

			//a = a + i + (((i - 1)*i*(2 * i - 1) / 12) - (i*(i - 1) / 4));
			//(n*n*n) - (3*n*n) + 2*n
		}

		output = new char[result->lastindex];

		for (i = result->lastindex - 1; i >= 0; i--) {
			if (result->num[i] >= 49)
				printf("%c", result->num[i]);
		}
		cout<<'\n';
	}

    return 0;
}

