// Color Hash.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

char finalL[13], finalR[13];

static int remaintoL[11][12] =
{ {0,0,1,0,0,0,1,0,0,0,1,0},
{0,1,0,2,0,2,0,1,0,0,0,0},
{1,0,2,0,3,0,2,0,1,0,0,0},
{0,0,0,0,0,1,0,2,0,2,0,1},
{1,0,0,0,1,0,2,0,3,0,2,0},
{0,2,0,1,0,0,0,0,0,1,0,2},
{3,0,2,0,1,0,0,0,1,0,2,0},
{0,2,0,3,0,4,0,3,0,2,0,1},
{3,0,4,0,5,0,4,0,3,0,2,0},
{0,3,0,4,0,3,0,2,0,1,0,2},
{3,0,4,0,4,0,3,0,2,0,2,0} };

static int remaintoR[11][12] =
{ {0,0,1,0,0,0,1,0,0,0,1,0},
{ 0,1,0,2,0,2,0,1,0,0,0,0 },
{ 1,0,2,0,3,0,2,0,1,0,0,0 },
{ 0,2,0,3,0,4,0,3,0,2,0,1 },
{ 3,0,4,0,5,0,4,0,3,0,2,0 },
{ 0,3,0,4,0,3,0,2,0,1,0,2 },
{ 3,0,4,0,4,0,3,0,2,0,2,0 },
{ 0,0,0,0,0,1,0,2,0,2,0,1 },
{ 1,0,0,0,1,0,2,0,3,0,2,0 },
{ 0,2,0,1,0,0,0,0,0,1,0,2 },
{ 3,0,2,0,1,0,0,0,1,0,2,0 }};


void initFinal(char* L, char* R) {
	L[8]=L[4]=L[0] = 0;
	L[3]=L[1] = 3;
	L[2] = 4;
	L[7]=L[5] = 5;
	L[6] = 6;
	L[11]=L[9] = 1;
	L[10] = 2;

	R[8] = R[4] = R[0] = 0;
	R[3]=R[1] = 7;
	R[2] = 8;
	R[7]=R[5] = 9;
	R[6] = 10;
	R[9] = R[11] = 1;
	R[10] = 2;
}



int cSuccessNum = 17;
void CulMinimumDistance(char* leftN, char* rightN, int& minimumD, int leftSpot, int rightSpot) {
	int i;
	int returnminimum = 0;
	int saveLs = leftSpot;
	int saveRs = rightSpot;
	i = 0;
	for (; saveLs<12; i++,saveLs++)
	{
		if (minimumD < remaintoL[leftN[saveLs]][i])
			minimumD = remaintoL[leftN[saveLs]][i];
	}
	for (int s = 0; s < leftSpot; s++,i++)
	{
		if (minimumD < remaintoL[leftN[s]][i])
			minimumD = remaintoL[leftN[s]][i];
	}

	i = 0;
	for (; saveRs < 12; i++, saveRs++)
	{
		if (minimumD < remaintoR[rightN[saveRs]][i])
			minimumD = remaintoR[rightN[saveRs]][i];
	}
	for (int s = 0; s < rightSpot; s++, i++)
	{
		if (minimumD < remaintoR[rightN[s]][i])
			minimumD = remaintoR[rightN[s]][i];
	}
}



bool JudgeMetching(char* leftN, char* rightN,int leftSpot, int rightSpot) {
	int i = 0;
	int spot;
	for (spot = leftSpot; spot < 12; spot++) {
		if (finalL[i++] != leftN[spot]) return false;
		//if (leftN[i] != finalL[i] || rightN[i] != finalR[i]) return false;
	}
	for (spot = 0; spot < leftSpot; spot++) {
		if (finalL[i++] != leftN[spot]) return false;
	}
	i = 0;
	for (spot = rightSpot; spot < 12; spot++) {
		if (finalR[i++] != rightN[spot]) return false;
	}
	for (spot = 0; spot < rightSpot; spot++) {
		if (finalR[i++] != rightN[spot]) return false;
	}

	return true;
}

