// Bridge.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int partition(int* a, int left, int right) {
	int first = left;
	int pivot = a[first];
	int temp = 0;
	++left;

	while (left <= right) {
		while (a[left] <= pivot && left < right) ++left;
		while (a[right] > pivot && left <= right) --right;

		if (left < right) {
			temp = a[right];
			a[right] = a[left];
			a[left] = temp;
		}
		else break;
	}
	temp = a[right];
	a[right] = a[first];
	a[first] = temp;

	return right;
}

void quickSort(int* a, int left, int right) {
	if (left < right) {
		int index = partition(a, left, right);

		quickSort(a, left, index - 1);
		quickSort(a, index + 1, right);
	}
}

int main()
{
	int TC;
	int* N;
	cin >> TC;
	cout << endl;
	int** crossTime = new int*[TC];
	N = new int[TC];

	for (int tc = 0; tc < TC; tc++) {
		if (tc != 0)cout << endl; //케이스간 줄건너띄기

		cin >> N[tc];

		crossTime[tc] = new int[N[tc]];

		for (int i = 0; i < N[tc]; i++) {
			crossTime[tc][i] = 0;

			//입력받
			cin >> crossTime[tc][i];
		}
		//cout << endl;
		quickSort(crossTime[tc], 0, N[tc] - 1);


		int count; //맨앞 두개를 제외한 갯수,count가 1개남은경우 총 3개남은상태에서 가장작은값 포함해서 먼저보내기
		int AtoB[2];
		AtoB[0] = crossTime[tc][0];
		AtoB[1] = crossTime[tc][1];

		int* allSom = new int[2];
		allSom[0] = 0; allSom[1] = 0; //초기화

		//더하기 1
		count = N[tc];

		if (N[tc] == 1) {
			allSom[0] += crossTime[tc][0];

		}
		else if (N[tc] == 2) {
			allSom[0] += crossTime[tc][1];

		}
		while (count > 3) {
			allSom[0] += AtoB[1];
			allSom[0] += AtoB[0];


			allSom[0] += crossTime[tc][count - 1];

			allSom[0] += AtoB[1];

			count -= 2;


		}

		if (count == 3) { //홀수면
			allSom[0] += AtoB[1];
			allSom[0] += AtoB[0];

			allSom[0] += crossTime[tc][2];
		}
		else if (count == 2) {//짝수면
			allSom[0] += AtoB[1];
		}

		//더하기 2
		count = N[tc];

		while (count > 2) {


			allSom[1] += crossTime[tc][count - 1];
			allSom[1] += AtoB[0];
			count--;
		}

		if (count == 2) {
			allSom[1] += AtoB[1];
		}
		else if (count == 1) {
			allSom[1] += AtoB[0];
		}



		//출력


		if (allSom[0] < allSom[1]) {

			count = N[tc];
			cout << allSom[0] << endl;

			if (N[tc] == 1) cout << crossTime[tc][0] << endl;
			else if (N[tc] == 2) cout << crossTime[tc][0] << " " << crossTime[tc][1] << endl;

			while (count > 3) {
				cout << AtoB[0] << " " << AtoB[1] << endl;
				cout << AtoB[0] << endl;
				cout << crossTime[tc][count - 2] << " " << crossTime[tc][count - 1] << endl;
				cout << AtoB[1] << endl;

				count -= 2;
			}

			if (count== 3) { //홀수면

				cout << AtoB[0] << " " << AtoB[1] << endl;
				cout << AtoB[0] << endl;
				cout << AtoB[0] << " " << crossTime[tc][2] << endl;
			}

			else if (count== 2) {//짝수면
				cout << AtoB[0] << " " << AtoB[1] << endl;
			}

		}

		else {
			count = N[tc];
			cout << allSom[1] << endl;

			while (count > 2) {
				cout << AtoB[0] << " " << crossTime[tc][count - 1] << endl;
				cout << AtoB[0] << endl;
				count--;
			}

			if (count == 2) {
				cout << AtoB[0] << " " << AtoB[1] << endl;
			}
			else if (count == 1) {
				cout << AtoB[0] << endl;
			}

		}
	}

	return 0;
}

