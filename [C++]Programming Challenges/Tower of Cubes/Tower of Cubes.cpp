// Tower of Cubes.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const char* fblrtb[6] = {"front","back","left","right","top","bottom"};

int checkProcess[500][500];
int output1[500];
int output2[500];
int cubeN;
int saveInform[500][6];
int resultCount = 0;
bool finished = false;
int cubeInformNum[500];

void init(int copyCN) {
	for (int i = 0; i < copyCN; i++)
	{
		for (int j = 0; j < copyCN; j++)
		{
			checkProcess[i][j] = 0;
		}
	}

	for (int i = 0; i < resultCount; i++) {
		output1[i] = 0;
		output2[i] = 0;
	}

	resultCount = 0;
}

void dfs(int topNum,int cubeNum,int fblrtb,int count) {
	static int copyoutput1[500];
	static int copyoutput2[500];

	if (cubeNum + count < resultCount)
		return;

	bool endSw = false;

	copyoutput1[count - 1] = fblrtb;//count-1 : count가 처음부터 1로시작하므로
	copyoutput2[count - 1] = cubeNum;

	for (int i = cubeNum - 1; i >= 0; i--) {
		for (int six = 0; six < cubeInformNum[i]; six = six + 2) {
			if (saveInform[i][six + 1] == topNum &&checkProcess[saveInform[i][six + 1]][saveInform[i][six]] != 0) //0이아니면
			{
				checkProcess[saveInform[i][six + 1]][saveInform[i][six]] --;

				//윗면정보 전달
				dfs(saveInform[i][six], i, six, count + 1);
				checkProcess[saveInform[i][six + 1]][saveInform[i][six]] ++;
				//if (finished) {i = -1; break; }

				endSw = true;
			}
			if (saveInform[i][six] == topNum && checkProcess[saveInform[i][six]][saveInform[i][six + 1]] != 0) //0이아니면
			{
				checkProcess[saveInform[i][six]][saveInform[i][six + 1]] --;

				//윗면정보 전달
				dfs(saveInform[i][six + 1], i, six + 1, count + 1);
				checkProcess[saveInform[i][six]][saveInform[i][six + 1]] ++;
				//if (finished) {i = -1; break;}
				endSw = true;
			}


		}
	}

	if (endSw == false && count > resultCount) {
		for (int i = 0; i < count; i++) {
			output1[i] = copyoutput1[i];
			output2[i] = copyoutput2[i];
		}
		resultCount = count;
	}

}


int main()
{
	int num1, num2;
	int TC = 1;
	int index = 0;
	bool Check = false;
	while (1) {
		int copyCN = cubeN;
		cin >> cubeN;

		if (cubeN == 0) break;

		init(copyCN);
			for (int i = 0; i < cubeN; i++) {
			 index = 0;
			 for (int j = 0; j < 3; j++)
			 {
				 Check = false;

				 cin >> num1 >> num2;

				 //중복검사
				 for (int c = 0; c < index; c = c + 2)
					 if ((num1 == saveInform[i][c] && num2 == saveInform[i][c + 1]) ||
						 (num2 == saveInform[i][c] && num1 == saveInform[i][c + 1]))
						 Check = true;

				 //중복되지 않으면
				 if (!Check) {
					 saveInform[i][index++] = num1;
					 saveInform[i][index++] = num2;
					 checkProcess[num1][num2]++; //패턴갯수들 저장
					 checkProcess[num2][num1]++;
					 cubeInformNum[i] += 2; //갯수카운팅
				 }
			 }
		}


		for (int i = cubeN - 1; i >= 0; i--) {
			for (int j = 0; j < cubeInformNum[i]; j = j + 2) {
				if (checkProcess[saveInform[i][j + 1]][saveInform[i][j]] != 0) //0이아니면
				{
					checkProcess[saveInform[i][j + 1]][saveInform[i][j]] --;
					//윗면정보 전달
					dfs(saveInform[i][j], i, j, 1);

				}
				if (checkProcess[saveInform[i][j]][saveInform[i][j + 1]] != 0) //0이아니면
				{

					checkProcess[saveInform[i][j]][saveInform[i][j + 1]] --;
					//윗면정보 전달
					dfs(saveInform[i][j + 1], i, j + 1, 1);

				}


			}

		}

		cout << "CASE #" << TC++ << '\n';
		cout << resultCount << '\n';
		for (int i = resultCount - 1; i >= 0; i--) {

			cout << output2[i] + 1 << ' ';
			cout << fblrtb[output1[i]] << '\n';
		}
		cout << '\n';
	}
    return 0;

}