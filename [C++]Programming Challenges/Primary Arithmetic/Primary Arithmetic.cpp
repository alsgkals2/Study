// Primary Arithmetic.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
using namespace std;

typedef struct {
	char digits[100];
	int signbit=0;
	int lastdigit=0;

}bignum;

void add_bignum(bignum *a, bignum *b, bignum *c) {
	int carry;

	if (a->lastdigit > b->lastdigit) {
		c->lastdigit = a->lastdigit+1;

	}
	else {
		c->lastdigit = b->lastdigit+1;

	}
	carry = 0;

	int i = 0;

	for (i = 0; i < c->lastdigit; i++) {
		int charA=0, charB=0;
		if(a->digits[i] >=48) charA = a->digits[i] - 48;
		 if(b->digits[i] >=48)charB = b->digits[i] - 48;

		c->digits[i] = '0'+((carry + (charA) + (charB)) % 10);
		carry = ((carry + (charA) + (charB)) / 10);
	}

	while (c->lastdigit-1>0 && c->digits[c->lastdigit-1] == '0') c->lastdigit--;
}

void print_bignum(bignum *n) {
	int i;
	if (n->digits[0] != '0') i = 0;
	else i = 1;
	for (; i < n->lastdigit; i++)
		printf("%c", n->digits[i]);
	printf("\n");
}

int main()
{
	int count = 0;
	int N = 0;
	bignum* a ; bignum *b ;
	bignum* output;
	int repeatNum;

	cin >> N;
	char inputNum[3][100];
/*	for (int n = 0; n < N; n++) {
		cin >> inputNum[n];
	}
	*/
	for(int n=0; n<N; n++) {
		cin >> inputNum[n];
		a = new bignum(); b = new bignum();	
		output = new bignum();
		repeatNum = 1;

		for (count = 0; inputNum[n][count] != NULL; count++) { a->digits[count] = inputNum[n][count]; }
		a->lastdigit = count;
		while (1) {
			int i = 0;


		for (; i<a->lastdigit; i++)
			b->digits[a->lastdigit - i - 1] = a->digits[i];//역수저장
		b->lastdigit += a->lastdigit;

			add_bignum(a, b, output);

			//회문검사
			bool swit = true;
			int rightP = output->lastdigit - 1;

			for (int p=0; p < output->lastdigit; p++,rightP--)
			{
				if (rightP != p || rightP != p - 1) {
					if (output->digits[p] != output->digits[rightP]) {
						swit = false; break;
					}
				}
				else break;
			}

			if (swit) { 	//출력
				cout << repeatNum << " ";
				print_bignum(output); 
				break; }//회문인경우
			else//회문아닌경우
			{
				a = output;
				output = new bignum();
				b->lastdigit = 0;
				repeatNum++;
			}
		}

		//출력
		/*cout << repeatNum << " ";
		print_bignum(output);*/
		
		delete a; delete b; delete output;
	}
	//delete a; delete b; delete output;

		//print_bignum(output);
	return 0;
}

