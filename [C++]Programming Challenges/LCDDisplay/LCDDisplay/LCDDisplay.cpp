// LCDDisplay.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class Drawing {
public:
	int size, count;
	char ***display;
	void col(char*);//draw
	Drawing(int, int);
	Drawing();
	~Drawing();
};
Drawing::Drawing() {}
Drawing::Drawing(int size, int count) {

	this->size = size;
	this->count = count;
	display = new char**[count];

	for (int i = 0; i < count; i++) {
		display[i] = new char*[2 * size + 3];
		for (int j = 0; j < 2 * size + 3; j++) {
			display[i][j] = new char[size + 2];
		}
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < 2 * size + 3; j++) {
			for (int z = 0; z < size + 2; z++) {
				display[i][j][z] = ' ';
			}
		}
	}
}
Drawing::~Drawing() 
{
	for (int i = 0; i < count; i++)
		for (int j = 0; j < 2 * size + 3; j++)
			delete[] display[i][j];

	for (int i = 0; i < count; i++)
		delete[] display[i];

	delete[] display;
}
void Drawing::col(char* num) {//세로
	for (int i = 0; i < count; i++)
	{
		switch (num[i])
		{
		case '1':
			for (int s = 1; s <= size; s++) {
				display[i][s][size + 1] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;

		case '2':
			for (int s = 1; s <= size; s++) {
				display[i][0][s] = '-';
				display[i][size + 1][s] = '-';
				display[i][2 * size + 2][s] = '-';

				display[i][s][size + 1] = '|';
				display[i][s + size + 1][0] = '|';
			}
			break;

		case '3':
			for (int s = 1; s <= size; s++) {
				display[i][0][s] = '-';
				display[i][size + 1][s] = '-';
				display[i][2 * size + 2][s] = '-';

				display[i][s][size + 1] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;

		case '4':
			for (int s = 1; s <= size; s++) {
				display[i][size + 1][s] = '-';

				display[i][s][0] = '|';
				display[i][s][size + 1] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;

		case '5':
			for (int s = 1; s <= size; s++) {
				display[i][0][s] = '-';
				display[i][size + 1][s] = '-';
				display[i][2 * size + 2][s] = '-';

				display[i][s][0] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;

		case'6':
			for (int s = 1; s <= size; s++) {
				display[i][0][s] = '-';
				display[i][size + 1][s] = '-';
				display[i][2 * size + 2][s] = '-';

				display[i][s][0] = '|';
				display[i][s + size + 1][0] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;

		case'7':
			for (int s = 1; s <= size; s++) {
				display[i][0][s] = '-';

				display[i][s][size + 1] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;

		case'8':
			for (int s = 1; s <= size; s++) {
				display[i][0][s] = '-';
				display[i][size + 1][s] = '-';
				display[i][2 * size + 2][s] = '-';

				display[i][s][0] = '|';
				display[i][s][size + 1] = '|';
				display[i][s + size + 1][0] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;

		case'9':
			for (int s = 1; s <= size; s++) {
				display[i][0][s] = '-';
				display[i][size + 1][s] = '-';
				display[i][2 * size + 2][s] = '-';

				display[i][s][0] = '|';
				display[i][s][size + 1] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;

		case'0':
			for (int s = 1; s <= size; s++) {
				display[i][0][s] = '-';
				display[i][2 * size + 2][s] = '-';

				display[i][s][0] = '|';
				display[i][s][size + 1] = '|';
				display[i][s + size + 1][0] = '|';
				display[i][s + size + 1][size + 1] = '|';
			}
			break;
		}
	}
}

int main()
{
	int size, count;
	char* num;
	int objectNum = 0;
	Drawing *d = new Drawing[5];

	while (1) {
		num = new char();
		cin >> size;
		cin >> num;

		if (size == 0 && num == 0) break;

		count = 0;
		for (int i = 0; num[i]; i++) {
			count++;
		}
		d[objectNum] = Drawing(size, count);
		d[objectNum].col(num);
		objectNum++;

		delete num;
	}

	//count=숫자갯수
	//가로사이즈:2+size 세로사이즈:size*2+3
	//3차원배열들 한꺼번에 출력하게끔 이어주기
	for (int o = 0; o < objectNum; o++) {
		for (int i = 0; i < size * 2 + 3; i++)
		{
			for (int z = 0; z < count; z++) {
				for (int j = 0; j < (2 + size); j++)
				{
					cout << d[objectNum].display[z][i][j] << " ";
				}
			}
			cout << endl;
		}
	}

	for (int o = 0; o < objectNum; o++) {
		d[objectNum].~Drawing();
	}

	return 0;
}

