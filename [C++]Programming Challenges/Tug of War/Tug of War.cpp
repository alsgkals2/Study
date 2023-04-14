// Tug of War.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
/*static char c[45000][101], hs[45000][101];
static int n, cp[45000], inp[100];
static double sum, sum2, sol;

void input(void)
{
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &inp[i]);

	for (i = 0; i < 45000; i++)
	{
		cp[i] = 0;
		for (j = 0; j < n; j++)
			c[i][j] = hs[i][j] = 0;
	}
}

double abs(double s)
{
	if (a < 0)
		return -a;
	else
		return a;
}

void dynamic(void)
{
	int i, j, k, l;
	int sw;

	sum = 0;
	for (i = 0; i < n; i++)
		sum = sum + (double)inp[i];
	sum2 = sum / (double)2.0;

	cp[0] = 1;

	for(i=0; i<=sum2; i++)
		for(j=0; j<cp[i]; j++)
			for (k = 0; k < n; k++)
			{
				sw = 0;
				if(hs[i+inp[k]][c[i][j]+1])
			

			}


}
*/
const int MAXPEOPLE = 100;

int partition(int left, int right, short* weight) {
	int first = left;
	int pivot = weight[first];
	left++;

	while (left <= right) {
		while (weight[left] <= pivot && left < right) left++;
		while (weight[right] > pivot && left <= right) right--;

		if (left < right) {
			int temp = weight[right];
			weight[right] = weight[left];
			weight[left] = temp;
		}
		else break;
	}

	int temp = weight[first];
	weight[first] = weight[right];
	weight[right] = temp;

	return right;
}
void Quicksort(int left, int right, short* weight) {
	int index;
	if (left < right) {
		index = partition(left, right, weight);

		Quicksort(left, index - 1, weight);
		Quicksort(index+1, right, weight);
	}
}

int Allsom;
int dividedPeople;
int N;

int BackTracking(int& minimumMinus, short* weight, int count, int startIndex, int currentSum1) {
	int i;
	int returnValue;
	static short judgeDec_Inc;
	static short thisJudge;
	static bool tjSw;

	//검사
	if (count == dividedPeople - 1) {
		judgeDec_Inc = 0;
		tjSw = false;
	}
	if (count == dividedPeople) {
		int comMinus = abs(Allsom - currentSum1 - currentSum1);//한쪽합과 다른쪽합의 차잇값
		if (!tjSw) {
			tjSw = true;
			thisJudge = comMinus;
		}
		else {
			if (thisJudge < comMinus)
				return 0;
			else thisJudge = comMinus;
		}

		if (comMinus == 0) {
			minimumMinus = -1;
			return currentSum1;
		}

		/*if (judgeDec_Inc == 1 && minimumMinus < comMinus) {//작아졌다가 커진경우
			//어차피 차잇값 더 증가하므로 더이상 트랙킹 할필요X(가지치기)

			return 0;
		}*/
	//	else {
		//	judgeDec_Inc = 3; //큰데 judgedec가 0인경우
			if (minimumMinus > comMinus) { //작은경우, 작아지는경우
				minimumMinus = comMinus;
				judgeDec_Inc = 1;
		//	}
			return currentSum1;
		}

	}



	//조건충족 안된경우
	for (i = startIndex; i < N; i++)
	{
		returnValue = BackTracking(minimumMinus, weight, count + 1, i + 1, currentSum1 + weight[i]);
		if (returnValue == 0) return minimumMinus;
		if (minimumMinus == -1)
			break;
	}

	return minimumMinus;

}


int main()
{
	int TC;
	short* weight = new short[MAXPEOPLE];
	int minus;
	int result;

	//cin >> TC;

	//while (TC-- != 0) {
	//	cout << '\n';
		Allsom = 0;
		
		cin >> N;
		dividedPeople = N / 2;

		for (int i = 0; i < N; i++)
		{
			cin >> weight[i];
			Allsom += weight[i];
		}
		minus = Allsom;

		Quicksort(0, N - 1, weight);

		BackTracking(minus, weight, 0, 0, 0);
		result = Allsom / 2 - minus / 2;

		printf("%d %d", result, Allsom - result);
	//}
    return 0;
}

