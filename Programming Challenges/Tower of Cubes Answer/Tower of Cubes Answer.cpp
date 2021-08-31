// Tower of Cubes Answer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

static int n;
static int inp[501][6], c[501][6]; // inp:정육면체 숫자들
static int tracking1[501][6], tracking2[501][6];
static int solNumber[501], solSide[501];
static int cnSol, t;

const int opSide[] = { 1,0,3,2,5,4 }; //반대편 인덱스 의미인듯,
const char sides[6][7] = { "front","back","left","right","top","bottom" };

int input(void)
{
	int i, j;

	scanf_s("%d", &n);
	if (n == 0)
		return 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < 6; j++)
			scanf_s("%d", &inp[i][j]);

	return 1;

}


void dynamic()
{
/*	int max, nextN, nextS;
	for (int i = 0; i < n; i++) {
		for (int is = 0; is < 6; is++) {
			max = 0; nextN = -1, nextS = -1;

			for (int j = 0; j < i; j++) {
				for (int js = 0; js < 6; js++) {
					if (inp[i][is] == inp[j][opSide[js]] && max < c[j][js]) {
						max = c[j][js];
						nextN = j;
						nextS = js;
					}
				}
			}

			c[i][is] = max+1;
			tracking1[i][is] = nextN;
			tracking2[i][is] = nextS;
		}
	}*/
	int i, is, j, js;
	int max, mi, ms;
	for (i = 0; i < n; i++)
	{
		for (is = 0; is < 6; is++) {

			max = 0, mi = -1; ms = -1;
			for (j = 0; j<i; j++)
				for (js = 0; js<6; js++)
					if (inp[i][is] == inp[j][opSide[js]] && max < c[j][js]) { //해당주사위 위로(가벼운주사위대상으로) c[][]값이 가장 큰 주사위의 인덱스,방향 찾기
						max = c[j][js];//?
						mi = j;
						ms = js;
					}

			c[i][is] = max + 1;
			tracking1[i][is] = mi;
			tracking2[i][is] = ms;
		}

	}
}

void tracking_procedure()
{
	/*int max = 0;
	int N, S;

	for (int i = 0; i < n; i++) {
		for (int s = 0; s < 6; s++) {
			if (c[i][s] > max) {
				max = c[i][s];
				N = i;
				S = s;
			}
		}
	}
	cnSol = max;

	int incIndex = -1;
	int copyN, copyS;
	while (c[N][S] != 1) {
		solNumber[++incIndex] = N;
		solSide[incIndex] = S;

		copyN = N;
		copyS = S;

		N = tracking1[copyN][copyS];
		S = tracking2[copyN][copyS];
	}
	solNumber[++incIndex] = N;
	solSide[incIndex] = S;

	*/
	int max, mi, ms;
	int ti, ts;
	int i, j;

	max = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j<6; j++)
			if (max < c[i][j]) {
				max = c[i][j];
				mi = i;
				ms = j;
			}
	cnSol = 0;
	while (tracking1[mi][ms] != -1) {
		solNumber[cnSol] = mi;
		solSide[cnSol] = ms;
		cnSol++;

		ti = tracking1[mi][ms];
		ts = tracking2[mi][ms];

		mi = ti;
		ms = ts;
	}

	//마지막 탐색된 주사위 출력을위해 삽입
	solNumber[cnSol] = mi;
	solSide[cnSol] = ms;
	cnSol++;
}

void output(void) {
	int i;

	printf("Case #%d\n", t);
	printf("%d\n", cnSol);

	for(i=cnSol-1; i>=0; i--)
		printf("%d %s\n", solNumber[i] + 1, sides[solSide[i]]);
	printf("\n");
}




int main()
{
	t = 0;

	while (input()) {
		t++;
		dynamic();
		tracking_procedure();
		output();
	}

    return 0;
}

/*
void dynamic(void) {
int i, is, j, js;
int max, mi, ms;
for (i = 0; i < n; i++)
{
for (is = 0; is < 6; is++) {

max = 0, mi = -1; ms = -1;
for(j=0; j<i; j++)
for(js=0; js<6; js++)
if (inp[i][is] == inp[j][opSide[js]] && max < c[j][js]) { //해당주사위 위로(가벼운주사위대상으로) c[][]값이 가장 큰 주사위의 인덱스,방향 찾기
max = c[j][js];//?
mi = j;
ms = js;
}

c[i][is] = max + 1;
tracking1[i][is] = mi;
tracking2[i][is] = ms;
}

}
}

void tracking_procedure(void) {
int max, mi, ms;
int ti, ts;
int i, j;

max = 0;
for (i = 0; i < n; i++)
for(j=0; j<6; j++)
if (max < c[i][j]) {
max = c[i][j];
mi = i;
ms = j;
}
cnSol = 0;
while (tracking1[mi][ms] != -1) {
solNumber[cnSol] = mi;
solSide[cnSol] = ms;
cnSol++;

ti = tracking1[mi][ms];
ts = tracking2[mi][ms];

mi = ti;
ms = ts;
}

//마지막 탐색된 주사위 출력을위해 삽입
solNumber[cnSol] = mi;
solSide[cnSol] = ms;
cnSol++;
}
*/