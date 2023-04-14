// NQueen.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*void InitArray(int** ar, int** board,int N)
{
	for (int i = 0; i < N; i++) {
		ar[i] = new int[3];
		for (int j = 0; j < 3; j++) ar[i][j] = board[i][j];
	}
}*/
void CopyArray(char* ar, char* board, int N)
{
	for (int i = 0; i < N; i++) {
		ar[i] = board[i];
	}
}
void initArray(char* ar, int N)
{
	for (int i = 0; i < N; i++) {
		ar[i] =0;
	}
}

bool forDecalcoSw = false;
void JudgeforDecalco(short& forSearch,int &N)
{
	forDecalcoSw = false;
	if(forSearch < N - (N / 2) - (N % 2))
		forDecalcoSw = true;
}

int situationCount = 0;
void Backtracking(int N,char* copy_board,char queenCount,char beforIndex_Y)//beforindex_x,y 스타트값은 -1
{

	if (queenCount == N)
	{
		if (forDecalcoSw)
			situationCount++;

		situationCount++;
	return;
	}//

	short forSearch = 0;
	char* copyofcopy_board = new char[N];
	initArray(copyofcopy_board, N);

	if (beforIndex_Y != -1) {

		int i;
		//int* copyofcopy_board = new int[N];
		//initArray(copyofcopy_board, N);
		//상향대각선 옮기기
		for (i = 0; i < N; i++)
		{
			switch (copy_board[i]) {
			case 0: break;
			case 1:
				copyofcopy_board[i] += 1;
				break;

			case 3:
				if (i - 1 >= 0)
					copyofcopy_board[i - 1] += 3;
				break;

			case 4:
				copyofcopy_board[i] += 1;

				if (i - 1 >= 0) {
					copyofcopy_board[i - 1] += 3;
				}
				break;

			case 5:

				if (i + 1 < N) {
					copyofcopy_board[i + 1] += 5;
				}
				break;
			case 6:
				copyofcopy_board[i] += 1;

				if (i + 1 < N) {
					copyofcopy_board[i + 1] += 5;
				}
				break;
			case 8:
				if (i - 1 >= 0) {
					copyofcopy_board[i - 1] += 3;
				}
				if (i + 1 < N) {
					copyofcopy_board[i + 1] += 5;
				}
				break;
			case 9:
				copyofcopy_board[i] += 1;

				if (i - 1 >= 0) {
					copyofcopy_board[i - 1] += 3;
				}
				if (i + 1 < N) {
					copyofcopy_board[i + 1] += 5;
				}
				break;
			}

		}


		copyofcopy_board[beforIndex_Y] += 1;//직선 checking
		if (beforIndex_Y - 1 >= 0)
			copyofcopy_board[beforIndex_Y - 1] += 3; //상향대각선 checking
		if (beforIndex_Y + 1 < N)
			copyofcopy_board[beforIndex_Y + 1] += 5;//하향대각선 checking

	}
	
	if (queenCount == 0)
	{
		while (forSearch < N - (N/2)) {
			if (copyofcopy_board[forSearch] == 0) {
				/*forDecalcoSw = false;
				if (forSearch < N - (N / 2) - (N % 2))
					forDecalcoSw = true;*/
				JudgeforDecalco(forSearch, N);
				Backtracking(N, copyofcopy_board, queenCount + 1, forSearch);

			}
			forSearch++;
		}
	}
	else
	{
		while (forSearch < N) {
			if (copyofcopy_board[forSearch] == 0) {
				Backtracking(N, copyofcopy_board, queenCount + 1, forSearch);
			}
			forSearch++;
		}
	}


	if (forSearch == N) {
		delete copyofcopy_board;
	}
}

int main()
{
	int N;
	cin >> N;
	char* board = new char[N];

	//char testc = 3;
	//int ttt = testc;


	for (int j = 0; j < N; j++) {
		board[j] = 0;
	}
	Backtracking(N, board, 0, -1);
	cout << situationCount;
	    return 0;
}

