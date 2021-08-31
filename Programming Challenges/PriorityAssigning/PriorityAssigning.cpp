// PriorityAssigning.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct inform {
	string firstName;
	string secondName;
	int height;
	int weight;
};

int nameSort(string a, string b) {
	//1:a가 우선 2:b가 우선 -1:모두 일치
	int count;
	count = a.size() > b.size() ? b.size() : a.size();//작은크기 count에 저장
	for (int i = 0; i < count; i++) {
		if (a.at(i) < b.at(i)) {
			return 1;
		}
		else if (a.at(i) > b.at(i)) {
			return 2;
		}
	}
	//모두 일치
	return -1;
}

void swap(inform& a, inform& b) {
	inform forTemp;
	forTemp = b;
	b = a;
	a = forTemp;
}
int main()
{
	int count = 0;
	int inputNum = 0;
	inform** inf = new inform*[100];
	cin >> inputNum;



	for (int i = 0; i < inputNum; i++) {
		inf[i] = new inform();
		cin >> inf[i]->firstName >> inf[i]->secondName >> inf[i]->height >> inf[i]->weight;
		inf[i]->height = inf[i]->height - 180;
		inf[i]->weight = inf[i]->weight- 75;
	
		//키 정렬
		inform* forTemp;
		for (int j = i; j > 0; j--) {
			if (abs(inf[j]->height) < abs(inf[j - 1]->height)) {
				swap(inf[j - 1], inf[j]);
				}
			//몸무게 정렬
			else if (abs(inf[j]->height) == abs(inf[j - 1]->height)) {
				int jj = inf[j]->weight; int j_1 = inf[j - 1]->weight;

				if (abs(jj) < abs(j_1)) {
					if (!(jj >0 && j_1 < 0)) {
						swap(inf[j - 1], inf[j]);
					}

				}
				else if (abs(jj) == abs(j_1)) {
					if (jj == j_1) {
						int r = nameSort(inf[j]->firstName, inf[j - 1]->firstName);
						if (r == 1)//swap
						{
							swap(inf[j - 1], inf[j]);
						}
						else if (r == 3) {
							if (nameSort(inf[j]->secondName, inf[j - 1]->secondName) == 1) { //두번째이름으로 비교
								swap(inf[j - 1], inf[j]);
							}
						}
					}//몸무게같은경우, 이름순으로 정렬
					else if (jj < 0 && j_1>0)
					{
						swap(inf[j - 1], inf[j]);
					}
				}
			}
			else break;
		}
	}








    return 0;
}

