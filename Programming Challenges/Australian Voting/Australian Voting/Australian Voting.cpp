// Australian Voting.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class voting {
public:
	int survivedN = 0;//생존자 수
	int n = 0;//후보 수
	int voter = 0; //투표자 수
	char** name;//후보자이름
	int** love;//각 투표자들의 선호도
	int* priority;//각 후보자들의 1의 갯수

	voting* nextStart;

	int Function();
	void input();
	void print(int);
};

void voting::input() {

	cin >> n;//후보 수
	name = new char*[n];

	for (int count = 0; count < n; count++)
	{
		name[count] = new char[20];
		cin>>name[count]; //후보이름
	}

	//선호도 한줄입력받으면
	//love에 기록
	//만약 두줄입력되면(한줄들여쓰기) 종료
	love = new int*[1000];
	int j = -1, i = 0;
	int swit = 0;

	while (1) {

		if (i%n == 0) {
			j++;
			love[j] = new int[n];
		}
		cin >> love[j][i%n];
		if (love[j][0] == 0) { cout << endl; break; }

		i++;
	}
	voter = j;
	priority = new int[n];
	for (i = 0; i < n; i++)priority[i] = 0;
}

int voting::Function() {
	int compareSurveved = 1;
	int i, j;
	survivedN = n;
	bool same;
	const int half = voter / 2 + voter % 2;

	//1의 갯수 비교
	for (i = 0; i < voter; i++) {
		for (j = 0; j < n; j++) {
			if (love[i][j] == 1) priority[j]++;
		}
	}

	while (1) {
		//투표수가 모두 같은 경우
		same = true;
		for (j = 0; j < n; j++)
		{
			if (priority[j] != -1 && priority[j] != -2)
				if (priority[j] != priority[compareSurveved])
				{ same = false; break; }
		}
		if (same == true) {/*모든 후보자이름 출력*/return -1; }

		//다른 경우, 1의 갯수 반이상이면
		else if (same == false) {

			for (j = 0; j < n; j++)
			{
				if (priority[j] >= half) {
					/*j번째 후보자이름 출력*/return j;
				}
			}


			//아닌 경우 1의 갯수 가장 적은 후보자 투표수 저장
			int mini = priority[compareSurveved];
			for (j = 0; j < n; j++)
			{
				if (priority[j] >= 0 && priority[j] <= mini) {
					mini = priority[j];
				}
			}

			//탈락한 후보자와 같은 갯수 있는 후보자가 있다면 함께탈락,
			for (j = 0; j < n; j++)
			{
				if (priority[j] == mini) {
					priority[j] = -1; //탈락 처리
					survivedN--;
				}
			}

			//priority에서 2로투표한 사람에게 투표 수 증가. 만약 2로 투표한 사람도 탈락했다면 3으로, 4로 ....
			int nextNum = 2;

			for (j = 0; j < n; j++)
			{
				if (priority[j] == -1) {
					for (i = 0; i < voter; i++) {
						if (love[i][j] == 1) {
							for (int second = 0; second < n; second++) {
								if (love[i%voter][second] == nextNum) {
									if (priority[second] == -1 || priority[second] == -2) {//다음 우선순위도 탈락자이면
										nextNum++; continue;
									}
									else {
										priority[second]++;//투표수 옮기기
										compareSurveved = second;//생존자 후보자번호 저장
										priority[j] = -2;//투표수 옮기기 처리된 탈락자는 -2으로 갱신
									
										break;
									}//생존자 탐색됐으면 빠저나감
								}
							}
						}
					}

				}

			}

			//생존자가 한명이면 생존자 출력
			if (survivedN == 1) {
				for (j = 0; j < n; j++)
				{
					if (priority[j] != -2 && priority[j] != -1) return j;
				}
			}

			//위의과정 반복
		}
	}
}
void voting:: print(int candi) {
	if (candi == -1)//모든 후보자 출력
	{
		for (int i = 0; i < n; i++) {
			cout << name[i] << endl;
		}
	}
	else {
		cout << name[candi] << endl;
	}
}
int main()
{
	voting *v = new voting();
	voting *start = new voting();
	start = v;
	voting *next = new voting();
	next = v;

	int num = 0;
	cin >> num;//입력케이스갯수
	int* save = new int[num];

	for (int i = 0; i < num; i++) {
		next->input();
		save[i] = next->Function();
		next->nextStart = new voting();
		next = next->nextStart;
	}

	for (int i = 0; i < num; i++) {
		start->print(save[i]);
		start = start->nextStart;
	}


	return 0;
}

