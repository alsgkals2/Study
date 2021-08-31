// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
static int ii = 3;

static void abc() { static int iq = 0; }

class C
{
public:
	static void TM(const int& i) {
		int aaaaa = 3;
	}

	void Test(int& val) {
		cout << "좌측값 참조 매개변수" << endl;
	}
	void Test(int&& val) {
		cout << "우측값 참조 매개변수" << endl;
	}
private:

};


void TestMethod(const int& a) {
	cout << a << endl;
}

constexpr int cexpr(const int& a, const int& b) {
	return a + b;
}
extern double pie=4.0;

int main()
{
	
	const int* t = new int[3];
	//t[0] = 5;
	int* const tt = new int[10];
	tt[4] = 5;
	return 0;

}

