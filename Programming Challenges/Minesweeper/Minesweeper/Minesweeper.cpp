// Minesweeper.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Function {
public:
	int** searching(char**);
	void output(int**, char**);
	int col, row;

};

int** Function::searching(char** mine) {
	int** returnMine = new int*[col];

	for (int i = 0; i < col; i++) {
		returnMine[i] = new int[row];
		for (int j = 0; j < row; j++) {
			if (mine[i][j] != '*') {
				returnMine[i][j] = 0;
			}
			else returnMine[i][j] = '*';
		}
	}

	for (int y =0; y < col; y++) {
		for (int x = 0; x < row; x++) {
			if (mine[y][x] == '*') {
				
				if (x + 1 != row)
				{
					returnMine[y][x + 1]++;
					if (y + 1 != col) returnMine[y + 1][x + 1]++;
				}
				if (y + 1 != col)
				{
					returnMine[y + 1][x]++;
					if (x - 1 != -1) returnMine[y + 1][x - 1]++;
				}
				if (x - 1 != -1)
				{
					returnMine[y][x - 1]++;
					if (y - 1 != -1) returnMine[y - 1][x - 1]++;
				}
				if (y - 1 != -1)
				{
					returnMine[y - 1][x]++;
					if (x + 1 != -1) returnMine[y - 1][x + 1]++;
				}			

			}
		}
	}
	return returnMine;
}

void Function::output(int** result, char** mine)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (mine[i][j] == '*') { cout << "* "; continue; }
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	
}
int main()
{
	Function f;
	f.col = 0, f.row = 0;
	cin >> f.col >> f.row;

	char **mine = new char*[f.col];
	int ** result = new int*[f.col];

	for (int i = 0; i < f.col; i++)
	{
		mine[i] = new char[f.row];
		
		for (int j = 0; j < f.row; j++) {
			cin >> mine[i][j];
		}
	}

	result = f.searching(mine);
	f.output(result,mine);



	for (int i = 0; i < f.col; i++)
	{
		delete[] mine[i];
	}
	delete[] mine;

	return 0;

}

