// Tree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
#include <string.h>
using namespace std;

typedef struct node {
	node* parentsNode = NULL;
	char nodeAlpha = -1;
	node* leftNode = NULL;
	node* rightNode = NULL;
	int checkNum = 0; // 2번째부터 7번째까지 입력줄대로 번호매김, 그번호가 아닌경우는 거치지않은거임
}node;

class function {

public:
	int outputElement = 0;

	void input(node*, char, char, char,int);
	void inputCycle(node*,char**, char, int);

	void preorder(node*, char*);
	void inorder(node*, char*);
	void postorder(node*, char*);
};

void function::inputCycle(node* ingNode,char ** inputNode, char compareNode, int N) {
	for (int n = 0; n < N; n++) {
		if (inputNode[n][0] != '.'&&inputNode[n][0] == compareNode) {
			
			input(&ingNode[0], inputNode[n][0], inputNode[n][1], inputNode[n][2], n);
			
			if (inputNode[n][1] != '.') {
				compareNode = inputNode[n][1];
				inputCycle(&ingNode[0],inputNode, compareNode, N);
			}
			if (inputNode[n][2] != '.') {
				compareNode = inputNode[n][2];
				inputCycle(&ingNode[0], inputNode, compareNode, N);
			}
			inputNode[n][0] = '.';
		}
	}
}
void function::input(node* n, char root, char left, char right, int checkNum) {
	n->checkNum = checkNum;
	if (!(left == '.' && right == '.')) {

		if (root == n->nodeAlpha) {
			if (left != '.') {
				n->leftNode = new node();
				n->leftNode->nodeAlpha = left;
				n->leftNode->parentsNode = n;
			}
			if (right != '.') {
				n->rightNode = new node();
				n->rightNode->nodeAlpha = right;
				n->rightNode->parentsNode = n;
			}
			
		}
		else if (n->leftNode&& n->leftNode->checkNum != checkNum) {
			n = n->leftNode;
			input(n, root, left, right, checkNum);
		}
		else if (n->rightNode&&n->rightNode->checkNum != checkNum) {
			n = n->rightNode;
			input(n, root, left, right, checkNum);
		}
		else if (n->parentsNode) {
			n = n->parentsNode;
			//제귀호출
			input(n, root, left, right, checkNum);
		}	

	}

}

void function::preorder(node *n, char* output1) {
	//순회한 노드는 checknum = -1
	if (n->checkNum != -1) {
		output1[outputElement++] = n->nodeAlpha;
		n->checkNum = -1;
	}
	if (n->leftNode&&n->leftNode->checkNum != -1) {
		n = n->leftNode;
		preorder(n, output1);
	}
	if (n->rightNode&&n->rightNode->checkNum != -1) {
		n = n->rightNode;
		preorder(n, output1);
	}
	if (n->parentsNode) {
		n = n->parentsNode;
		preorder(n, output1);
	}
}
void function::inorder(node *n, char* output2) {
	//순회한 노드는 checknum = -3
	if (n->leftNode&&n->leftNode->checkNum != -3) {
		n = n->leftNode;
		inorder(n, output2);
	}
	if (n) {
		if (n->checkNum != -3) {
			output2[outputElement++] = n->nodeAlpha;
			n->checkNum = -3;
		}
	}
	if (n->rightNode&&n->rightNode->checkNum != -3) {
		n = n->rightNode;
		inorder(n, output2);
	}
	if (n->parentsNode) {
		n = n->parentsNode;
		inorder(n, output2);
	}
}
void function::postorder(node *n, char* output3) {
	//순회한 노드는 checknum = -2
	if (n->leftNode&&n->leftNode->checkNum != -2) {
		n->leftNode->parentsNode = n;
		n = n->leftNode;
		postorder(n, output3);
	}
	if (n->rightNode&&n->rightNode->checkNum != -2) {
		n = n->rightNode;
		postorder(n, output3);
	}
	if (n) {
		if (n->checkNum != -2) {
			output3[outputElement++] = n->nodeAlpha;
			n->checkNum = -2;
		}
	}

	if (n->parentsNode) {
		n = n->parentsNode;
		postorder(n, output3);
	}
}

int main()
{
	int N = 0;//노드의 갯수
	cin >> N;
	function f;
	int alphanum = 0;
	char** inputNode = new char*[N];
	for (int i = 0; i < N; i++){
		inputNode[i] = new char[3];
		for (int j = 0; j < 3; j++)
		{
			inputNode[i][j] = NULL;
		}	
	}
	char compareLeft = NULL, compareRight = NULL;
	cin >> inputNode[0][0] >> inputNode[0][1] >> inputNode[0][2];
	compareLeft = inputNode[0][1];
	compareRight = inputNode[0][2];

	node firstNode;
	firstNode.nodeAlpha = inputNode[0][0];
	alphanum++;
	if (inputNode[0][1] != '.') {
		firstNode.leftNode = new node();
		firstNode.leftNode->nodeAlpha = inputNode[0][1];
		firstNode.leftNode->parentsNode = &firstNode;
		alphanum++;
	}

	if (inputNode[0][2] != '.') {
		firstNode.rightNode = new node();
		firstNode.rightNode->nodeAlpha = inputNode[0][2];
		firstNode.rightNode->parentsNode = &firstNode;
		alphanum++;
	}

	node *ingNode = new node();
	ingNode[0] = firstNode;
	
	
	
	for (int n = 1; n <= N - 1; n++) {
		cin >> inputNode[n][0] >> inputNode[n][1] >> inputNode[n][2];
		if (inputNode[n][1] != '.') alphanum++;
		if (inputNode[n][2] != '.') alphanum++;
	}


	
	f.inputCycle(&ingNode[0],inputNode,compareLeft,N);
	f.inputCycle(&ingNode[0],inputNode, compareRight, N);


	char** output = new char*[3];
	for (int i = 0; i < 3; i++) {
		output[i] = new char[alphanum];
		for (int j = 0; j < alphanum; j++) {
			output[i][j] = '-';
		}
	}

	//출력할 문자들초기화
	f.preorder(&firstNode, output[0]);
	f.outputElement = 0;
	f.inorder(&firstNode, output[1]);
	f.outputElement = 0;
	f.postorder(&firstNode, output[2]);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < alphanum; j++)
		{
			cout << output[i][j];
		}
		cout << endl;
	}

		return 0;
}

