// 15-Puzzle Problem.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <string>
#include <set>

using namespace std;


set<char*> visited;
queue<char*> currentList;

void copyChar(char* a, char* b) {
	for (int i = 0; i < 9; i++)
		b[i] = a[i];
}

bool Compare(char* currentState) {
	int num = '1';
	int i = 0;
	for (; currentState[i] == num + i && i < 8; i++)
	{
	}

	if(i==8 && currentState[i] == '0')
		return true;

	return false;
}
bool continueSW = false;


void swap(char* &st, int index1, int index2)
{
	char temp = st[index1];
	st[index1] = st[index2];
	st[index2] = temp;
}

/*bool JudgeSolve()
{
	
}*/

char* currentS = new char[10];
char* copyCurrent = new char[10];

void BFS_puzzle(queue<char*> &currentList, int & count)
{
	//검사
	int queueSize = currentList.size();
	//queue<string> copycurrentList = currentList;
	//char* currentS;
	currentS = new char[10];
	currentS[9] = '\0';

	for (int i = 0; i < queueSize; i++)
	{
		//currentS = currentList.front();
		copyChar(currentList.front(),currentS);
		visited.insert(currentS);

		if (Compare(currentS))
		{
			cout << count;
			continueSW = true;
			return;
		}

		currentList.pop();
	//}

	//count++;
	//for (int i = 0; i < queueSize; i++)
	//{
		//currentS = copycurrentList.front();

		//검사통과 안될경우
		//copycurrentList.pop();//맨오른쪽 데이터 pop
		int zeroSpot = 0;
		//string copyCurrent;

		//currentS에서 0탐색
		for (; currentS[zeroSpot] != '0'; zeroSpot++) {
		}

		//교환
		//정상작동하면 하나로 합치기!
		if (zeroSpot % 3 - 1 >= 0)//왼쪽교환가능
		{
			//copyCurrent = currentS;
			copyCurrent = new char[10];
			copyCurrent[9] = '\0';

			copyChar(currentS, copyCurrent);
			swap(copyCurrent, zeroSpot, zeroSpot - 1);

			if (visited.find(copyCurrent) == visited.end())
				currentList.push(copyCurrent);

		}
		if (zeroSpot % 3 + 1 < 3)//오른쪽교환가능
		{
			//copyCurrent = currentS;
			copyCurrent = new char[10];
			copyCurrent[9] = '\0';

			copyChar(currentS, copyCurrent);
			swap(copyCurrent, zeroSpot, zeroSpot + 1);

			if (visited.find(copyCurrent) == visited.end())
				currentList.push(copyCurrent);
		}
		if (zeroSpot - 3 >= 0) //위로 교환가능
		{
			//copyCurrent = currentS;
			copyCurrent = new char[10];
			copyCurrent[9] = '\0';

			copyChar(currentS, copyCurrent);
			swap(copyCurrent, zeroSpot, zeroSpot - 3);

			if (visited.find(copyCurrent) == visited.end())
				currentList.push(copyCurrent);
		}
		if (zeroSpot + 3 < 9) // 아래로 교환가능
		{
			//copyCurrent = currentS;
			copyCurrent = new char[10];
			copyCurrent[9] = '\0';

			copyChar(currentS, copyCurrent);
			swap(copyCurrent, zeroSpot, zeroSpot + 3);

			if (visited.find(copyCurrent) == visited.end())
				currentList.push(copyCurrent);


		}
	}

	//delete currentS;
}



int main()
{
	char* input = new char[10];
	char num;
	int count = 0;
	currentS[9] = '\0';
	copyCurrent[9] = '\0';

	for (int i = 0; i < 9; i++)
	{
		cin >> input[i];
	}

	currentList.push(input);

	while (!currentList.empty() && continueSW == false) {
		BFS_puzzle(currentList, count);
		count++;
	}

	if (continueSW == false) cout << -1;

	return 0;
}
