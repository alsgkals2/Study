// Ones.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

/*
2나 5로 나눌 수 없는 0 이상 10000이하의 정수 n이 주어졌는데, n의 배수 중에는 10진수로 표기했을 때 모든 자리 숫자가 1인 것이 있다.
그러한 n의 배수 중에서 가장 작은 것은 몇 자리 수일까?
*/

/*알고리즘:
ex) 3이 입력됬을때, multiple에 3의자릿수 + 1의 크기를가지는 10의 n제곱값을 저장한 후, 3을 더해가면서 자릿수를 체크한다.
자릿수를 체크하는 방법은 multiple * pow(10,n)으로 나눠가면서 계속 나눈나머지가 1일때 최초로 몫이 0 이면 pow(10,n)을 n로보고 자릿수 n을 리턴한다.
나눈나머지가 1이아닌값이 있으면 함수실행을 중단한다.
*/
using namespace std;



int main()
{
		int N = 0;
		unsigned long long int fordevided = 0;
		int incTen = 0;
		unsigned long long int foradd = 0;
		while (scanf("%d",&N)!=EOF) {

			fordevided = 0;
			int incTen = 0;
			foradd = 1;

			while (1) {
				if(incTen!=0) {
					foradd = foradd * 10;

					fordevided = fordevided+foradd;
				}
				else fordevided = 1;

					incTen++;
				if (fordevided%N == 0) {
					printf("%d\n", incTen); break;
				}
			}
		}
    return 0;
}

