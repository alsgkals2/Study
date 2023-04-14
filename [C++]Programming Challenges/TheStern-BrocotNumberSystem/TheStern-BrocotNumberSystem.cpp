// TheStern-BrocotNumberSystem.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
//방향설정
int DirectionOption(int cTop, int cBottom,int top,int bottom) {
	//리턴값이 1이면 L방향,2이면 R방향
	if (top*cBottom > cTop*bottom) return 2;//R
	return 1;//L
}

//노드정보 갱신(R이 갱신된거면 R수정, L이 갱신된거면 L수정)
void Edit(node& RorL,int top, int bottom) {
	RorL.topNum = top;
	RorL.bottomNum = bottom;
}

//그 방향의 값구하기

int main()
{
	node R ;
	node L;

	int top = 0, bottom = 0;
	while (1) {
		cin >> top >> bottom;
		if (top == 1 && bottom == 1) break;
		init_node(R, L);//맨처음노드들 초기화
		string RLinform;

		//현재노드의 값
		int current_top = 0;
		int current_bottom = 0;

		while (1) {
			current_top = R.topNum + L.topNum;
			current_bottom = R.bottomNum + L.bottomNum;

			if (current_top == top && current_bottom == bottom) break;
			//노드정보 갱신(R이 갱신된거면 R수정, L이 갱신된거면 L수정)
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

