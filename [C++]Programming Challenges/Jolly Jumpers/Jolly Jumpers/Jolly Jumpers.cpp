// Jolly Jumpers.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

class Jolly {
public:
	int n;
	int *num;
	char* re;
	Jolly* nextJolly;

	void function();

};

void Jolly::function() {

	int *num = new int[n];
	char *re = new char[n];
	bool swit = true;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (abs(num[i] - num[i + 1] < n)) {
			re[abs(num[i] - num[i + 1])] = 'o';
		}
		else { swit = false; break; }
	}

	if(swit==true)
	for (int i = 1; i < n; i++) {
		if (re[i] != 'o') {
			swit = false;
			break;
		}
	}

	if (swit == true) cout << "Jolly" << endl;
	else if (swit == false) cout << "Not Jolly"<<endl;


}

int main()
{
	Jolly *j = new Jolly();
	Jolly *start = new Jolly();
	start = j;

	while (1) {
		start->function();
		start->nextJolly = new Jolly();
		start = start->nextJolly;
	}
    return 0;
}

