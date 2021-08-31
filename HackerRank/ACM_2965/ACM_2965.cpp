// ACM_2965.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int input[3];
	cin >> input[0] >> input[1] >> input[2];
	int output = input[1] - input[0] < input[2] - input[1] ? input[2] - input[1] - 1 : input[1] - input[0] - 1;
	cout << output;
    return 0;
}

