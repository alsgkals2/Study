// AcmTEST.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
const int MAXSIZE = 100001;
const int M = -1;
const int P = 1;

bool compare(char*f, char* l, int& num, int origin_count, int& wordNum) {
	
	int lastchar_startIndex = origin_count - num;

	for (int i = 0 ,j=lastchar_startIndex; i < num; i++,j++) {
		if (f[i] != l[j]) return false;
	}
	if (num != origin_count) wordNum=2;
	if (num == origin_count) wordNum = 1;
	return true;
}

int CountingWord(int num,int origin_count,char* word,int* indexInform, int fwi) {
	int count = 0;
	/*
	for (int i = 1; i < origin_count - num; i++) {
		if (word[0] == word[i]) {
			int j = 0;
			for (j = i; j < i + num; j++) {
				if (word[j - i] != word[j]) break;
			}
			if (j == i + num) count++;
		}
	}
*/
	int j = 0;
	int index = 0;
	for (int i = 0; i < fwi; i++) {
		index = indexInform[i];
		if (index + num >= origin_count) break;
		for (j = index; j < index + num; j++) {
			if (word[j - index] != word[j]) break;
		}
		if (j == index + num) count++;
	}

	return count;
}

int main()
{

	char *first_s = new char[MAXSIZE];
	char *last_s = new char[MAXSIZE];

	int count = 0;

	cin>>first_s;

	for (count = 0; first_s[count] !=NULL; count++) { last_s[count] = first_s[count]; }
	int num = count;
	int**saveResult = new int*[count];

	int wordNum = 0, resultIndex = 0;

	//첫문자의 인덱스저장
	int* saveFirstWordIndex = new int[count];
	int fwi = 0;

	for (int i = 1; i < count-1; i++) {
		if (first_s[i] == first_s[0]) {
			saveFirstWordIndex[fwi++] = i;
		}
	}

	///////////////////////////
	while (num > 0) {
		if (compare(first_s, last_s, num, count,wordNum)) {

			wordNum += CountingWord(num, count, first_s,saveFirstWordIndex,fwi);
			saveResult[resultIndex] = new int[2];
			saveResult[resultIndex][0] = num;
			saveResult[resultIndex][1] = wordNum;
			resultIndex++;
		}
		num--;
	}
	printf("%d\n",resultIndex);

	for (int i = resultIndex - 1; i >= 0; i--)printf("%d %d\n", saveResult[i][0], saveResult[i][1]);

    return 0;
}

