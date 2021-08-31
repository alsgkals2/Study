// 2577.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	int m_iABC;
	string m_strABC;
	const char* _num = m_strABC.c_str();

	cin >> A;
	cin >> B;
	cin >> C;
	m_iABC = A*B*C;
	m_strABC = to_string(m_iABC);
	int sz = m_strABC.size();
	int arr[10] = { 0 };

	for (int i = 0; i< sz; i++)
		arr[(int)(_num[i] - '0')] ++;

	for (int i : arr)
		cout << i << endl;
	
	delete _num;

	return 0;
}