void output() {}
//시계방향 회전
void left(int &spot) {
	if (spot - 2 < 0) spot = spot - 2 + 12;
	else spot = spot - 2;
}


//반시계 방향 회전
void right(int &spot) {
	if (spot + 2 >= 12) spot = spot + 2 - 12;
	else spot = spot + 2;
}

char finalSaveNum[17];

void back(char* beforL, char *beforR,int count,char *beforSaveNum,int beforI,int leftSpot,int rightSpot) {
	char saveNum[17];
	

	for (int i = 0; i < count; i++) saveNum[i] = beforSaveNum[i];
	
	if ( JudgeMetching(beforL, beforR,leftSpot,rightSpot)) {
		cSuccessNum = count;
		for (int s = 0; s < 17; s++) {
			if (s < count) finalSaveNum[s] = saveNum[s];
			else {
				finalSaveNum[s] = '.';
			}
		}
	}
	else {

		//count+최소회전값이 successNum보다 크면 return가지치기
		int minimumD = 0;
		CulMinimumDistance(beforL, beforR, minimumD, leftSpot, rightSpot);


		for (int num = 1; num <= 4 && count+minimumD<cSuccessNum; num++) {
			//1->3, 2->4와같이 다시 제자리로 가는경우 가지치기
			if ((beforI == 1 && num == 3) || (beforI == 3 && num == 1) || (beforI == 2 && num == 4) || (beforI == 4 && num == 2)) continue;

			//6회연속으로 같은 i값들어가면 제자리이므로 가지치기
			bool continueSw = false;
			for (int s = count - 1; s > count - 1 - 5; s--)
			{
				if (saveNum[s] != num) { continueSw = true; break; }
			}
			if (continueSw == false) continue;

			////////////////////
			saveNum[count] = num;
		///////회전
			int i;
			int leftIndex, rightIndex;


			switch (num)
			{
				//왼쪽바퀴는 시계방향으로
			case 1:
				left(leftSpot);
				
				//spot옮겨지고나서 마지막3개값 수정
				for (int a = 1; a <= 3; a++) {
					if (rightSpot - a < 0) rightIndex = rightSpot - a + 12;
					else rightIndex = rightSpot - a;
					if (leftSpot - a < 0) leftIndex = leftSpot - a + 12;
					else leftIndex = leftSpot - a;

					beforR[rightIndex] = beforL[leftIndex];
				}

				back(beforL, beforR, count + 1, saveNum, num, leftSpot, rightSpot);

				right(leftSpot);
				//마지막3개값 다시돌려놓기(그다음 rotation을 위해)
				for (int a = 1, index = 2; a <= 3; a++, index--) {
					if (rightSpot - a < 0) rightIndex = rightSpot - a + 12;
					else rightIndex = rightSpot - a;

					if (leftSpot - a < 0) leftIndex = leftSpot - a + 12;
					else leftIndex = leftSpot - a;

					beforR[rightIndex] = beforL[leftIndex];
				}

				break;

				//오른쪽 바퀴를 시계방향으로
			case 2:
				right(rightSpot);
				
				//spot옮겨지고나서 마지막3개값 수정
				for (int a = 1; a <= 3; a++) {
					if (rightSpot - a < 0) rightIndex = rightSpot - a + 12;
					else rightIndex = rightSpot - a;
					if (leftSpot - a < 0) leftIndex = leftSpot - a + 12;
					else leftIndex = leftSpot - a;

					beforL[leftIndex] = beforR[rightIndex];
				}

				back(beforL, beforR, count + 1, saveNum, num, leftSpot, rightSpot);

				left(rightSpot);
				//마지막3개값 다시돌려놓기(그다음 rotation을 위해)
				for (int a = 1, index = 2; a <= 3; a++, index--) {
					if (rightSpot - a < 0) rightIndex = rightSpot - a + 12;
					else rightIndex = rightSpot - a;

					if (leftSpot - a < 0) leftIndex = leftSpot - a + 12;
					else leftIndex = leftSpot - a;

					beforL[leftIndex] = beforR[rightIndex];
					//beforL[leftIndex] = originLastNum[index];
				}

				break;


				//왼쪽 바퀴는 반시계방향으로
			case 3:
				right(leftSpot);
				
				//spot옮겨지고나서 마지막3개값 수정
				for (int a = 1; a <= 3; a++) {
					if (rightSpot - a < 0) rightIndex = rightSpot - a + 12;
					else rightIndex = rightSpot - a;
					if (leftSpot - a < 0) leftIndex = leftSpot - a + 12;
					else leftIndex = leftSpot - a;

					beforR[rightIndex] = beforL[leftIndex];
				}

				back(beforL, beforR, count + 1, saveNum, num, leftSpot, rightSpot);

				left(leftSpot);
				//마지막3개값 다시돌려놓기(그다음 rotation을 위해)
				for (int a = 1, index = 2; a <= 3; a++, index--) {
					if (rightSpot - a < 0) rightIndex = rightSpot - a + 12;
					else rightIndex = rightSpot - a;

					if (leftSpot - a < 0) leftIndex = leftSpot - a + 12;
					else leftIndex = leftSpot - a;

					beforR[rightIndex] = beforL[leftIndex];
					//beforL[leftIndex] = originLastNum[index];
				}

				break;

			case 4:
				left(rightSpot);

				//spot옮겨지고나서 마지막3개값 수정
				for (int a = 1; a <= 3; a++) {
					if (rightSpot - a < 0) rightIndex = rightSpot - a + 12;
					else rightIndex = rightSpot - a;
					if (leftSpot - a < 0) leftIndex = leftSpot - a + 12;
					else leftIndex = leftSpot - a;

					beforL[leftIndex] = beforR[rightIndex];
				}

				back(beforL, beforR, count + 1, saveNum, num, leftSpot, rightSpot);

				right(rightSpot);
				//마지막3개값 다시돌려놓기(그다음 rotation을 위해)
				for (int a = 1, index = 2; a <= 3; a++, index--) {
					if (rightSpot - a < 0) rightIndex = rightSpot - a + 12;
					else rightIndex = rightSpot - a;

					if (leftSpot - a < 0) leftIndex = leftSpot - a + 12;
					else leftIndex = leftSpot - a;

					beforL[leftIndex] = beforR[rightIndex];
				}

				break;
			}
		
}
	}
}


