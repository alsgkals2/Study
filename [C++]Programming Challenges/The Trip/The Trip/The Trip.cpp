// The Trip.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class Function {
public:
	int maxi, mini;
	float av;
	static float total;
	float* moneyStudent;
	int stNum;
	float fun(float*);
	int sameReturn(float*);
};

float Function::total=0;

int CheckStateNum(float value) {
	int v = (int)value;
	int num = 1;
	while (1) {
		if (v / num < 10) break;
			num = num * 10;
	}
	return num;

}

float Function::fun(float* ms)
{
	maxi = 0;
	mini = 0;

	for (int i = 0; i < stNum; i++) 
	{
		if (ms[maxi] < ms[i]) maxi = i; //가장 큰요소
		else if (ms[mini] > ms[i]) mini = i; //가장 작은요소
	}
	if (mini == maxi) return 0;
	else{
		/*
		f.moneyStudent[i] = (int)(f.moneyStudent[i] * 100);
		f.moneyStudent[i] = f.moneyStudent[i] / 100;
		*/
	ms[maxi] = ((ms[maxi] - (av - ms[mini])));
	//ms[maxi] = ms[maxi] / 100;
	total += (av - ms[mini]);
	ms[mini] = ms[mini] + (av - ms[mini]); //값넘겨주기
	//ms[mini] = (int)((ms[mini] + (av - ms[mini])) * 100);
	//ms[mini] = ms[mini] / 100;

	fun(ms);
	}
}

int Function::sameReturn(float* ms)
{
	bool swit=0;
	for (int i = 0; i < stNum-1; i++)
	{
		if (ms[i] != ms[i + 1]) swit = 1;
	}
	return swit;
}

int main()
{
	Function f;
	f.av = 0;
	cin >> f.stNum;
	f.moneyStudent = new float[f.stNum];
	
	for (int i = 0; i < f.stNum; i++) {
		cin >> f.moneyStudent[i];
	f.moneyStudent[i] = (int)(f.moneyStudent[i] * 1000);
	//	f.moneyStudent[i] = f.moneyStudent[i] / 100;
		f.av += f.moneyStudent[i];
	}
	f.av = (f.av / f.stNum);
	//f.av = (int)(f.av * 100);
	//f.av = f.av/ 100;

	f.fun(f.moneyStudent);
	float test = f.total;
	
	delete[] f.moneyStudent;
    return 0;
}

