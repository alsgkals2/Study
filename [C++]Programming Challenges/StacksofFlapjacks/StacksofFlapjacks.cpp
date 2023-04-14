// StacksofFlapjacks.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;
const int MAXFENNUM = 30;

void inverseSort(int* inputStack,int i) {
	int forTemp = 0;
	int movingEle = 0;
	while (movingEle < i) {
		forTemp = inputStack[i];
		inputStack[i] = inputStack[movingEle];
		inputStack[movingEle] = forTemp;
		i--; movingEle++;
	}
}

int* flip(int* inputStack,int* sortStack,int count,int& returnCount) {
	int i=0;
	int forTemp = 0;
	int saveLastEle;
	int* forreturn = new int[MAXFENNUM];

		for (int in = count-1; in>=0; in--) {
			if (inputStack[in] != sortStack[in]) {
				int searchIndex = 0;

				while (searchIndex <in) {
					if (inputStack[searchIndex] == sortStack[in])//sortstack에서 해당요소 탐색시작
						break;
					searchIndex++;
				}

				if (searchIndex != 0) //인덱스가 0이아니면
				{
					inverseSort(inputStack, searchIndex);
					forreturn[returnCount++] = abs(searchIndex - count);
				
				}
					inverseSort(inputStack, in);
					forreturn[returnCount++] = abs(in -count);
				
			}


		}

	forreturn[returnCount++] = 0;
	return forreturn;
	
}
int partition(int left, int right, int* inputStack) {
	int first = left;
	++left;

	while (left <= right) {
		while (inputStack[left] <= inputStack[first] && left < right) { left++; }
		while (inputStack[right] > inputStack[first] && left <= right) { right--; }

		if (left < right) {
			int temp = inputStack[right];
			inputStack[right] = inputStack[left];
			inputStack[left] = temp;
		}
		else break;
	}
	int temp = inputStack[first];
	inputStack[first] = inputStack[right];
	inputStack[right] = temp;

	return right;
}

void quickSort(int left, int right, int* inputStack) {
	if (left < right) {
		int index = partition(left, right, inputStack);

		quickSort(left, index - 1, inputStack);
		quickSort(index + 1, right, inputStack);
	}

}

void initStack(char* stack) {
	for (int i = 0; i < MAXFENNUM; i++) stack[i] = '.';
}

int main()
{
	char* input = new char[150];
	int* inputStack = new int[MAXFENNUM];
	int* sortedStack = new int[MAXFENNUM];

	int count;
	int inputNum = -1;
	string s;

	while (!feof(stdin)) {
		count = 0;
		cin.getline(input, 150);
		
		for (int i = 0; i < 150; i++) {
			if (input[i] >= 48 && input[i] <= 57) inputNum = atoi(&input[i]);
			else if (input[i] == ' ') continue;
			else break;


			if (input[i + 1] >= 48 && input[i + 1] <= 57)//2자릿수 이상의 숫자면
			{
				//string에 저장
				s += input[i];
				s += input[i + 1];
				i = i + 2;

				while (input[i] >= 48 && input[i] <= 57) {
					s += input[i];
					i++;
				}
				//숫자 저장
				inputNum = stoi(s);
				s.clear();
			}

			sortedStack[count] = inputStack[count] = inputNum;
			count++;//요소 갯수
		}
		//출력
		for (int i = 0; i < count-1; i++) cout << inputStack[i] << " ";
		cout << inputStack[count - 1];
		//정렬
		quickSort(0, count - 1, sortedStack);
		//inverseSort(sortedStack, count - 1);

		//flip
		int returnCount = 0;
		int* result = flip(inputStack, sortedStack, count,returnCount);
		
		//출력
		cout << endl;
		for (int i = 0; i < returnCount-1; i++) {
			cout << result[i] << " ";
		}
		cout << result[returnCount-1] << endl;

		initStack(input);
	}
    return 0;
}