bool CheckException(char* inputL, char* inputR) {
	for (int i = 0; i < 12; i++) {
		if (inputL[i] != finalL[i]) return false;
		if (inputR[i] != finalR[i]) return false;
	}
	return true;
}

bool CheckException(char* finalSaveNum) {
	for (int i = 0; i < 17; i++)
		if (finalSaveNum[i] != '.') return false;

	return true;
}
int main()
{
	initFinal(finalL, finalR);
	char inputL[13], inputR[13];
	int num;
	int i;
	int TC;

	cin >> TC;

	while (TC-- != 0) {

		for (i = 0; i < 17; i++) finalSaveNum[i] = '.';
		for (i = 0; i < 12; i++) {
			cin >> num;
			inputL[i] = num;
		}
		for (i = 0; i < 12; i++) {
			cin >> num;
			inputR[i] = num;;
		}

		if (CheckException(inputL, inputR))cout << "PUZZLE ALREADY SOLVED" << '\n';
		else {
			back(inputL, inputR, 0, finalSaveNum, 0, 0, 0);
			if (CheckException(finalSaveNum)) cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << '\n';
			else {
				for (i = 0; finalSaveNum[i] != '.'; i++) {
					printf("%d", finalSaveNum[i]);
				}
				cout << '\n';
			}

		}

	}
    return 0;
}

