// Bigger Square Please.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
/*int squareNum;
int SquareSize;
char** finalBoard;

void SaveFinalBoard(char** finalBoard, char** board) {
	for (int i = 1; i <= SquareSize; i++) {
		for (int j = 1; j <= SquareSize; j++) {
			finalBoard[i][j] = board[i][j];
		}
	}
}

bool IsSolution(int& x, int &y,char **board) //board에 사각형이 꽉차있으면 true
{
	int j;
	for (int i = 1; i <= SquareSize; i++) //i=y좌표에 관한변수
	{
		j = 1;
		while (j != SquareSize + 1&&board[i][j] != 'f') {
			j = j + board[i][j];
		}
		if (j != SquareSize + 1) return false;
	}

	return true;
}

void Spread(int& x, int& y, char** board,int &size)//board의 좌측에 크기표시
{
	for (int i = y; i < y + size; i++) // y값 레퍼런스 넎으면 i값바뀌면 변하는지 확인해보기
	{
		board[i][x] = size;
	}

}

void InitAndCopyArray(char** board, char** copyBoard) {

	for (int i = 1; i <= SquareSize; i++)
	{
		copyBoard[i] = new char[SquareSize + 1];
		for (int j = 1; j <= SquareSize; j++) {
			copyBoard[i][j] = board[i][j];
		}
	}

}

int CulMaxSize(char** board, int& x,int& y) { //해당위치에서 펼칠수있는 가장큰 사각형크기
	int i = x;
	int MaxSize=SquareSize;
		while (i<=SquareSize && board[y][i] == 'f') { i++; }
		if (i - x == 1) return 1;
		if (MaxSize > i - x) MaxSize = i - x;
		MaxSize = MaxSize > SquareSize - y + 1 ? SquareSize - y + 1 : MaxSize;

	for (int s = y+1; s < y + MaxSize && s <= SquareSize; s++)
	{
		i = x;
		while (i <= SquareSize && board[s][i] == 'f') { i++; }
		if (i-x == 1) return 1;
		if (MaxSize > i - x) MaxSize = i - x;
	}

	return MaxSize;
}

void back(int x, int y, char** board,int count)
{
	int i;

	if (IsSolution(x, y,board)) {
		if (count >= squareNum) return;//카운트 크면 리턴

		squareNum = count;
		SaveFinalBoard(finalBoard, board);
	}
	
	else {
		char** copyBoard = new char*[SquareSize+1];

		while (board[y][x] != 'f') {
			if (x + board[y][x] > SquareSize) {
				y = y + 1;
				x = 1;
			}
			else {
				x = x + board[y][x];
			}
		}

		int range;
			if (x != 1 || y != 1) {
				i=CulMaxSize(board, x, y);
				range = 1;
			}
			else
			{
				i = SquareSize - 1; //x,y위치가 1,1일때 i=N은불가능하므로 -1
				range = (SquareSize / 2) + (SquareSize % 2);
			}
			for (; i >= range && count<squareNum-1; i--) {
				InitAndCopyArray(board, copyBoard);

				Spread(x, y, copyBoard, i);
				back(x, y, copyBoard, count + 1);

				for (int d = 1; d <= SquareSize; d++)
					delete[] copyBoard[d];
			}

			//할당해제
			delete copyBoard;
	}
}


int main()
{
	int i, j;
	int TC;

	cin >> TC;

	while (TC-- != 0) {


		cin >> SquareSize;
		squareNum = SquareSize * SquareSize;
		char** board = new char*[SquareSize + 1];
		finalBoard = new char*[SquareSize + 1];
		for (i = 0; i < SquareSize + 1; i++)
		{
			board[i] = new char[SquareSize + 1];
			finalBoard[i] = new char[squareNum + 1];
			for (j = 0; j < SquareSize + 1; j++)
			{
				board[i][j] = 'f';
			}
		}

		back(1, 1, board, 0);
		cout << squareNum << '\n';

		for (j = 1; j <= SquareSize; j++) {
			for (i = 1; i <= SquareSize;) {
				if (finalBoard[i][j] != 'f') {
					printf("%d %d %d\n", i, j, finalBoard[i][j]);
					i += finalBoard[i][j];
					continue;
				}
				i++;
			}
		}
	}

    return 0;
}*/

#include <iostream>
#define MAX_N 50
#define MAX_SQUARE 100

#define DATABASE_NUM 11

