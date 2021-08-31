// ACM_10816.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



int partition(int left, int right, vector<int>& arr)
{
	int temp = 0;
	int first = left;
	++left;

	while (left <= right) {

		while (arr[left] <= arr[first] && left < right) { left++; }
		while (arr[first] < arr[right] && left <= right) { right--; }

		if (left < right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		else break;
	}

	temp = arr[first];
	arr[first] = arr[right];
	arr[right] = temp;

	return right;
}

void QuickSort(int left, int right, vector<int>& arr)
{
	if (left < right) {
		int index = partition(left, right, arr);

		QuickSort(left, index - 1, arr);
		QuickSort(index + 1, right, arr);
	}
}


int UpperBound(int num, int m, vector<int>& arr) {
	int start = 0;
	int end = m - 1;
	int middle = 0;
	//-10 -10 2 3 3 6 7 10 10 10
	while (start < end) {
		middle = (start + end) / 2;
		if (arr[middle] <= num) start = middle + 1;//Lower�� <=��� <�θ� �ٲ��ָ� �ȴ�.
		else end = middle;

	}

	if (arr[middle] == num) return middle;
	else return middle + 1;
}

int main()
{
	//���翩�� �Ǵܹ迭
	//���
	static int existedPlus[10000000] = { 0 };
	//����
	static int existedMinus[10000000] = { 0 };

	int M, N;
	//cin >> M;
	M = 10;
	vector<int> sorted(M + 1);
	int input;
	int *output;
	sorted = { 6,3,2,10,10,10,-10,-10,7,3 };
	for (int i = 0; i < M; i++) {
		//cin >> sorted[i];
		if (sorted[i] >= 0) {
			existedPlus[sorted[i]] = 1;
		} //����ΰ��
		else//�����ΰ��
			existedMinus[std::abs(sorted[i])] = 1;
	}

	QuickSort(0, M - 1, sorted);
		
	//cin >> N;
	N = 8;
	output = new int[N];
	for (int i = 0; i < N; i++) output[i] = 0;
	//input = 10,9,-5,2,3,4,5,-10

	for (int i = 0; i < N; i++) {
		cin >> input;
		//if ((input >= 0 && existedPlus[input] == 1) || input < 0 && existedMinus[std::abs(input)] == 1) {

			int searchIndex = UpperBound(input,M,sorted);
			while (searchIndex<M && sorted[searchIndex] == input){
				searchIndex++; output[i]++; }
		//}
		//else output[i] = 0;
	}

	//output = 3,0,0,1,2,0,0,2
	for (int i = 0; i < N; i++)
		printf("%d ", output[i]);
	return 0;
}

