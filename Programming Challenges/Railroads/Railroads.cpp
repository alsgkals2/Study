// Railroads.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

/*int Partition(char** a, int left, int right) {

	char* temp = new char[100];
	int iTemp;

	int first = left;
	left++;

	while (left < right) {
		
		while (strcmp(a[left], a[first]) < 0 && left <= right) left++;
		while (strcmp(a[right], a[first]) >= 0 && left < right) right--;
	

		if (left < right) {
			temp = a[right];
			a[right] = a[left];
			a[left] = temp;
		}
	}

		temp = a[first];
		a[first] = a[right];
		a[right] = temp;

	return right;
}
void QuickSort(char** a, int left, int right) {
	int index;

	if (left < right) {
		index = Partition(a, left, right);
		QuickSort(a, 0, index - 1);
		QuickSort(a, index+1, right);
	}
}
*/

/*int BinarySearch(char** a, char* word, int left, int right) {
	int middle;
	int str;

	while (left <= right) {

	middle = (left + right) / 2;
	str = strcmp(word, a[middle]);

		if (str < 0) {
			right = middle - 1;
		}
		else if (str > 0) {
			left = middle + 1;
		}
		else if (str == 0) {
			return middle;
		}
	}
}

*/
char *cityName[100];
int tn[1000];
int train[100][1000][2];
int minTime;

void init(int** mti,bool* ck)
{
	for (int i = 0; i < 100; i++) {
		mti[i] = new int[2];
		mti[i][0] = 9999;
		mti[i][1] = -1;

		ck[i] = false;
	}

}
static int* minimumTime[100];

int shortDJS(int startI,int endI,int N, int T) {
	static bool ck[100];
	int index;
	init(minimumTime, ck);
	
	index = startI;
	minimumTime[index][0] = minTime;
	

	while (index != -1) {
		ck[index] = true;

		for (int t = 0; t < T; t++) {
			for (int ran = 0; ran < tn[t] - 1; ran++) {
				if (index == train[t][ran][1] && train[t][ran][0] >= minimumTime[index][0])
	
				{
					if (minimumTime[train[t][ran + 1][1]][0] > train[t][ran + 1][0])//다익스트라
						minimumTime[train[t][ran + 1][1]][0] = train[t][ran + 1][0];


				}
			}
		}
		index = -1;
		for (int n = 0; n < N; n++) {
			if (ck[n] == false && (index == -1 || minimumTime[index][0] > minimumTime[n][0])) {
				index = n;
			}
		}

		if (minimumTime[index][0] == 9999) return 1;
	}

	if (minimumTime[endI][0] == 9999) return 1; //목적지까지 도달할 수 없는경우

	index = endI;
	minimumTime[index][1] = minimumTime[index][0];

	
	while (index != -1) {
		ck[index] = false;

		for (int t = 0; t < T; t++) {
			for (int ran = 1; ran < tn[t]; ran++) {
				if (index == train[t][ran][1] && train[t][ran][0] <= minimumTime[index][1])
				{
					if (minimumTime[train[t][ran - 1][1]][1] < train[t][ran - 1][0])//다익스트라
						minimumTime[train[t][ran - 1][1]][1] = train[t][ran - 1][0];
				}
			}
		}

		index = -1;
		for (int n = 0; n < N; n++) {
			if (ck[n] == true && (index == -1 || minimumTime[index][1] < minimumTime[n][1])) {
				index = n;
			}
		}

	}


	return 0;
}

int FindIndex(char** cn,char* word,int C) {
	for (int i = 0; i < C; i++) {
		if (strcmp(cn[i], word) == 0) {
			return i;
		}
	}
}


int main()
{
	int TC;
	int C, T;
	int i;
	char* cityN = new char[100];
	int startI, endI;
	for (i = 0; i < 100; i++) {
		cityName[i] = new char[100];
	}
	
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {

		cin >> C;
		for (i = 0; i < C; i++) {

			cin >> cityName[i];
		}
		//QuickSort(cityName, 0, C - 1);

		cin >> T;
		for (i = 0; i < T; i++) {
			cin >> tn[i];

			for (int j = 0; j < tn[i]; j++) {
				cin >> train[i][j][0];
				cin >> cityN;
				//train[i][j][1] = BinarySearch(cityName, cityN, 0, C - 1);
				train[i][j][1] = FindIndex(cityName, cityN, C);
			}
		}

		cin >> minTime;
		cin >> cityN;
		//startI = BinarySearch(cityName, cityN, 0, C - 1);
		startI = FindIndex(cityName, cityN, C);

		cin >> cityN;
		//endI = BinarySearch(cityName, cityN, 0, C - 1);
		endI = FindIndex(cityName, cityN, C);

	
		cout << "Scenario " << tc << '\n';
		if (shortDJS(startI, endI, C, T)) {
			cout << "No connection" << '\n';
		}
		else {
			printf("Departure %04d %s\n", minimumTime[startI][1], cityName[startI]);
			printf("Arrival   %04d %s\n", minimumTime[endI][0], cityName[endI]);

		}


		cout << '\n';
	}


    return 0;
}

