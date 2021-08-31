// aba.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int maxsize = 100000;
int main()
{
	char* input = new char[maxsize];
	cin >> input;
	int count = 0;
	for (count = 0; input[count] != NULL; count++) {}

	int l = count;
	int output=1;

	for (int s = 0; s < count; s++) {
		for (l = count-1; l >= s; l--) {
			if (input[s] == input[l])
			{
				int forcomC = 1;
				int ss = s, ll = l;
				while (++ss < count&& --ll >= 0 && input[ss] == input[ll]) {
					forcomC++;
					if (ss == ll) {
						forcomC = forcomC * 2 - 1;
						break;
					}
					else if (ss-1 == ll) {
						forcomC = forcomC*2-2 ; break;
					}
				}

				if (forcomC > output) output = forcomC;
			}
		}

	}

	cout << output;

    return 0;
}

