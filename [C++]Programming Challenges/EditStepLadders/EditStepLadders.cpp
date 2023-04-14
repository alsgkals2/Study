// EditStepLadders.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool** check = new bool*[16];//���� : ���ĺ�, ���� : ���ڿ���ġ
char** Word;
int Wordindex;

void DeleteChar(char*, int,int&);
void ChangeChar(char*, int,int&);
void AddChar(char*, int,int&);


bool binarySearch(char* newWord, int left, int right) {
	int middle;
	
	while (left <= right) {
		middle = (left + right) / 2;

		int returnResult = strcmp(newWord, Word[middle]);

		if (returnResult == 0) {
			return true;
		}
		else if (returnResult < 0) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}

	return false;
}


void DeleteChar(char* newWord,char* word,int wSize,int& cResult) {
	int newWordIndex;

	if (wSize == 1) return;

	for (int i = 0; i < wSize; i++) {
		newWordIndex = 0;
		for (int lefti = 0; lefti < i; lefti++) {
			newWord[newWordIndex++] = word[lefti];
		}
		for (int righti = i + 1; righti < wSize+1; righti++) { // \0���� �����ϱ����� +1����
			newWord[newWordIndex++] = word[righti];
		}

		//newWord�� �߰��� �Ϸ������ check�迭���� Ȯ��
		if (i < wSize - 1&&check[i][newWord[i]-'a'] == true && binarySearch(newWord,0,Wordindex-1))
		{
			cResult++;
		}
		else if (i == wSize - 1 && check[0][newWord[0] - 'a'] == true && binarySearch(newWord, 0, Wordindex - 1)) {
			cResult++;
		}
	}

}

void ChangeChar(char* newWord,char* word, int wSize,int& cResult) {
	
	for (int i = 0; i < wSize; i++) {

		for (int alpha = 'a'; alpha <= 'z'; alpha++) {
			if (newWord[i] == alpha) continue; //���� ���ڿ��ΰ�� ī��Ʈx

			newWord[i] = alpha;
			if (check[i][newWord[i] - 'a'] == true && binarySearch(newWord, 0, Wordindex - 1))
			{
				cResult++;
			}

			newWord[i] = word[i];
		}

	}


}

void AddChar(char*newWord,char* word, int wSize, int& cResult) {
	int newWordIndex;
	newWord[wSize + 1] = '\0';

	for (int i = 0; i <= wSize; i++) {
		newWordIndex = 0;
		for (int lefti = 0; lefti < i; lefti++) {
			newWord[newWordIndex++] = word[lefti];
		}

		newWordIndex++;
		

		for (int righti = i; righti < wSize ; righti++) { // \0���� �����ϱ����� +1����
			newWord[newWordIndex++] = word[righti];
		}

		//newWord�� �߰��� �Ϸ������ check�迭���� Ȯ��
		for (int alpha = 'a'; alpha <= 'z'; alpha++) {
			newWord[i] = alpha;

			if (check[i][newWord[i] - 'a'] == true && binarySearch(newWord, 0, Wordindex - 1))
			{
				cResult++;
			}
		}
	}


}


int main()
{
	//char* test = new char[3];
	//cout << sizeof(test);
	Word = new char*[25000];
	for (int i = 0; i < 25000; i++) Word[i] = new char[17];

	int result = 0;
	Wordindex = -1;
	for (int i = 0; i < 16; i++) {
		check[i] = new bool[26];
		for (int j = 0; j < 26; j++) {
			check[i][j] = false;
		}
	}

	while (cin>>Word[++Wordindex]) {

		//�� ������ ��ġ���� ������(check)
		for (int i = 0; i < strlen(Word[Wordindex]); i++) {
			check[i][Word[Wordindex][i] - 'a'] = true;
		}
	}

	char* newWord = new char[17];

	for (int i = 0; i < Wordindex; i++) {
		int compareReulst = 1; // �ڱ��ڽŵ� �����ϹǷ� 1���� ī����
		int wordSize = strlen(Word[i]);
		for (int i = wordSize-1; i < wordSize+2; i++) newWord[i] = 0;

		
		DeleteChar(newWord,Word[i], wordSize, compareReulst);


		strncpy_s(newWord, 17, Word[i], wordSize);//��n���̸�ŭ �������� �� �̻�ũ���� ����ũ�⸦ �������Ѵ�. �׷��� ����max���� 16+1
		ChangeChar(newWord, Word[i], wordSize, compareReulst);

		AddChar(newWord, Word[i], wordSize, compareReulst);

		if (compareReulst > result) result = compareReulst;
	}

	cout << result << '\n';

    return 0;
}

