// Shoemaker's Problem.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int Partition(int left, int right, double** a) {
	int first = left;
	double pivot = a[first][1];
	left++;

	while (left <= right) {
		while (a[left][0] > pivot && left < right) ++left;
		while (a[right][0] < pivot && left <= right) --right;
	
		if (a[left][0] == pivot && a[left][1] < a[first][1]) {
			
			double temp2 = a[first][0];
			int temp3 = a[first][1];
			a[first][0] = a[left][0];
			a[first][1] = a[left][1];
			a[left][0] = temp2;
			a[left][1] = temp3;
			++left;
		}
		else if (left < right) {
			double temp2 = a[right][0];
			int temp3 = a[right][1];
			a[right][0] = a[left][0];
			a[right][1] = a[left][1];
			a[left][0] = temp2;
			a[left][1] = temp3;
		}
		
		else break;
	}

	int temp1 = a[first][0];
	double temp2 = a[first][1];
	a[first][0] = a[right][0];
	a[first][1] = a[right][1];
	a[right][0] = temp1;
	a[right][1] = temp2;

	return right;

}
void QuickSort(int left, int right, double**a) {

	if (left < right) {
		int index = Partition(left, right, a);

		QuickSort(left, index - 1, a);
		QuickSort(index + 1, right, a);
	
	}

}

int binarySearch(double value1,double value2, double** a, int size) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (value1 == a[mid][0] && value2==a[mid][1]) return mid;
		else if (value1 == a[mid][0]) {
			if (value2 > a[mid][1]) left = mid + 1;
			else right = mid - 1;
		}
		else if (value1 > a[mid][0]) right = mid - 1;
		else if (value1 < a[mid][0]) left = mid + 1;
	}
}
int main()
{
	int TC = 0;
	int N = 0;
	int* S, *T;
	double** devide;
	double** origin_devide;

	cin >> TC;

	while (TC-- != 0) {
		cout << '\n';
		cin >> N;
	
		S = new int[N];
		T = new int[N];
		devide = new double*[N];
		origin_devide = new double*[N];

		for (int n = 0; n < N; n++) {
			cin >> S[n] >> T[n];
			devide[n] = new double[2];
			devide[n][0] = (double)T[n] / S[n];
			devide[n][1] = S[n];
			origin_devide[n] = new double[2];
			origin_devide[n][0] = devide[n][0];
			origin_devide[n][1] = devide[n][1];
		}
		//정렬
		QuickSort(0, N - 1, devide);
		
		//출력..?
		bool* checkingIndex = new bool[N];
		for (int n = 0; n < N; n++) {
			int deinc = 0;
			cout << binarySearch(origin_devide[n][0],origin_devide[n][1], devide, N)+1;
			if (n != N - 1)cout << " ";
			else cout << '\n';
		}

	}
	return 0;
}

