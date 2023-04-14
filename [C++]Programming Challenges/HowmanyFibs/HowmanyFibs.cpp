// HowmanyFibs.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*

const int MAXDIGIT = 100;

static char a[MAXDIGIT + 1], b[MAXDIGIT + 1];
static char fib[3][MAXDIGIT + 1];
static int lengtha, lengthb, length[3];
static int result;
int input(void) {
	int i;
	char tempa[MAXDIGIT + 1], tempb[MAXDIGIT + 1];
	cin >> tempa >> tempb;

	if (tempa[0] == '0' && tempb[0] == '0') return 0;
	lengtha = 0; 
	lengthb = 0;
	//for (; tempa[lengtha] != NULL; lengtha++);
	//for (; tempa[lengthb] != NULL; lengthb++);
	lengtha = strlen(tempa);
	lengthb = strlen(tempb);

	for (i = 0; i < lengtha; i++)
		a[i] = tempa[lengtha - i - 1] - '0';
	for (i = 0; i < lengthb; i++)
		b[i] = tempb[lengthb - i - 1] - '0';

	return 1;
}

int compare(int fi, char *numb, int len)
{
	int i;

	if (length[fi] < len) return -1;
	if (length[fi] > len) return 1;

	for (i = len - 1; i >= 0; i--) {
		if (fib[fi][i] < numb[i]) return -1;
		if (fib[fi][i] > numb[i]) return 1;
	}
	return 0;
}

void pluss(int target, int a, int b) {
	int len = 0, carry = 0;

	for (; len < length[a] && len < length[b]; len++) {
		fib[target][len] = (fib[a][len] + fib[b][len] + carry);
		if (fib[target][len] >= 10) carry = 1;
		else carry = 0;

		fib[target][len] %= 10;
	}

	if (len < length[a]) {
		for (; len < length[a]; len++) {
			fib[target][len] = (fib[a][len] + carry);
			if (fib[target][len] >= 10) carry = 1;
			else carry = 0;
			fib[target][len] %= 10;
		}
	}
	else {
		for (; len < length[b]; len++) {
			fib[target][len] = (fib[b][len] + carry);
			if (fib[target][len] >= 10) carry = 1;
			else carry = 0;
			fib[target][len] %= 10;
		}
	}

	
		if (carry) fib[target][len++] = 1;

		length[target] = len;



}*/
////////////////
struct bitnum {
	char num[10000];
	int lastIndex=0;
};

void add(bitnum* num1, bitnum* num2, bitnum* result) {
	int carry;
	int i;

	result->lastIndex = num1->lastIndex > num2->lastIndex ? num1->lastIndex + 1 : num2->lastIndex + 1;
	carry = 0;

	int cToI1, cToI2;
	for (i = 0; i <= result->lastIndex; i++) {
		cToI1 = (num1->num[i] >= 48) ? num1->num[i] - 48 : 0;
		cToI2 = (num2->num[i] >= 48) ? num2->num[i] - 48 : 0;

		result->num[i] = ((carry + cToI1 + cToI2) % 10) + 48;
		carry = (carry+cToI1 + cToI2) / 10;
	}

	while (result->lastIndex > 0 && result->num[result->lastIndex] == '0') result->lastIndex--;
	result->lastIndex++;
}

int Compare(bitnum& input, bitnum* value) { //true:1 false:2
	if (input.lastIndex > value->lastIndex) return 1;
	if (input.lastIndex < value->lastIndex) return 2;

	for (int i = input.lastIndex - 1; i >= 0; i--) {
		if (input.num[i] > value->num[i]) return 1;
		if (input.num[i] < value->num[i]) return 2;
	}
	//input과 value값이 같은경우
	return 0;
}

void ReverseSort(bitnum& num) {
	char temp;
	for (int i = 0; i < num.lastIndex; i++) {
		if (i == num.lastIndex - i - 1 || i-1 == num.lastIndex-i-1) break;

		temp = num.num[i];
		num.num[i] = num.num[num.lastIndex - i - 1];
		num.num[num.lastIndex - i - 1] = temp;
	}
}

int main()
{
	while (1) {
		bitnum inputa, inputb;
		cin >> inputa.num >> inputb.num;

		if (inputa.num[0] == '0' && inputb.num[0] == '0') break;
		

		for (; inputa.num[inputa.lastIndex] != NULL; inputa.lastIndex++);
		for (; inputb.num[inputb.lastIndex] != NULL; inputb.lastIndex++);

		//역순정렬
		ReverseSort(inputa);
		ReverseSort(inputb);

		bitnum ** pib = new bitnum*[3]; // [0] : a-2, [1] : a-1, [2] : a
		int i, result;
		for (i = 0; i < 3; i++) pib[i] = new bitnum();

		pib[0]->num[0] = '1'; pib[0]->lastIndex = 1;
		pib[1]->num[0] = '1'; pib[1]->lastIndex = 1;

		for (i = 1; Compare(inputa, pib[(i) % 3]) == 1; i++)
			add(pib[(i-1) % 3], pib[(i) % 3], pib[(i + 1) % 3]);

		result = i;

		for (; Compare(inputb, pib[(i) % 3]) <= 1; i++)
			add(pib[(i - 1) % 3], pib[(i) % 3], pib[(i + 1) % 3]);

		result = i - result;

		cout << result << '\n';
	}
	/*
	int i;

	while (input()) {
		length[0] = length[1] = 1;
		fib[0][0] = fib[1][0] = 1;

		for (i = 1; compare(i % 3, a, lengtha) < 0; i++)
			pluss((i + 1) % 3, i % 3, (i - 1) % 3);

		result = i;

		for (; compare(i % 3, b, lengthb) <= 0; i++)
			pluss((i + 1) % 3, i % 3, (i - 1) % 3);

		result = i - result;

		cout << result << '\n';
	}*/
    return 0;
}

