// Playing With Wheels.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int prohibitedCheck[10][10][10][10];
bool discoveriedG[4][10];

int AttechNum(short[]);

typedef struct queue {
	short Q[10001];
	int head=1;
	int near=0;
	int size = 0;
}Queue;
void enQueue(Queue& q,short value){	
	q.Q[q.head% 10001] = value;
	q.head++;
	q.size++;
}

short deQueue(Queue& q) {
	short forReturn;
	forReturn = q.Q[(q.near+1)% 10001];
	q.near++;
	q.size--;
	return forReturn;
}
bool EnterEmpty(Queue q) {
	if (q.near == q.head - 1)
		return true; // 큐가 비었다.
	return false;
}

void initializeArray(int pcheck[10][10][10][10]) {
	for (int a = 0; a < 10; a++)
		for(int b=0; b<10; b++)
			for(int c=0; c<10; c++)
				for(int d=0; d<10; d++)
					pcheck[a][b][c][d] = 0;

	
	
}

void initializeQ(Queue *q) {
	for (int i = 0; i < 4; i++) {
		q[i].head = 1;
		q[i].near = 0;
		q[i].size = 0;
	}
}


short finaln[4];

bool isSolution(short input[]) {
	if (input[0]== finaln[0] && input[1]== finaln[1] && input[2]== finaln[2] && input[3]== finaln[3]) {
		return true;
	}
	return false;
}

void Rotatleft(short& number) {
	if (number + 1 > 9) number = 0;
	else number += 1;
}
void Rotatright(short& number) {
	if (number - 1 < 0) number = 9;
	else number -= 1;
}

Queue *q = new Queue[4];

int bfs(short input[]) {

	int count = 0;
	//int index;

	if (isSolution(input))
		return 1;

	while (!EnterEmpty(q[0]) && prohibitedCheck[finaln[0]][finaln[1]][finaln[2]][finaln[3]] == 0)
	{
		input[0] = deQueue(q[0]);
		input[1] = deQueue(q[1]);
		input[2] = deQueue(q[2]);
		input[3] = deQueue(q[3]);

		count = prohibitedCheck[input[0]][input[1]][input[2]][input[3]];

		
		for (int i = 0; i < 4; i++) {

			Rotatleft(input[i]);
			if (prohibitedCheck[input[0]][input[1]][input[2]][input[3]] == 0) {
				enQueue(q[0], input[0]);
				enQueue(q[1], input[1]);
				enQueue(q[2], input[2]);
				enQueue(q[3], input[3]);
				prohibitedCheck[input[0]][input[1]][input[2]][input[3]] = count + 1;
			}
			Rotatright(input[i]);

			Rotatright(input[i]);
			if (prohibitedCheck[input[0]][input[1]][input[2]][input[3]] == 0) {
				enQueue(q[0], input[0]);
				enQueue(q[1], input[1]);
				enQueue(q[2], input[2]);
				enQueue(q[3], input[3]);
				prohibitedCheck[input[0]][input[1]][input[2]][input[3]] = count + 1;
			}
			Rotatleft(input[i]);
		}
	}

	int forreturn = prohibitedCheck[finaln[0]][finaln[1]][finaln[2]][finaln[3]];
	if (forreturn == 0) { return 0; }
	return forreturn;
}


int main()
{
	int TC;
	short input[4],p_input[4];
	short p_one, p_two, p_three, p_four;
	int prohibitedNum;
	
	cin >> TC;
	cout << '\n';
	while (TC-- != 0) {


		initializeArray(prohibitedCheck);
		initializeQ(q);
		cin >> input[0] >> input[1] >> input[2] >> input[3];
		cin >> finaln[0] >> finaln[1] >> finaln[2] >> finaln[3];
		cin >> prohibitedNum;

		for (int i = 0; i < prohibitedNum; i++)
		{
			cin >> p_input[0] >> p_input[1] >> p_input[2] >> p_input[3];
			prohibitedCheck[p_input[0]][p_input[1]][p_input[2]][p_input[3]] = -1;
		}

		enQueue(q[0], input[0]);
		enQueue(q[1], input[1]);
		enQueue(q[2], input[2]);
		enQueue(q[3], input[3]);
		prohibitedCheck[input[0]][input[1]][input[2]][input[3]] = 1;

		cout << bfs(input) - 1 << '\n'<<'\n';
	}
    return 0;
}

