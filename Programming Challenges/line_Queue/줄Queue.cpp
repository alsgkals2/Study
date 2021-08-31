// ��Queue.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	//1�����迭��ȯ
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			board[i * 4 + j] = puzzle[i][j];

	//�����̵�������ID;
	inv1 = 0;
	for (i = 0; i < 16; i++)
	{
		if (!board[i]) continue; //0�̸�ǳʶ�
		for (j = i + 1; j < 16; j++) {
			if (board[j] && board[j] < board[i]) inv1++;
		}
	}

	//�¿��̵�������ID;
	inv2 = 0;
	for (i = 0; i < 16; i++)
	{
		if (!conv[board[cnvp[i]]]) continue; //0�̸�ǳʶ�
		for (j = i + 1; j < 16; j++) {
			if (conv[board[cnvp[j]]] && conv[board[cnvp[j]]] < conv[board[cnvp[i]]]) inv2++;
		}
	}

	id1 = (inv1 / 3) + (inv1 % 3);
	id2 = (inv2 / 3) + (inv2 % 3);

	/*MD�� ID�� �� ���� lower bound����*/
	lowb1 = (id1 > md1) ? id1 : md1;
	lowb2 = (id2 > md2) ? id2 : md2;

	return lowb1 + lowb2;
}

void back(int a, int nowx, int nowy) {
	int i, c;
	int nextx, nexty;

	//lowerbound ����
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

		puzzle[nowx][nowy] = puzzle[nextx][nexty]; //�̵�
		puzzle[nextx][nexty] = 0;

		movestack[mtop++] = i;
		back(a + 1, nextx, nexty);
		if (solved) return;
		mtop--;//solve���� ������� �ٽ� mtop�ε��� ���� �ε����� �̵�

		//��ġ��  ���ڸ�
		puzzle[nextx][nexty] = puzzle[nowx][nowy];
		puzzle[nowx][nowy] = 0;
	}
}


void solve(void)
{
	int i, j, k, l, value, x, y;

	/*�ذᰡ������ Ȯ��*/
	value = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (puzzle[i][j] == 0 && (i + j) % 2 == 1)//0�� ��ġȮ��,Ȧ���� value����
				value++;
			//��Ʈ��ŷ������ x,y����
			if (puzzle[i][j] == 0)
			{
				x = i;
				y = j;
			}

			//�� ���Ҹ��� �� �ڿ� ���������� Ž��
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

