// Ones.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

/*
2�� 5�� ���� �� ���� 0 �̻� 10000������ ���� n�� �־����µ�, n�� ��� �߿��� 10������ ǥ������ �� ��� �ڸ� ���ڰ� 1�� ���� �ִ�.
�׷��� n�� ��� �߿��� ���� ���� ���� �� �ڸ� ���ϱ�?
*/

/*�˰���:
ex) 3�� �Է�����, multiple�� 3���ڸ��� + 1�� ũ�⸦������ 10�� n�������� ������ ��, 3�� ���ذ��鼭 �ڸ����� üũ�Ѵ�.
�ڸ����� üũ�ϴ� ����� multiple * pow(10,n)���� �������鼭 ��� ������������ 1�϶� ���ʷ� ���� 0 �̸� pow(10,n)�� n�κ��� �ڸ��� n�� �����Ѵ�.
������������ 1�̾ƴѰ��� ������ �Լ������� �ߴ��Ѵ�.
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

