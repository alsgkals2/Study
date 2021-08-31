// LongestNap.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int partition(int left, int right, int* a) {
	int first = left;
	int pivot = a[first];
	left++;

	while (left <= right) {
		while (a[left] <= pivot && left < right) ++left;
		while (a[right] > pivot && left <= right)--right;

		if (left < right) {
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
		else break;
	}

	int temp = a[right];
	a[right] = a[first];
	a[first] = temp;
	
	return right;
}
void quickSort(int left, int right, int*a) {
	if (left < right) {
		int index = partition(left, right, a);
	
		quickSort(left, index - 1,a);
		quickSort(index + 1, right,a);
	}
}

char* itoa(int a) {
	char* forre = new char[4];

	if(a>=1000)//4자리수이면
		forre[0] = '0' + a/1000;

	if (a >= 100)//3자릿수
		forre[1] = '0' + (a % 1000) / 100;

	if (a >= 10)//2자릿수
		forre[2] = '0' + ((a % 1000) % 100)/10;

	if (a >= 10)//2자릿수
		forre[3] = '0' + ((a % 1000) % 100) % 10;

	return forre;

}
int main()
{
	//char* s = NULL;//100이하까지 가능하므로
	string S;
	int stoi_S = 0;
	
	char* inputLine =NULL;
	int* saveTime;
	int* subTime;
	int day = 1;

 	while (1) {
		//s입력받기
		inputLine = new char[256];
		//s = new char[4];
		int s = 0;
		//for (int i = 0; i < 4; i++) s[i] = '.';

		//cin.getline(s, 4);
		//scanf("%s", s);
		if (scanf("%d", &s) != EOF) {
			getchar();
		//	for (int i = 0; s[i] != '\0'; i++)
			//	S += s[i];
			//stoi_S = stoi(S);
			stoi_S = s;
			//S.clear();
			//delete[] s;
		}
		else { break; }

		int timeNum = (stoi_S * 2) + 2;
		saveTime = new int[timeNum]; //시간정보 저장
		subTime = new int[stoi_S + 1];

		int saveTimeIndex = 0;
		saveTime[saveTimeIndex++] = 1000;//처음시각

		for (int i = 0; i < stoi_S; i++) {
			//cin.ignore();
			cin.getline(inputLine,256);

			string forsaveTime;

			for (int il = 0; il < 12; il++) {
				if (inputLine[il] == ' ') {
					saveTime[saveTimeIndex] = stoi(forsaveTime);
					saveTimeIndex++; forsaveTime.clear();
					continue;
				}

				if (inputLine[il] != ':') {
					forsaveTime += inputLine[il];
				}

			}
		}
		delete[] inputLine;
		saveTime[saveTimeIndex] = 1800;//마지막시각

		quickSort(0, saveTimeIndex, saveTime);

		 //시간 차잇값구하고 최대값 가지는 인덱스구하기
		int subIndex = 0;
		int maxIndex = 0;
		for (int i = 0; i < timeNum; i += 2) {
			if (saveTime[i + 1] / 100 != saveTime[i] / 100) {
				subTime[subIndex] = ((saveTime[i + 1] - saveTime[i]) / 100) * 60;

				int mmBack = (saveTime[i + 1] % 1000) % 100;
				int mmFront = (saveTime[i] % 1000) % 100;

				if (mmFront < mmBack) {
					subTime[subIndex] += mmBack - mmFront;
				}
				else if (mmFront > mmBack) {
					subTime[subIndex] += 60 - mmFront + mmBack;
				}
			}
			else {
				subTime[subIndex] = saveTime[i + 1] - saveTime[i];
			}

			if (subTime[maxIndex] < subTime[subIndex]) maxIndex = subIndex;
			subIndex++;
		}
	
		char* toCharST = new char[5];

		toCharST = itoa(saveTime[maxIndex * 2]);
		
		string hh,mm;

		hh= toCharST[0];
		hh += toCharST[1];
		mm = toCharST[2];
		mm += toCharST[3];

		int hh_2=0, mm_2=0;

		cout << "Day #" << day << ": the longest nap starts at " << hh << ":" << mm << " and will last for ";
		//몇시간 몇분인지 구하기
		if (subTime[maxIndex] >= 60) {
			hh_2 = subTime[maxIndex] / 60;
			mm_2 = subTime[maxIndex]-(60 * hh_2);

			cout<< hh_2 <<" hours and "<<mm_2<<" minutes."<< endl;

		}
		else {
			mm_2 = subTime[maxIndex];
			cout << mm_2 << " minutes." << endl;
		}

		delete[] saveTime;
		delete[] subTime;
		delete[] toCharST;
		day++;
	}

	
	
    return 0;
}

