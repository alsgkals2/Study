// Tree's Parents Search.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <iostream>

using namespace std;

typedef struct node {
	int value = 0;
	node* parentNode = NULL;
	node* leftNode = NULL;
	node* rightNode = NULL;
	int enter = 0;
}node;
node* beforenode;
bool befor_sweet = false;

void presearch(node* parent, int parentValue,int childValue) {//중왼오
	if (parent->value == parentValue) {
		beforenode = parent;//이전노드 저장(배열에서 못찾는것을 대비해서)
		if (!parent->leftNode) {
			parent->leftNode = new node();
			parent->leftNode->parentNode = parent;
			parent = parent->leftNode;
			parent->value = childValue;
		}
		else if (!parent->rightNode) {
			parent->rightNode = new node();
			parent->rightNode->parentNode = parent;
			parent = parent->rightNode;
			parent->value = childValue;
		}
	}
	else if (parent->value != parentValue) {
		parent->enter = childValue;

		if (parent->leftNode && parent->leftNode->enter != childValue) {
			parent = parent->leftNode;
			presearch(parent, parentValue, childValue);
		}
		else if (parent->rightNode&& parent->rightNode->enter != childValue) {
			parent = parent->rightNode;
			presearch(parent, parentValue, childValue);
		}
		else if(parent->parentNode){
			parent = parent->parentNode;
			presearch(parent, parentValue, childValue);
		}
	}

}

bool Enter(int* output, int N) {
	for (int i = 0; i < N; i++) {
		if (output[i] == 0) return false;
	}
	return true;
}

int main()
{
	int N = 0;
	cin >> N;
	int **input = new int*[N - 1];
	for (int i = 0; i < N - 1; i++) {
		input[i] = new int[2];
		cin >> input[i][0] >> input[i][1];
	}
	int* enter = new int[N - 1];
	for (int i = 0; i < N - 1; i++) {
		enter[i] = 0;
	}

	int* output = new int[N - 1];
	for (int i = 0; i < N - 1; i++) {
		output[i] = 0;
	}

	/////////////////
	//최상위노드 생성
	node* pmaxNode = new node();
	pmaxNode->value = 1;
	node* parent = pmaxNode;

	int searchNodeValue = 1;
	bool swit = false;
	bool findSwit = false;
	while (Enter(output,N-1)==false) {
		findSwit = false;
		for (int i = 0; i < N - 1; i++) {
			if (enter[i] != -1 && (input[i][0] == searchNodeValue || input[i][1] == searchNodeValue)) {
				
				if (input[i][0] == searchNodeValue) {

					presearch(parent, searchNodeValue, input[i][1]);
					enter[i] = -1; output[input[i][1]-2] = searchNodeValue;
					searchNodeValue = input[i][1];
				}
				else if (input[i][1] == searchNodeValue) {

					presearch(parent, searchNodeValue, input[i][0]);
					enter[i] = -1; output[input[i][0]-2] = searchNodeValue;
					searchNodeValue = input[i][0];
				}
				findSwit = true; break;
			}
		}
		if (findSwit == false) //searchnodevalue에 해당하는 값이 존재하지 않으면
		{
			searchNodeValue = beforenode->value;
			beforenode = beforenode->parentNode;

		}
	}

	for (int i = 0; i < N - 1; i++) {
		cout << output[i] << endl;
	}

	return 0;
}

