// project4383.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//#include "p4383.h"
#include <iostream>
using namespace std;
class p4383 {
public:
	p4383(int num, int* arr) {
		this->num = num;
		this->arr = arr;
		validationValue = (num*(num - 1)) / 2;
		checkArr = new bool[num];
	}

	~p4383() {
		cout << "소멸자" << endl;
		delete[] arr;
		delete[] checkArr;
	}

	virtual bool Excute() {
		//차이값의 절대값을 구해서 checkArr에 대입
		int abst = 0;
		for (int i = 1; i < num; i++) {
			abst = abs(arr[i] - arr[i - 1]);

			//jolly check
			if (Validation(abst, num))
				checkArr[abst] = false;
			else //졸리가 아닌경우
				return false;
		}

		//졸리인 경우
		if (validationValue == 0)
			return true;

	}

	virtual bool Validation(int abst, int num) {
		//체크 1
		if (checkArr[abst] == false)
			return false; //jolly가 아니다

		else validationValue = validationValue - abst;

		//체크 2
		if (validationValue < 0)
			return false;

		else return true;
	}

private:
	int num;
	int* arr;
	int validationValue;
	bool* checkArr; //연속된 차이값의 중복 체크
};
int main()
{

	int num = 0;
	//cin >> num;
	for (; EOF != scanf_s("%d", &num);) {
		int* arr = new int[num];
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}



		p4383* p = new p4383(num, arr);
		p->Excute() == true ? cout << "Jolly" : cout << "Not jolly";
		cout << endl;
	}
    return 0;
}

