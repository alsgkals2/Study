// ShellSort.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
const int MAXTultleNum = 200;

int Compare(string* old, string* nnew,int& sn) {
	int count = 0;
	int snOldIndex = sn-1;
	int snNewIndex = sn - 1;

	while(snOldIndex>-1){
		if (old[snOldIndex].compare(nnew[snNewIndex]) != 0) { count++; snOldIndex--; }
		snOldIndex--;
		snNewIndex--;
	}

	return count;
}


int main()
{
	int ori_tc = 0;
	int TC = 0;
	cin >> TC;
	ori_tc = TC;
	int stringNum = 0;
	string* old_name;
	string* new_name;

	while (TC-- != 0) {
		if (TC != ori_tc - 1) cout << '\n';
		stringNum = 0;
		old_name = new string[MAXTultleNum];
		new_name = new string[MAXTultleNum];
		
		cin >> stringNum;
		cin.ignore();

		for (int sn = 0; sn < stringNum; sn++) {
			getline(cin, old_name[sn]);
		}
		for (int sn = 0; sn < stringNum; sn++) {
			getline(cin, new_name[sn]);
		}

		int count = Compare(old_name, new_name, stringNum);
		for (int c = count - 1; c >= 0; c--) {
			cout << new_name[c] << endl;
		}

	}

	return 0;
}

