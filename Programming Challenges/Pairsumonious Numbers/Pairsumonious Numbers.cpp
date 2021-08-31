// Pairsumonious Numbers.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int Partition(int left, int right, int* parray) {
	int first = left;
	int pivot = parray[first];

	left++;

	while (left <= right) {
		while (left < right && parray[left] <= pivot) left++;
		while (left <= right && parray[right] > pivot)--right;

		if (left < right) {
			int temp = parray[left];
			parray[left] = parray[right];
			parray[right] = temp;
		}
		else break;

	}

	int temp = parray[first];
	parray[first] = parray[right];
	parray[right] = temp;

	return right;
}

void Quicksort(int left, int right, int* parray) {
	if (left < right) {
		int index = Partition(left, right, parray);

		Quicksort(0, index - 1, parray);
		Quicksort(index+1,right, parray);
	}
}

bool CheckPair(int* input, int* output, int N)
{
	int index = -1;
	int i = 0;

	while (++index < N) {
		for (i = index+1; i < N; i++) {
			int searchedValue = output[index] + output[i];

			//input배열에 페어값(두개의합)탐색후, 존재하면 -1값
			int in = 0;
			for (; in < N; in++) {
				if (input[in] == searchedValue) { input[in] = -1; break; }
			}

			if (in == N)//input배열에 searchedvalue값이 없는경우
				return false;
		}
	}
	//input값들이 모두 -1인지 검사
	for (i = 0; i < N; i++) {
		if (input[i] != -1) return false;
	}
	return true;

}
int main()
{
	int N;
	int* pArray;
	int sumAndAve;

	scanf("%d", &N);
	pArray = new int[N];
	sumAndAve = 0;

	for (int i = 0; i < N*(N-1)/2; i++) {
		scanf("%d", &pArray[i]);
		sumAndAve += pArray[i];
	}
	sumAndAve = (sumAndAve / (N*(N - 1)))+0.5;

	//퀵정렬
	Quicksort(0, N - 1, pArray);

	//중복제거
	int sameNum = 0;
	int inputNum = N*(N - 1) / 2;

	int* input = new int[inputNum];
	copy(pArray, pArray + inputNum, input);//입력한애들 복사

	for (int i = 1; i < inputNum; i++) {
		if (input[i-1] == input[i]) {
			sameNum = 1;
			int j = i + 1;

			//중복갯수 카운팅
			while (input[i - 1] == input[j]) {
				j++;
				sameNum++;
			}
			
			//중복인애들 덮어쓰기
			for (int startIndex = j; startIndex < inputNum; startIndex++) {
				input[j - sameNum] = input[j];
			}
			
			inputNum = inputNum - sameNum;
		}
	}

	//a값부터 쌍 검사시작
	int *output = new int[inputNum];
	output[0] = sumAndAve;
	int forCheckingPair = 1;
	int value = 0;//값넣어넣고 검사하기위함
	int inc = 0;//parray의 인덱스
	int* copyinput;
	int num; //쌍검사할 갯수범위

	if (inputNum >= N) {//증복제거한 후의 갯수들이 N보다 크면
		num = inputNum;
		copyinput = new int[num];
		copy(input, input + num, copyinput);//입력한애들 복사
	}
	else {
		num = N;
		copyinput = new int[num];
		copy(pArray, pArray+ num, copyinput);//입력한애들 복사
	}

	//output에 값들 추가...
	while (forCheckingPair < num) {
 		value = input[inc] - sumAndAve;
		if (value != output[0]) {
			output[forCheckingPair++] = value;
			inc++;
		}
	}
	//쌍 검사
	CheckPair(input, output, inputNum);

	//모든 쌍들의 덧셈결과값들이 input에 들어있으면 ==>모든값이 -1이면 통과
	//덧셈결과가 input에 없는경우라면 통과 X
	if (forCheckingPair == N) {}//모두통과
	else if (forCheckingPair < N) {}//통과X

	output[0] = output[0] - 1;
    return 0;
}