int db_num[DATABASE_NUM] = { 11,13,17,19,23,29,31,37,41,43,47 };
int db_cnt[DATABASE_NUM] = { 11,11,12,13,13,14,15,15,15,16,16 };
int db_square_list[DATABASE_NUM][MAX_SQUARE]=
{ {7,4,4,4,2,1,3,2,2,1,1},
{7,6,2,4,6,1,3,1,3,2,2},
{9,8,2,4,2,2,8,1,3,1,5,4},
{13,6,6,2,4,6,6,1,3,1,3,2,2},
{13,10,4,6,10,2,1,3,2,2,1,7,6},
{17,12,4,8,2,2,12,4,1,3,2,1,9,8},
{21,10,10,4,6,10,5,3,3,7,3,5,1,5,4},
{21,16,7,9,16,3,2,1,5,2,1,1,4,12,9},
{23,18,7,11,18,3,2,1,5,3,2,1,4,12,11},
{29,14,14,2,5,7,14,14,1,3,3,3,2,1,8,7},
{28,19,11,8,8,19,7,2,5,8,3,5,12,9,2,7},
};




int main()
{
	int i, test_case;
	char** board = new char*[MAX_N + 1];
	for (i = 0; i < MAX_N + 1; i++) {
		board[i] = new char[MAX_N + 1];
		for (int j = 0; j < MAX_N + 1; j++)
		{
			board[i][j] = 0;
		}
	}

	cin >> test_case;
	for (i = 0; i < test_case; i++)
	{
		int j, k=0;
		int n;
		int square_num = 0;
		int square_list[MAX_SQUARE];
		int height[MAX_SQUARE] = { 0 };

		cin >> n;

		if (n % 2 == 0) {
			square_num = 4;
			square_list[0] = n / 2;
			square_list[1] = n / 2;
			square_list[2] = n / 2;
			square_list[3] = n / 2;
		}
		else if (n % 3 == 0) {
			square_num = 6;
			square_list[0] = n / 3 * 2;
			square_list[1] = n / 3;
			square_list[2] = n / 3;
			square_list[3] = n / 3;
			square_list[4] = n / 3;
			square_list[5] = n / 3;
		}
		else if (n % 5 == 0) {
			square_num = 8;
			square_list[0] = n / 5 * 3;
			square_list[1] = n / 5 * 2;
			square_list[2] = n / 5;
			square_list[3] = n / 5;
			square_list[4] = n / 5 * 2;
			square_list[5] = n / 5 * 2;
			square_list[6] = n / 5;
			square_list[7] = n / 5;
		}
		else if (n % 7 == 0) {
			square_num = 9;
			square_list[0] = n / 7 * 3;
			square_list[1] = n / 7 * 4;
			square_list[2] = n / 7 * 2;
			square_list[3] = n / 7;
			square_list[4] = n / 7 * 3;
			square_list[5] = n / 7 * 2;
			square_list[6] = n / 7 * 2;
			square_list[7] = n / 7;
			square_list[8] = n / 7;
		}
		else {
			for (j = 0; j < DATABASE_NUM; j++)
				if (db_num[j] == n)
				{
					square_num = db_cnt[j];
					for(int sn=0; sn<square_num; sn++)
						square_list[sn] = db_square_list[j][sn];
				}
		}
			cout << square_num<<'\n';

			//for (j = 0; j < square_num; j++)
			int indexinc = 1;
			int listindex = 0;
			while(indexinc <= n){
				j = 1;
				while (board[j][indexinc] != 0) j += board[j][indexinc];

				if(j <= n)
				{
					printf("%d %d %d\n", j, indexinc, square_list[listindex]);
					for (int range = indexinc; range < indexinc + square_list[listindex]; range++)
					{
						board[j][range] = square_list[listindex];
					}
					listindex++;
				}
				else indexinc++;
				//while (height[j] == n) j++;

			/*int min_x = 0;
			int left = 0;
			int now_size = 0, min_size = -1;
			for (k = 1; k <= n; k++)
				if (k == n || height[k] != height[left])//높이가 달라지면
				{
					int now_size = k - left; //min_x+1에서 펼칠수있는
					if (left > 0 && height[left] > height[left - 1])//높이가 낮았다가 높아지면 변경
					{
						left = k;
							continue;
						}
						if (k<n && height[k - 1]>height[k]) //높이가 높았다가 낮아지면 left값변경
						{
							left = k;
							continue;
						}
						if (now_size < min_size || min_size == -1)
						{
							min_size = now_size;
							min_x = left;
						}
						left = k;
					}

				printf("%d %d %d\n", min_x + 1, height[min_x] + 1, square_list[j]);

				for (k = 0; k < square_list[j]; k++)
					height[min_x + k] += square_list[j];
			*/
			
			
			
			}
	}

	return 0;
}

