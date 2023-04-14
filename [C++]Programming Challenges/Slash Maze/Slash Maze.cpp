// Slash Maze.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int w, h;
const int MAXWH = 75;
//static int movee[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
static int slashMove[6][2] = { { -1,0 } ,{ -1,1 },{ 0,-1 },{ 1,0 },{ 1,-1 },{ 0,1 } };
static char slashMoverChar[6] = { '\\' ,'/' , '\\' , '\\' ,'/' , '\\' };


static int BslashMove[6][2] = { {-1,0} ,{-1,-1}, {0,1}, {1,0}, {1,1},{ 0,-1 } };
static char BslashMoverChar[6] = { '/' ,'\\', '/'  , '/' ,'\\' , '/' };


//static int check[MAXWH][MAXWH][2];
static int cycle, maxlength;
static int c2;
char** slash;
static int** lineCheck;
static int** QueueleftXY;
static int** QueuerightXY;
int nearL = 0, headL = 1;
int nearR = 0, headR = 1;
int parents[2][75][75];


void initArray() {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			lineCheck[j][i] = 0;
		}
	}

	nearL = 0; headL = 1;
	nearR = 0; headR = 1;

	
}

void CheckParents(int leftX, int leftY, int rightX, int rightY) {
	int saveY, saveX;

	lineCheck[leftY][leftX] = -2;
	lineCheck[rightY][rightX] = -2;

	while (parents[0][leftY][leftX]!= -1) {
		saveY = leftY;
		saveX = leftX;
		leftY = parents[0][saveY][saveX];
		leftX = parents[1][saveY][saveX];
		lineCheck[leftY][leftX] = -2;

	}
	while (parents[0][rightY][rightX] != -1) {
		saveY = rightY;
		saveX = rightX;
		rightY = parents[0][saveY][saveX];
		rightX = parents[1][saveY][saveX];
		lineCheck[rightY][rightX] = -2;

	}
}

