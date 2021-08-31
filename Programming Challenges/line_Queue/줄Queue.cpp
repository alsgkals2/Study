// 줄Queue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

//15puzzle

const int MAXMOVE = 50;

static int MAXDEPTH;
static int movee[4][2] = { {-1,0},{0,1},{1,0},{0,-1}};
static char movechar[4] = { 'U', 'R', 'D', 'L' };
static int solved, puzzle[4][4];
static int mtop, movestack[MAXMOVE];

void input(void) {
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			scanf_s("%d", &puzzle[i][j]);
}

int cost(void)
{
	int i, j;
	int md1, md2;
	int inv1, inv2, id1, id2;
	int lowb1, lowb2;
	int board[16];
	int conv[16] = { 0,1,5,9,13,2,6,10,14,3,7,11,15,4,8,12 };
	int cnvp[16] = { 0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15 };

	md1 = 0;
	for(i=0; i<4; i++)
		for (j = 0; j < 4; j++)
		{
			if (puzzle[i][j] != 0)
				md1 += abs(i - ((puzzle[i][j] - 1) / 4));
		
		}

	md2 = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j < 4; j++)
		{
			if (puzzle[i][j] != 0)
				md2 += abs(j - ((puzzle[i][j] - 1) % 4));
		}

	

	/*ID*/
	//1차원배열변환
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			board[i * 4 + j] = puzzle[i][j];

	//상하이동에의한ID;
	inv1 = 0;
	for (i = 0; i < 16; i++)
	{
		if (!board[i]) continue; //0이면건너뜀
		for (j = i + 1; j < 16; j++) {
			if (board[j] && board[j] < board[i]) inv1++;
		}
	}

	//좌우이동에의한ID;
	inv2 = 0;
	for (i = 0; i < 16; i++)
	{
		if (!conv[board[cnvp[i]]]) continue; //0이면건너뜀
		for (j = i + 1; j < 16; j++) {
			if (conv[board[cnvp[j]]] && conv[board[cnvp[j]]] < conv[board[cnvp[i]]]) inv2++;
		}
	}

	id1 = (inv1 / 3) + (inv1 % 3);
	id2 = (inv2 / 3) + (inv2 % 3);

	/*MD와 ID중 더 좋은 lower bound선택*/
	lowb1 = (id1 > md1) ? id1 : md1;
	lowb2 = (id2 > md2) ? id2 : md2;

	return lowb1 + lowb2;
}

void back(int a, int nowx, int nowy) {
	int i, c;
	int nextx, nexty;

	//lowerbound 구함
	c = cost();
	if (c == 0) { solved = 1; return; }

	if (a + c > MAXDEPTH) return;

	for (i = 0; i < 4; i++)
	{
		if ((movestack[mtop - 1] + 2) % 4 == i)
			continue;

		nextx = nowx + movee[i][0];
		nexty = nowy + movee[i][1];

		if (nextx < 0 || nextx >= 4 || nexty < 0 || nexty >= 4)
			continue;

		puzzle[nowx][nowy] = puzzle[nextx][nexty]; //이동
		puzzle[nextx][nexty] = 0;

		movestack[mtop++] = i;
		back(a + 1, nextx, nexty);
		if (solved) return;
		mtop--;//solve되지 않은경우 다시 mtop인덱스 이전 인덱스로 이동

		//위치도  제자리
		puzzle[nextx][nexty] = puzzle[nowx][nowy];
		puzzle[nowx][nowy] = 0;
	}
}


void solve(void)
{
	int i, j, k, l, value, x, y;

	/*해결가능한지 확인*/
	value = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (puzzle[i][j] == 0 && (i + j) % 2 == 1)//0의 위치확인,홀수면 value증가
				value++;
			//백트레킹을위해 x,y저장
			if (puzzle[i][j] == 0)
			{
				x = i;
				y = j;
			}

			//각 원소마다 그 뒤에 작은값갯수 탐색
			for (k = i; k < 4; k++)
			{
				if (k == i) l = j + 1;
				else l = 0;
				for (; l < 4; l++)
				{
					if (puzzle[i][j] == 0 || (puzzle[k][l] != 0 && puzzle[i][j] > puzzle[k][l])) value++;
				}
			}
		}
	}

	if (value % 2 == 1) return;

	for (MAXDEPTH = cost(); !solved & (MAXDEPTH <= MAXMOVE); MAXDEPTH += 2)
		back(0, x, y);
}

void output(void)
{
	int i;

	if (solved)
	{
		for (i = 0; i < mtop; i++)
			printf("%c", movechar[movestack[i]]);
	}

	else printf("This puzzle is not solvable.\n");

}

int main()
{
	int i, t;
	scanf_s("%d", &t);
	for (i = 0; i < t; i++) {
		input();
		mtop = 0;
		solved = 0;
		solve();

		output();
	}

    return 0;
}

