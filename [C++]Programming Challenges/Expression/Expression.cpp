// Expression.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int NUMBERLENGTH = 23;
const int ONEDIGIT = 10000;

typedef struct _longlong {
	unsigned int h[NUMBERLENGTH];
}longlong;

static int n, d;
static longlong result;
static longlong c[151][151];
static longlong e[151];
static longlong f[151][151];

void assign(longlong *a, unsigned int b) {
	int i;
	for (i = 0; i < NUMBERLENGTH; i++) {
		a->h[i] = b%ONEDIGIT;
		b /= ONEDIGIT;
	}
}

void add(longlong *c, const longlong *a, const longlong *b) {
	int i, carry;

	carry = 0;
	for (i = 0; i < NUMBERLENGTH; i++) {
		c->h[i] = a->h[i] + b->h[i] + carry;
		carry = c->h[i] / ONEDIGIT;
		c->h[i] %= ONEDIGIT;
	}
}

void sub(longlong *c, const longlong *a, const longlong *b) {
	int i, carry;

	carry = 0;
	for (i = 0; i < NUMBERLENGTH; i++) {
		if (a->h[i] >= b->h[i]) {
			c->h[i] = a->h[i] - b->h[i] + carry;
			carry = 0;
		}
		else {
			c->h[i] = (ONEDIGIT + a->h[i]) - b->h[i] + carry;
			carry = -1;
		}
	}
}

void mul(longlong *c, const longlong *a, const longlong *b) {
	int i, j, carry;
	unsigned int temp;
	int in, jn;
	longlong d;

	for (i = 0; i < NUMBERLENGTH; i++)
		d.h[i] = 0;
	in = jn = NUMBERLENGTH - 1;


	while (a->h[in] == 0) in--;
	in++;
	while (b->h[jn] == 0) jn--;
	jn++;

	for (i = 0; i < in + 1; i++) {
	
		carry = 0;
		for(j=0; j<jn+1; j++)
			if (i + j < NUMBERLENGTH) {
				temp = (d.h[i + j] + a->h[i] * b->h[j] + carry) % ONEDIGIT;
				carry = (d.h[i + j] + a->h[i] * b->h[j] + carry) / ONEDIGIT;
				d.h[i + j] = temp;
			}
	}
	for (i = 0; i < NUMBERLENGTH; i++)
		c->h[i] = d.h[i];

}

void print(const longlong *a) {
	int sw; int i;
	sw = 0;

	for (i = NUMBERLENGTH - 1; i >= 0; i--) {
		if (!(sw == 0 && a->h[i] == 0)) { //sw가 0이고 맨뒤에서부터 검사할때 0이면 계속건너뛰다가
			if (sw == 0) { //0이아닌 숫자부터가 진짜숫자이므로 그때 sw값 갱신하고 출력시작
				printf("%d", a->h[i]);
				sw = 1;
			}//출력이 시작한시점부터계속 출력, sw=1인상태이므로 계속 출력함.(시작한시점부터는 값이 0인것도 숫자이므로 0도 출력하게끔함.)
			else printf("%04d", a->h[i]);
		}
	}
	if (sw == 0) printf("0"); //마지막까지 숫자가 다 0이면 값이 0
}

void solve(void) {
	int i, j, k;
	longlong p;

	assign(&e[0], 1);
	assign(&e[1], 1);
	assign(&e[2], 2);

	for (i = 3; i <= 150; i++) {
		assign(&e[i], 0);
		for (j = 1; j <= i; j++) {
			mul(&p, &e[j - 1], &e[i - j]);
			add(&e[i], &e[i], &p);
		}
	}

	for(i=0; i<=150; i++)
		for (j = 0; j <= 150; j++) {
			if (i == 0 && j == 0)
				assign(&f[i][j], 1);
			else if (i <= j) f[i][j] = e[i];
			else if (j == 1) assign(&f[i][j], 1);
			else if (j == 0) assign(&f[i][j], 0);
			else {
				assign(&f[i][j], 0);
				for (k = 1; k <= i; k++) {
					mul(&p, &f[k - 1][j - 1], &f[i - k][j]);
					add(&f[i][j], &f[i][j], &p);
				}
			}
		}

}


int main()
{
	solve();

	while (scanf("%d %d", &n, &d) != EOF) {
		sub(&result, &f[n / 2][d], &f[n / 2][d - 1]);
		print(&result);
		printf("\n");
	}
    return 0;
}