void bfs(int leftX, int leftY, int rightX, int rightY) {
	initArray();
	int compareCycle = 0;
	int repeatL = 0;
	int repeatR = 0;
	static int leftLinkedX, leftLinkedY, rightLinkedX, rightLinkedY;
	static int searchedX, searchedY;
	bool finished = false;

	lineCheck[leftY][leftX] = 1; //1 :왼쪽
	lineCheck[rightY][rightX] = 2;//2 :오른쪽
	QueueleftXY[0][headL % 10000] = leftX;
	QueueleftXY[1][headL % 10000] = leftY;
	headL++;
	QueuerightXY[0][headR % 10000] = rightX;
	QueuerightXY[1][headR % 10000] = rightY;
	headR++;

	while (!finished &&( headL - nearL != 1 || headR - nearR != 1)) {
		compareCycle++;


		if (headL == nearL + 1 && QueueleftXY[0][nearL%10000]) repeatL = 10000;
		else if (headL > nearL) { repeatL = headL - nearL - 1; }
		else { repeatL = (9999 - (nearL%10000)) + (headL%10000); }

		//<왼쪽>
		while (repeatL-- != 0) {
			leftLinkedX = QueueleftXY[0][(nearL + 1) % 10000];
			leftLinkedY = QueueleftXY[1][(nearL + 1) % 10000];
			nearL++;
			
			lineCheck[leftLinkedY][leftLinkedX] = 1;

			// ' / '인경우
			if (slash[leftLinkedY][leftLinkedX] == '/') {
				for (int r = 0; r < 6; r++) {
					//접근할 수 없는경우 continue
					searchedY = leftLinkedY + slashMove[r][0];
					if (searchedY < 0 || searchedY >= h) continue;
					searchedX = leftLinkedX + slashMove[r][1];
					if (searchedX < 0 || searchedX >=w) continue;
					 
					if (lineCheck[searchedY][searchedX] == 1) continue;//이전에 탐색됐던경우
					if (slash[searchedY][searchedX] == slashMoverChar[r]) {//연결될수있는 경우

						//양쪽점이 만나는경우
						if (lineCheck[searchedY][searchedX] == 2 && compareCycle % 2 == 0) {
							if (compareCycle == 1 && r == 5) continue;

							if (compareCycle > maxlength) maxlength = compareCycle;
							cycle++;
							finished = true; //bfs종료
							CheckParents(leftLinkedX, leftLinkedY, searchedX, searchedY);
							break;
						}
						else {
							QueueleftXY[0][headL % 10000] = searchedX;
							QueueleftXY[1][headL % 10000] = searchedY;
							headL++;

							lineCheck[searchedY][searchedX] = 1;
							parents[0][searchedY][searchedX] = leftLinkedY;
							parents[1][searchedY][searchedX] = leftLinkedX;
						}
					}


				}
			}

			// '\\'인 경우
			else {
				for (int r = 0; r < 6; r++) {
					searchedY = leftLinkedY + BslashMove[r][0];
					if (searchedY < 0 || searchedY >= h) continue;
					searchedX = leftLinkedX + BslashMove[r][1];
					if (searchedX < 0 || searchedX >= w) continue;


					if (lineCheck[searchedY][searchedX] == 1) continue;//이전에 탐색됐던경우
					if (slash[searchedY][searchedX] == BslashMoverChar[r]) {//연결될수있는 경우

					   //양쪽점이 만나는경우
						if (lineCheck[searchedY][searchedX] == 2 && compareCycle % 2 == 0) {
							if (compareCycle == 1 && r == 5) continue;
							if (compareCycle > maxlength) maxlength = compareCycle;
							cycle++;

							finished = true; //bfs종료
							CheckParents(leftLinkedX, leftLinkedY, searchedX, searchedY);
							break;
						}
						else {
							QueueleftXY[0][headL % 10000] = searchedX;
							QueueleftXY[1][headL % 10000] = searchedY;
							headL++;

							lineCheck[searchedY][searchedX] = 1;
							parents[0][searchedY][searchedX] = leftLinkedY;
							parents[1][searchedY][searchedX] = leftLinkedX;

						}
					}
				}
			}

		}

		if (finished) break;

		if (headR == nearR + 1 && QueueleftXY[nearR]) repeatR = 10000;
		else if (headR > nearR) { repeatR = headR - nearR - 1; }
		else { repeatR = (9999 - nearR) + headR; }


		//<오른쪽>
		while (repeatR-- != 0) {
			rightLinkedX = QueuerightXY[0][(nearR + 1) % 10000];
			rightLinkedY = QueuerightXY[1][(nearR + 1) % 10000];
			nearR++;



			// ' / '인경우
			if (slash[rightLinkedY][rightLinkedX] == '/') {
				for (int r = 0; r < 6; r++) {
					searchedY = rightLinkedY + slashMove[r][0];
					if (searchedY < 0 || searchedY >= h) continue;
					searchedX = rightLinkedX + slashMove[r][1];
					if (searchedX < 0 || searchedX >= w) continue;


					if (lineCheck[searchedY][searchedX] == 2) continue;//이전에 탐색됐던경우
					if (slash[searchedY][searchedX] == slashMoverChar[r]) {//연결될수있는 경우

						//양쪽점이 만나는경우
						if (lineCheck[searchedY][searchedX] == 1 && compareCycle % 2 == 0) {
							if (compareCycle == 1 && r == 5) continue;
							if (compareCycle > maxlength) maxlength = compareCycle;
							cycle++;

							finished = true; //bfs종료
							CheckParents(searchedX, searchedY,rightLinkedX,rightLinkedY);
							break;
						}
						else {
							QueuerightXY[0][headR % 10000] = searchedX;
							QueuerightXY[1][headR % 10000] = searchedY;
							headR++;

							lineCheck[searchedY][searchedX] = 2;
							parents[0][searchedY][searchedX] = rightLinkedY;
							parents[1][searchedY][searchedX] = rightLinkedX;

						}
					}


				}
			}



			// '\\'인 경우
			else {
				for (int r = 0; r < 6; r++) {
					searchedY = rightLinkedY + BslashMove[r][0];
					if (searchedY < 0 || searchedY >= h) continue;
					searchedX = rightLinkedX + BslashMove[r][1];
					if (searchedX < 0 || searchedX >= w) continue;


					if (lineCheck[searchedY][searchedX] == 2) continue;//이전에 탐색됐던경우
					if (slash[searchedY][searchedX] == BslashMoverChar[r]) {//연결될수있는 경우

						//양쪽점이 만나는경우
						if (lineCheck[searchedY][searchedX] == 1 && compareCycle % 2 == 0) {
							if (compareCycle == 1 && r == 5) continue;
							if (compareCycle > maxlength) maxlength = compareCycle;
							cycle++;

							finished = true; //bfs종료
							CheckParents(searchedX, searchedY, rightLinkedX, rightLinkedY);
							break;
						}
						else {
							QueuerightXY[0][headR% 10000] = searchedX;
							QueuerightXY[1][headR % 10000] = searchedY;
							headR++;

							lineCheck[searchedY][searchedX] = 2;
							parents[0][searchedY][searchedX] = rightLinkedY;
							parents[1][searchedY][searchedX] = rightLinkedX;

						}
					}
				}
			}
		}

	}


	
}

