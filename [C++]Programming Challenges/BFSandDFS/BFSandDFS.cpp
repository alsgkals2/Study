// BFSandDFS.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int maxNodeNum = 1000;
int N, M, V;

typedef struct lnk {
	int value = -1;
	lnk* child = NULL;
	int visited = -1;
}lnk;


int head, tail = 0;
void enqueue(int* arrayQueue,int value) {
	arrayQueue[tail%1000] = value;
	tail++;
}
int dequeue(int* arrayQueue) {
	int forReturn;
	forReturn = arrayQueue[head%1000];
	arrayQueue[head % 1000] = -1;
	head++;

	return forReturn;
}
void BFS(lnk* arrayLnk,int* arrayQueue) {

}

void DFS() {

}
int search(int R, lnk* vNode,int C) {
	
	for (int i = 0; i < 1000; i++) {
		lnk* child = &vNode->child[i];
		//value값이 일치하면
		if (child->value == R) {
			lnk* childofchild = &child->child[C];
			if (childofchild->value == -1) {
				childofchild->value = C;
				return 0;
			}
		}

		//일치하지 않으면 계속탐색
		else continue;
	}
}

int main()
{
	cin >> N >> M >> V;
	int R, C;

	lnk* vNode = new lnk();
	vNode->value = V;

	for (int i = 0; i < 5; i++) {
		cin >> R >> C;

		if (vNode->value == R)
		{
			lnk* child = &vNode->child[C];
			if (child->value == -1) {
				child->value = C;
			}
		
		}
		else {
			
			search(R, vNode,C);
		}

	}

    return 0;
}

