// Factovisors.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
const int maxPrime = 46400;
int* primeArray;
int* primeArrayList;
int *mPrime ;

void calculPrime() //소수저장
{
	int palIndex = 0;
	int primeValue=3;
	int i;
	primeArray[2] = 2; //소수
	primeArrayList[palIndex++] = 2;
	for (i = 4; i < maxPrime; i = i + 2) {
		primeArray[i] = 1;//합성수
	}

	while (primeValue < maxPrime) {
		if (primeArray[primeValue] == 0) {
			primeArray[primeValue] = 2;
			primeArrayList[palIndex++] = primeValue;

			for (i = primeValue * 2; i < maxPrime; i = i + primeValue) {
				if (!primeArray[i]) primeArray[i] = 1;
			}
		}
		primeValue = primeValue + 2;
	}

}


void prime_factorization(long x, int &forCountingPrime)
{
	int palIndex = 0;

	while(primeArrayList[palIndex] !=0 && x != 1){
		while (1) {
			if ( x%primeArrayList[palIndex] == 0)//소인수를발견하면
			{
				//배열추가
				mPrime[forCountingPrime] = primeArrayList[palIndex];
				forCountingPrime++;

				x /= primeArrayList[palIndex];
			}
			else break;
		}

		palIndex++;
	}
}
int inc;
bool forstartIncSit;

bool primeAndCompare(long x,int &forCountingPrime,int mPrimeCounting)
{
	 static int startInc;
	 inc = startInc;
	 forstartIncSit = false;

	//while (primeArrayList[palIndex] != 0 && x!=1) {
	 while (mPrime[inc] != 0 && x != 1) {
		 if (mPrime[inc] != -1 && x%mPrime[inc] == 0) {
			 //if (x%primeArrayList[palIndex] == 0)//소인수를발견하면
			 //{
				 //mPrime과 값 비교

					 //if (primeArrayList[palIndex] == mPrime[inc]) {
			 //mPrime[inc] = -1;
			 forCountingPrime++;
			 if (mPrimeCounting == forCountingPrime) return true;
			 //inc++;
			 //break;
		 //}
		 //else if (primeArrayList[palIndex] > mPrime[inc]) {
			 //x = 1; break;
		 //}
		 //else
			 //return false;

			 x /= mPrime[inc];
			 mPrime[inc] = -1;
			 //inc++;
			 //}
			 //else break;
		 }
		 else if (!forstartIncSit && mPrime[inc] != -1) {
			 startInc = inc;
			 forstartIncSit = true;
		 }
		 inc++;
	 }
		//palIndex++;

	//}

	return false;
}
template < typename T>
void initArray(T* ar, int range) {
	for (int i = 0; i < range; i++) ar[i] = 0;
}

int main()
{
	long n, m;
	int forCountingPrime;
	int mPrimeCounting;
	bool devideCheck;
	//cin >> n >> m;
	mPrime = new int[100];
	primeArray = new int[maxPrime];
	primeArrayList = new int[5000];
	initArray(primeArray, 46400);
	initArray(primeArrayList, 5000);
	calculPrime();

	while (scanf_s(	"%ld %ld", &n, &m) != EOF) {
		forCountingPrime = 0;
		mPrimeCounting = 0;
		devideCheck = false;
		initArray(mPrime,100);

		if ((n == 0 || n == 1) && m == 1) devideCheck = true;
		else if (m == 0) devideCheck = false;
		else if (m == n) devideCheck = true;
		else {
			prime_factorization(m, mPrimeCounting);
			//Quicksort(0, mPrimeCounting - 1, mPrime);

			for (int i = n; i >= 2; i--) {
				if (primeAndCompare(i, forCountingPrime, mPrimeCounting)) {
					devideCheck = true;
					break;
				}
			}
		}
		if (devideCheck) cout << m << " devides " << n << "!" << endl;
		else {
			cout << m << " does not divide " << n << "!" << endl;
		}
	}
	return 0;
}