/*
void dfs(int a, int b, int c, int depth) {
	int i, nexta, nextb, nextc;
	check[a][b][c] = depth;

	for (i = 0; i < 4; i++)
	{
		nexta = a + movee[i][0];
		nextb = b + movee[i][1];

		if (nexta < 0 || nexta >= h || nextb < 0 || nextb >= w) continue;

		nextc = -1;//??
		switch (i) {
		case 0: //-1 0 위
			if ((c == 0 && slash[a][b] == '/') || (c == 1 && slash[a][b] == '\\'))
			{
				if (slash[nexta][nextb] == '/')
					nextc = 1;
				else
					nextc = 0;
			}
			break;
		case 1: // 0 1 오
			if (c == 1)
				nextc = 0;

			break;
		case 2: // 1 0 아래
			if((c==0 && slash[a][b] == '\\') || (c==1 && slash[a][b] == '/')) // c= 0 : 원래위치의 값이 '/'이어야한다
			{
				if (slash[nexta][nextb] == '/')
					nextc = 0;
				else
					nextc = 1;
			}

			break;
		case 3: // 0 -1 왼
			if (c == 0)
				nextc = 1;

			break;
		}

		if (nextc != -1 && check[nexta][nextb][nextc])
		{
			if (check[nexta][nextb][nextc] < depth - 1) {
				cycle++;
				if (maxlength < depth)
					maxlength = depth;
			}
		}
		else if (nextc != -1)
			dfs(nexta, nextb, nextc, depth + 1);

	}
}
*/
int main()
{
	int i, j, k;
	int t = 0;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 75; j++) {
			for (k = 0; k < 75; k++) {
				parents[i][j][k] = -1;
			}
		}
	}



	cin >> w >> h;
	slash = new char*[h + 1];
	lineCheck = new int*[h];
	for (int i = 0; i < h; i++) {
		slash[i] = new char[w + 1];
		lineCheck[i] = new int[w];
		/*	for (int j = 0; j < w; j++) {
				cin >> slash[i][j];
			}*/
	}
	slash[0] = "\\//\\\\/";
	slash[1] = "\\///\\/";
	slash[2] = "//\\\\/\\";
	slash[3] = "\\/\\///";
	/*cycle = 0;
	maxlength = -1;
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			for (k = 0; k < 2; k++)
				check[i][j][k] = 0;

	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			for (k = 0; k < 2; k++)
				if (!check[i][j][k]) //탐색되지 않은상태
					dfs(i, j, k, 1);
	*/
	QueueleftXY = new int*[2];
	QueuerightXY = new int*[2];
	for (i = 0; i < 2; i++)
	{
		QueueleftXY[i] = new int[10000];
		QueuerightXY[i] = new int[10000];
	}

	for (i = 0; i < h; i++)
		for (j = 0; j < w-1; j++)
		{
			if (slash[i][j] == '/' && slash[i][j + 1] == '\\' && (lineCheck[i][j] != -2 || lineCheck[i][j+1] != -2)) {
				
				bfs(j, i, j + 1, i);
			}
		}

	printf("Maze #%d:\n", ++t);
	if (cycle) {
		
		printf("%d Cycles; the longest has length %d.\n\n", cycle, ((maxlength *2)-2)*2);

	}
	else
		printf("There are no Cycles.\n\n");

    return 0;
}

