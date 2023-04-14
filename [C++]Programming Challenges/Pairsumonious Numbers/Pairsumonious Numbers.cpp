// Pairsumonious Numbers.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

			//input�迭�� ��(�ΰ�����)Ž����, �����ϸ� -1��
			int in = 0;
			for (; in < N; in++) {
				if (input[in] == searchedValue) { input[in] = -1; break; }
			}

			if (in == N)//input�迭�� searchedvalue���� ���°��
				return false;
		}
	}
	//input������ ��� -1���� �˻�
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

	//������
	Quicksort(0, N - 1, pArray);

	//�ߺ�����
	int sameNum = 0;
	int inputNum = N*(N - 1) / 2;

	int* input = new int[inputNum];
	copy(pArray, pArray + inputNum, input);//�Է��Ѿֵ� ����

	for (int i = 1; i < inputNum; i++) {
		if (input[i-1] == input[i]) {
			sameNum = 1;
			int j = i + 1;

			//�ߺ����� ī����
			while (input[i - 1] == input[j]) {
				j++;
				sameNum++;
			}
			
			//�ߺ��ξֵ� �����
			for (int startIndex = j; startIndex < inputNum; startIndex++) {
				input[j - sameNum] = input[j];
			}
			
			inputNum = inputNum - sameNum;
		}
	}

	//a������ �� �˻����
	int *output = new int[inputNum];
	output[0] = sumAndAve;
	int forCheckingPair = 1;
	int value = 0;//���־�ְ� �˻��ϱ�����
	int inc = 0;//parray�� �ε���
	int* copyinput;
	int num; //�ְ˻��� ��������

	if (inputNum >= N) {//���������� ���� �������� N���� ũ��
		num = inputNum;
		copyinput = new int[num];
		copy(input, input + num, copyinput);//�Է��Ѿֵ� ����
	}
	else {
		num = N;
		copyinput = new int[num];
		copy(pArray, pArray+ num, copyinput);//�Է��Ѿֵ� ����
	}

	//output�� ���� �߰�...
	while (forCheckingPair < num) {
 		value = input[inc] - sumAndAve;
		if (value != output[0]) {
			output[forCheckingPair++] = value;
			inc++;
		}
	}
	//�� �˻�
	CheckPair(input, output, inputNum);

	//��� �ֵ��� ������������� input�� ��������� ==>��簪�� -1�̸� ���
	//��������� input�� ���°���� ��� X
	if (forCheckingPair == N) {}//������
	else if (forCheckingPair < N) {}//���X

	output[0] = output[0] - 1;
    return 0;
}

