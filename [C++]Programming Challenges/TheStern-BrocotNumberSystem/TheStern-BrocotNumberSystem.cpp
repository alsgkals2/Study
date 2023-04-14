// TheStern-BrocotNumberSystem.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


typedef struct node{
	int topNum = 0;
	int bottomNum = 0;
	node* nextN = NULL;
}node;

void init_node(node &R, node &L)
{
	R.topNum = 0;
	R.bottomNum = 1;

	L.topNum = 1;
	L.bottomNum = 0;
}
//���⼳��
int DirectionOption(int cTop, int cBottom,int top,int bottom) {
	//���ϰ��� 1�̸� L����,2�̸� R����
	if (top*cBottom > cTop*bottom) return 2;//R
	return 1;//L
}

//������� ����(R�� ���ŵȰŸ� R����, L�� ���ŵȰŸ� L����)
void Edit(node& RorL,int top, int bottom) {
	RorL.topNum = top;
	RorL.bottomNum = bottom;
}

//�� ������ �����ϱ�

int main()
{
	node R ;
	node L;

	int top = 0, bottom = 0;
	while (1) {
		cin >> top >> bottom;
		if (top == 1 && bottom == 1) break;
		init_node(R, L);//��ó������ �ʱ�ȭ
		string RLinform;

		//�������� ��
		int current_top = 0;
		int current_bottom = 0;

		while (1) {
			current_top = R.topNum + L.topNum;
			current_bottom = R.bottomNum + L.bottomNum;

			if (current_top == top && current_bottom == bottom) break;
			//������� ����(R�� ���ŵȰŸ� R����, L�� ���ŵȰŸ� L����)
			if (DirectionOption(current_top, current_bottom, top, bottom) == 2) {
				Edit(R, current_top, current_bottom);
				RLinform += 'R';
			}
			else {
				Edit(L, current_top, current_bottom);
				RLinform += 'L';
			}
		}

		cout << RLinform << endl;
	}
	return 0;
}

