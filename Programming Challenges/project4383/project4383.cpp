// project4383.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		cout << "�Ҹ���" << endl;
		delete[] arr;
		delete[] checkArr;
	}

	virtual bool Excute() {
		//���̰��� ���밪�� ���ؼ� checkArr�� ����
		int abst = 0;
		for (int i = 1; i < num; i++) {
			abst = abs(arr[i] - arr[i - 1]);

			//jolly check
			if (Validation(abst, num))
				checkArr[abst] = false;
			else //������ �ƴѰ��
				return false;
		}

		//������ ���
		if (validationValue == 0)
			return true;

	}

	virtual bool Validation(int abst, int num) {
		//üũ 1
		if (checkArr[abst] == false)
			return false; //jolly�� �ƴϴ�

		else validationValue = validationValue - abst;

		//üũ 2
		if (validationValue < 0)
			return false;

		else return true;
	}

private:
	int num;
	int* arr;
	int validationValue;
	bool* checkArr; //���ӵ� ���̰��� �ߺ� üũ
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

