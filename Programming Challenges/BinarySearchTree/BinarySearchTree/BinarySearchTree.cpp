// BinarySearchTree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

typedef struct node {
	int load = 0;
	int value = 0;
	node * leftnode = NULL;
	node * rightnode = NULL;
};

node* insert(node X, node* N,int &C) {
	

	if (X.value < N->value) { //부모노드보다 작을때
		if (!N->leftnode) {
			N->leftnode = new node();
			N->leftnode->value = X.value;
			C=N->leftnode->load = (N->load)+1;
			return N->leftnode;
		}
		else {//왼쪽자식이 존재한다면
			N = N->leftnode;
			insert(X, N, C);
		}
	}
	else{//부모노드보다 클때
		if (!N->rightnode) {
			N->rightnode = new node();
			N->rightnode->value = X.value;
			C = N->rightnode->load = (N->load) + 1;
			return N->rightnode;
		}
		else {//오른쪽자식이 존재한다면
			N = N->rightnode;
			insert(X, N, C);
		}
	}
}

int main()
{
	int num = 0;
	cin >> num;
	int* outputC = new int[num];

	int xNodeValue = 0;
	node X ;
	node maxrootNode;


	//최상위노드 생성
	cin >> xNodeValue;
	maxrootNode.value = xNodeValue;
	maxrootNode.load = 0;
	outputC[0] = 0;


	//바로 탐색을 위해 주소저장하기 위한 saveNode
	node ** saveNode = new node*[num+1];
	for (int i = 0; i < num+1; i++) {
		saveNode[i] = NULL;
	}
	saveNode[xNodeValue] = &maxrootNode;


	//시작할노드 saveNode에서 탐색
	
	int closeDistance = num;
	int closeElement = 0;
	int addElementSpot = 1;
	int distance = 0;
	for(int j=1,i=0; j<num; j++){
		cin >> xNodeValue;
		X.value = xNodeValue;
		i = 1;

		while (1) {
			if (X.value +i<num+1 && saveNode[X.value + i] != NULL) {
					closeElement = xNodeValue + i;
					break;
			}
			else if (X.value -i>0 && saveNode[X.value - i] != NULL) {
				closeElement = xNodeValue - i;
				break;
			}
			i++;
		}
		
		outputC[j] = outputC[j - 1];
		saveNode[X.value]=insert(X, saveNode[closeElement], outputC[j]);
	}

	cout << outputC[0] << endl;
	for (int i = 1; i < num; i++)
	{
		outputC[i] = outputC[i - 1] + outputC[i];
		cout << outputC[i] << endl;
	}
    return 0;
}

