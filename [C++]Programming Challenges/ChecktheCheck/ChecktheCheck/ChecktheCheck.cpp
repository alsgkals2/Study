// ChecktheCheck.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int dCount = 0;
class check {
public:
	int aw = 0, bw = 0, cw = 0, dw = 0, ew = 0, fw = 0, gw = 0, hw = 0;

	char** board;
	char lowlarge(char);
	int search();
	char* con = new char();

	int Pawn(int, int, char);
	int Knight(int, int, char);
	int Bishop(int, int, char);
	int Rook(int, int, char);
	int Queen(int, int, char);
	int King(int, int, char);

	void print(char);

	check* nextcheck;
	check();
};

check::check() {
	board = new char*[8];
	for (int i = 0; i < 8; i++)board[i] = new char[8];

	this->con = NULL;
}
char check::lowlarge(char c) {
	if (c >= 'A' && c <= 'Z') {
		return 'k';//대문자가 잡아야할 king
	}
	else return 'K';//소문자
}
void check::print(char a) {
	if (a == 'k') {
		con = ": black king is in check.";
	}
	else if (a == 'K') { con = ": white king is in check."; }
	else if (a == '.') { con = ": no king is in check"; }
}
int check::search() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] == 'q' || board[i][j] == 'Q')
			{
				if (Queen(j, i, lowlarge(board[i][j])) == 1)//킹을 잡을수있으면
				{
					print(lowlarge(board[i][j])); i = 9; break;
				}
			}
			else if (board[i][j] == 'r' || board[i][j] == 'R')
			{
				if (Rook(j, i, lowlarge(board[i][j])) == 1) { print(lowlarge(board[i][j])); i = 9; return 0; };
			}
			else if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				if (Bishop(j, i, lowlarge(board[i][j])) == 1) { print(lowlarge(board[i][j])); i = 9; return 0; };
			}
			else if (board[i][j] == 'n' || board[i][j] == 'N')
			{
				if (Knight(j, i, lowlarge(board[i][j])) == 1) { print(lowlarge(board[i][j])); i = 9; return 0; };
			}
			else if (board[i][j] == 'p' || board[i][j] == 'P')
			{
				if (Pawn(i, j, lowlarge(board[i][j])) == 1) { print(lowlarge(board[i][j])); i = 9; return 0; };
			}
			else if (board[i][j] == 'k' || board[i][j] == 'k')
			{
				if (King(i, j, lowlarge(board[i][j]) == 1)) { print(lowlarge(board[i][j])); i = 9; return 0; }
			}

	print('.');//아무런 체크가능정보가 없음
	return 0;

}
int check::Pawn(int x, int y, char a) {
	int swit = 0;
	if (a == 'K')//대문자
	{
		if (y - 1 >= 0 && x - 1 >= 0 && board[y - 1][x - 1] == 'K') return 1;
		else if (y - 1 >= 0 && x + 1 < 8 && board[y - 1][x + 1] == 'K') return 1;
	}
	else//소문자
	{
		if (y + 1 < 8 && x - 1 >= 0 && board[y + 1][x - 1] == 'K') return 1;
		else if (y + 1 < 8 && x + 1 < 8 && board[y + 1][x + 1] == 'K') return 1;
	}


	return 0;
}
int check::Knight(int x, int y, char a) {
	int swit = 0;


	if (y - 1 >= 0) {
		if (x - 2 >= 0) {
			if (board[y - 1][x - 2] == a)
			{
				return 1;
			}
		}
		else if (x + 2 < 8) {
			if (board[y - 1][x + 2] == a)
			{
				return 1;
			}
		}
	}
	if (y + 1 < 8) {
		if (x - 2 >= 0) {
			if (board[y + 1][x - 2] == a)
			{
				return 1;
			}
		}
		else if (x + 2 < 8) {
			if (board[y + 1][x + 2] == a)
			{
				return 1;
			}
		}
	}
	return 0;
}
int check::Bishop(int x, int y, char a) {
	for (int i = 1; i < 8; i++)
	{
		if (aw != 1 && y - i >= 0 && x + i < 8) {//2시
			if (board[y - i][x + i] == a)
			{
				return 1;
			}
			else if (board[y - i][x + i] != '.')
				aw = 1;
		}


		if (bw != 1 && y + i < 8 && x + i < 8) { //5시
			if (board[y + i][x + i] == a)
			{
				return 1;
			}
			else if (board[y + i][x + i] != '.')
				bw = 1;
		}


		if (cw != 1 && y + i < 8 && x - i >= 0) { //8시
			if (board[y + i][x - i] == a)
			{
				return 1;
			}
			else if (board[y + i][x - i] != '.')
				cw = 1;
		}

		if (dw != 1 && y - i >= 0 && x - i >= 0) {//11시
			if (board[y - i][x - i] == a)
			{
				return 1;
			}
			else if (board[y - i][x - i] != '.')
				dw = 1;
		}
	}
	return 0;
}
int check::Rook(int x, int y, char a) {
	for (int i = 1; i < 8; i++)
	{
		if (aw != 1 && y - i >= 0) {
			if (board[y - i][x] == a)
			{
				return 1;
			}
			else if (board[y - i][x] != '.')
				aw = 1;
		}

		if (bw != 1 && x + i < 8) {//3시
			if (board[y][x + i] == a)
			{
				return 1;
			}
			else if (board[y][x + i] != '.')
				bw = 1;
		}

		if (cw != 1 && y + i < 8) {//6시
			if (board[y + i][x] == a)
			{
				return 1;
			}
			else if (board[y + i][x] != '.')
				cw = 1;
		}

		if (dw != 1 && x - i >= 0) {//9시
			if (board[y][x - i] == a)
			{
				return 1;
			}
			else if (board[y][x - i] != '.')
				dw = 1;
		}

	}
	return 0;
}
int check::Queen(int x, int y, char a) { //위치정보넘기기

	for (int i = 1; i < 8; i++) //12시방향
	{
		if (aw != 1 && y - i >= 0) {
			if (board[y - i][x] == a)
			{
				return 1;

			}
			else if (board[y - i][x] != '.')
				aw = 1;
		}


		if (bw != 1 && y - i >= 0 && x + i < 8) {//2시
			if (board[y - i][x + i] == a)
			{
				return 1;
			}
			else if (board[y - i][x + i] != '.')
				bw = 1;
		}


		if (cw != 1 && x + i < 8) {//3시
			if (board[y][x + i] == a)
			{
				return 1;
			}
			else if (board[y][x + i] != '.')
				cw = 1;
		}


		if (dw != 1 && y + i < 8 && x + i < 8) { //5시
			if (board[y + i][x + i] == a)
			{
				return 1;
			}
			else if (board[y + i][x + i] != '.')
				dw = 1;
		}


		if (ew != 1 && y + i < 8) {//6시
			if (board[y + i][x] == a)
			{
				return 1;
			}
			else if (board[y + i][x] != '.')
				ew = 1;
		}


		if (fw != 1 && y + i < 8 && x - i >= 0) { //8시
			if (board[y + i][x - i] == a)
			{
				return 1;
			}
			else if (board[y + i][x - i] != '.')
				fw = 1;
		}

		if (gw != 1 && x - i >= 0) {//9시
			if (board[y][x - i] == a)
			{
				return 1;
			}
			else if (board[y][x - i] != '.')
				gw = 1;
		}

		if (hw != 1 && y - i >= 0 && x - i >= 0) {//11시
			if (board[y - i][x - i] == a)
			{
				return 1;
			}
			else if (board[y - i][x - i] != '.')
				hw = 1;
		}
	}
	return 0;
}
int check::King(int x, int y, char a) {
	if (y - 1 >= 0 && board[y - 1][x] == a) return 1;
	else if (y - 1 >= 0 && x + 1 < 8 && board[y - 1][x + 1] == a) return 1;
	else if (x + 1 < 8 && board[y][x + 1] == a) return 1;
	else if (x + 1 < 8 && y + 1 < 8 && board[y + 1][x + 1] == a)return 1;
	else if (y + 1 < 8 && board[y + 1][x] == a) return 1;
	else if (y + 1 < 8 && x - 1 >= 0 && board[y + 1][x - 1] == a) return 1;
	else if (x - 1 >= 0 && board[y][x - 1] == a) return 1;
	else if (y - 1 >= 0 && x - 1 >= 0 && board[y - 1][x - 1] == a) return 1;
	else return 0;
}

int main()
{
	check *start = new check();
	check *checkk = new check();
	int swit = 0;

	start = checkk;

	checkk->nextcheck = new check();
	check * NewCheck = checkk->nextcheck;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			cin >> checkk->board[i][j];
			if (checkk->board[i][j] != '.') swit = 1;
		}
	}

	if (swit == 0) { return 1; }
	checkk->search();

	while (1) {
		swit = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
			{
				cin >> NewCheck->board[i][j];
				if (NewCheck->board[i][j] != '.') swit = 1;
			}
		}
		if (swit == 0)break;
		NewCheck->search();

		NewCheck->nextcheck = new check();
		NewCheck = NewCheck->nextcheck;
	}


	////출력문

	while (start->con) {
		cout << "Game #" << ++dCount << start->con << endl;
		if (start->nextcheck)
			start = start->nextcheck;
		else break;
	}


	return 0;
}


//swit이 계속 0 이면 .로만 차있는것으로 본다.=>입력종료


