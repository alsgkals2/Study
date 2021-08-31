// Vito'sFamily.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

//퀵정렬


int Partition(int* familyNum, int left, int right) {
	int first = left;
	int pivot = familyNum[left];
	int forSwap = 0;
	++left;

	while (left <= right) {
		while (familyNum[left] <= pivot && left < right)
			++left;
		while (familyNum[right] > pivot && left <= right)
			--right;

		if (left < right) {
			forSwap = familyNum[left];
			familyNum[left] = familyNum[right];
			familyNum[right] = forSwap;
		}
		else break;
	}

	forSwap = familyNum[first];
	familyNum[first] = familyNum[right];
	familyNum[right] = forSwap;

	return right;
}

void QuickSort(int* familyNum, int left, int right) {
	if (left < right) {
		int index = Partition(familyNum, left, right);

		QuickSort(familyNum, left, index - 1);
		QuickSort(familyNum, index + 1, right);
	}
}

int BinarySearch(int* familNum,int start, int end,int searchNum) {
	int middle = (start + end) / 2;
	if (searchNum < familNum[middle] && start != middle) {
		BinarySearch(familNum, start, middle - 1,searchNum);
	}
	else if (searchNum > familNum[middle] && end != middle) {
		BinarySearch(familNum, middle + 1, end,searchNum);

	}
	else  return middle;
}


int main()
{

	int TC, INPUSTNUM;
	cin >> TC;
	int* saveOutput = new int[TC];
	int test;
	int outputIndex;
	int allSom;


	for (int tc = 0; tc < TC; tc++) {
		saveOutput[tc] = 0;

		allSom = 0;
		outputIndex = 0;
		
		cin >> INPUSTNUM;
		
		int *familyNum = new int[INPUSTNUM];
		
		for (int in = 0; in < INPUSTNUM; in++) {
			cin >> familyNum[in];
			allSom += familyNum[in];
		}
	
		//정렬
		QuickSort(familyNum, 0, INPUSTNUM - 1);

		if (INPUSTNUM % 2 == 1)//홀수갯수인경우
		{
			int ele = INPUSTNUM / 2;
			for (int i = 0; i < INPUSTNUM; i++) {
				saveOutput[tc] += abs(familyNum[ele] - familyNum[i]);
			}
		}
		else//짝수갯수인경우
		{
			int ele1 = INPUSTNUM / 2;
			int ele2 = INPUSTNUM / 2 - 1;
			int winEle = -1;

			if (familyNum[ele1] == familyNum[ele2]) //두 위치의 값이 같으면
				winEle = ele1;

			else {
				int ele1_count = 0;
				int ele2_count = 0;
				int forcount_ele1 = ele1;
				int forcount_ele2 = ele2;
				while (familyNum[++forcount_ele1] == familyNum[ele1]) { ele1_count++; }
				while (familyNum[--forcount_ele2] == familyNum[ele2]) { ele2_count++; }

				winEle = ele1_count > ele2_count ? ele1 : ele2;
			}

			for (int i = 0; i < INPUSTNUM; i++) {
				saveOutput[tc] += abs(familyNum[winEle] - familyNum[i]);
			}
		}

	}

	for (int i = 0; i < TC; i++) cout << saveOutput[i] << endl;

    return 0;
}

