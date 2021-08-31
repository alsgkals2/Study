// GraphicEditor.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class colorBoard {

public:
	char** board;

	int M, N, X, Y, X1, X2, Y1, Y2;
	char C;
	char *name = new char();
	colorBoard *nextBoard;

	void Judge(char);
	void I();
	void L();
	void CC();
	void V();
	void H();
	void K();
	void F();
	void S(const colorBoard&);
	colorBoard();
};
colorBoard::colorBoard() {}

void colorBoard::Judge(char input)
{
	if (input == 'I') {
		cin >> M >> N;
		I();
	}
	else if (input == 'L') {
		cin >> X >> Y >> C;
		L();
	}
	else if (input == 'C') {
		CC();
	}
	else if (input == 'V') {
		cin >> X >> Y1 >> Y2 >> C;
		V();
	}
	else if (input == 'H') {
		cin >> X1 >> X2 >> Y >> C;
		H();
	}
	else if (input == 'K') {
		cin >> X1 >> Y1 >> X2 >> Y2 >> C;
		K();
	}
	else if (input == 'F') {
		cin >> X >> Y >> C;
		F();
	}
	else if (input == 'S') {
		S(*this);
	}
}
void colorBoard::I() {
	board = new char*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new char[M];
		for (int j = 0; j < M; j++) {
			board[i][j] = 'O';
		}
	}
}

void colorBoard::L() {
	board[Y - 1][X - 1] = C;
}

void colorBoard::CC() {
	for (int i = 0; i < this->N; i++) {
		for (int j = 0; j < this->M; j++) {
			board[i][j] = 'O';
		}
	}
}

void colorBoard::V() {
	for (int i = Y1 - 1; i < Y2; i++)
		board[i][X - 1] = C;
}

void colorBoard::H() {
	for (int j = X1 - 1; j < X2; j++)
		board[Y - 1][j] = C;
}

void colorBoard::K() {
	for (int i = Y1 - 1; i < Y2; i++)
		for (int j = X1 - 1; j < X2; j++)
		{
			board[i][j] = C;
		}
}

void colorBoard::F() {
	int XX = X - 1, YY = Y - 1;
	char spot = board[Y - 1][X - 1];//이전색깔 미리저장


	while (1) {
		board[YY][XX] = C;//색변경

		if (YY + 1 < M && board[YY + 1][XX] == spot) {
			YY = YY + 1;
		}
		else if (XX + 1 < M && board[YY][XX + 1] == spot) {
			XX = XX + 1;
		}
		else if (YY - 1 >= 0 && board[YY - 1][XX] == spot) {
			YY = YY - 1;
		}
		else if (XX - 1 >= 0 && board[YY][XX - 1] == spot) {
			XX = XX - 1;
		}
		else break;
	}
	board[YY][XX] = C;//색변경

	//재탐색:모든x에 대해서 그 주변에서 c를찾고, 위의형태 반복.
		//우측하단까지 다 돌아서 없으면 함수종료
	int switt = 0;
	while (1) {
		switt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i + 1 < M && board[i + 1][j] == spot) {
					board[i + 1][j] = C;//색변경
					switt = 1;
				}
				if (j + 1 < M && board[i][j + 1] == spot) {
					board[i][j + 1] = C;//색변경
					switt = 1;
				}
				if (i - 1 >= 0 && board[i - 1][j] == spot) {
					board[i - 1][j] = C;//색변경
					switt = 1;
				}
				if (j - 1 >= 0 && board[YY][j - 1] == spot) {
					board[i][j - 1] = C;//색변경
					switt = 1;
				}
			}
		}
		if (switt == 0) break;
	}
}

colorBoard *ccd = new colorBoard();
int ss = 0;
void colorBoard::S(const colorBoard &cb) {
	nextBoard = new colorBoard(); //다음객체 생성

	nextBoard->board = new char*[N];
	for (int i = 0; i < cb.N; i++)
		nextBoard->board[i] = new char[cb.M];

	for (int i = 0; i < cb.N; i++)
		for (int j = 0; j < cb.M; j++)
			nextBoard->board[i][j] = cb.board[i][j]; //그전값 정보 저장
	
	nextBoard->M = cb.M;
	nextBoard->N = cb.N;
	//X가 바로 들어간다면 위의소스 생략하고 nextBoard = NULL;

	char input = 'S';  char x_input = '.';
	while (x_input != 'X') {
		cin >> input;
		if (input == 'X') { x_input = 'X'; }
		else if (input == 'S') {
			//만약 input이 S면 그다음값을 보고 결정함
			cin >> nextBoard->name;
			cin >> x_input;
		}
		else nextBoard->Judge(input);
	}
}

int main()
{
	colorBoard* start;
	start = new colorBoard();
	start = ccd;

	char input;

	while (1) {
		cin >> input;
		if (input == 'S') {
			cin >> ccd->name;
		}
		ccd->Judge(input);
		if (input == 'S') {
			break;
		}
	}

	//출력하기
	while (start) {
		cout << start->name << endl;
		for (int i = 0; i < start->N; i++) {
			for (int j = 0; j < start->M; j++) {
				cout << start->board[i][j] << " ";
			}
			delete[] start->board[i];
			cout << endl;
		}
		delete[] start->board;

		if (start->nextBoard == NULL) break;
		else start = start->nextBoard;
	}

	//메모리 해제하기
	
	delete start;
	delete ccd;
	return 0;
}

