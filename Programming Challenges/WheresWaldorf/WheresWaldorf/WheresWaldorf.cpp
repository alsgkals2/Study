// WheresWaldorf.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include <iostream>>
#include <string>


using namespace std;

void AlphaTranlate(string &input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) <= 90 && input.at(i) >= 65) {
			input[i] = input.at(i) + 32;
		}
	}
}

int** output; int outputEle; int m, n;
void ResetOutput(int Index_j, int Index_i) {
		if (output[outputEle][0] > Index_i + 1) {
			output[outputEle][0] = Index_i + 1;
		}//���ΰ����Ϸ��°� �� ����������
		if (output[outputEle][1] > Index_j+1) {
			output[outputEle][1] = Index_j+1;
		}//���ΰ����Ϸ��°� �� ���ʿ� ������
	

}
bool Find8direction(string* input, string inputWord, int Index_j, int Index_i) {

	int wordSize = inputWord.length();
	bool matchingSwit = true;
	int forWhile = 0;
	
	//��
	if (Index_i - wordSize >= -1) {
		while (++forWhile < wordSize) {
			if (input[Index_i - forWhile].at(Index_j) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//�ܾ ��Ī�̵Ǹ�
			
			ResetOutput(Index_j, Index_i);
			return true;
		}
		forWhile = 0;
		matchingSwit = true;
	}
	//2�ù���
	if (Index_i - wordSize >= -1 && Index_j + wordSize <= n) {
		while (++forWhile < wordSize) {
			if (input[Index_i - forWhile].at(Index_j+forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//�ܾ ��Ī�̵Ǹ�

			return true;
		}
		forWhile = 0;
		matchingSwit = true;

	}
	//������
	if (Index_j + wordSize <= n) {
		while (++forWhile < wordSize) {
			if (input[Index_i].at(Index_j + forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//�ܾ ��Ī�̵Ǹ�

			return true;
		}
		forWhile = 0;
		matchingSwit = true;
	}
	//5�ù���
	if (Index_j + wordSize <= n && Index_i + wordSize <= m) {
		while (++forWhile < wordSize) {
			if (input[Index_i + forWhile].at(Index_j + forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//�ܾ ��Ī�̵Ǹ�

			return true;
		}
		forWhile = 0;
		matchingSwit = true;

	}
	//�Ʒ�
	if (Index_i + wordSize <= m) {
		while (++forWhile < wordSize) {
			if (input[Index_i + forWhile].at(Index_j) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//�ܾ ��Ī�̵Ǹ�

			return true;
		}


		forWhile = 0;
		matchingSwit = true;
	}
	//7�ù���
	if (Index_j - wordSize >= -1 && Index_i + wordSize <= m) {
		while (++forWhile < wordSize) {
			if (input[Index_i + forWhile].at(Index_j - forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//�ܾ ��Ī�̵Ǹ�


			return true;
		}
		forWhile = 0;
		matchingSwit = true;

	}
	//����
	if (Index_j - wordSize >= -1) {
		while (++forWhile < wordSize) {
			if (input[Index_i].at(Index_j - forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//�ܾ ��Ī�̵Ǹ�

			return true;
		}
		forWhile = 0;
		matchingSwit = true;

	}
	//10�ù���
	if (Index_j - wordSize >= -1 && Index_i - wordSize >= -1) {
		while (++forWhile < wordSize) {
			if (input[Index_i - forWhile].at(Index_j - forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//�ܾ ��Ī�̵Ǹ�

			return true;
		}
		forWhile = 0;
		matchingSwit = true;
	}

	return false;
}
void Find(string* input, string inputWord) {
	//m:����, n:����
	
	

	for (int i = 0; i < m; i++) {
		if (input[i].find(inputWord.at(0)) != -1) {
			int startIndex_j = input[i].find(inputWord.at(0));

			//startindex���� Ž������
			//����Ž�� �� ��Ī�˻�
			if (Find8direction(input, inputWord, startIndex_j, i)) {
				ResetOutput(startIndex_j, i);
				break; }
			else{//�����ϴ� �ܾ ���°��
				 //�����ĵ� �ܾ� �����Ҽ� �����Ƿ� Ž��
				for (int afterstart = startIndex_j + 1; afterstart < n; afterstart++) {

					if (input[i][afterstart] == inputWord.at(0))
					{
						if (Find8direction(input, inputWord, afterstart, i)) {
							ResetOutput(afterstart, i);
							break; }
					}
				}
			}
		}

	}

}

int main()
{
	int t = 0;

	cin >> t;
	cin.ignore();
	while (t-- != 0) {
		m = 0;//����
		n = 0;//����
		int k = 0;//Ű���尹��

		cin >> m >> n;
		cin.ignore();
		string* input = new string[m];
		for (int i = 0; i < m; i++) {
			getline(cin, input[i]);
			AlphaTranlate(input[i]);//�����Է��Ҷ����� �ҹ��ڷ� ��ȯ
		}
		cin >> k;
		cin.ignore();
		string* inputWord = new string[k];
		output = new int*[m];
		for (int i = 0; i < m; i++) {
			output[i] = new int[2];
			output[i][0] = m;
			output[i][1] = n;
		}

		outputEle = 0;
		for (int i = 0; i < k; i++) {
			getline(cin, inputWord[i]);
			AlphaTranlate(inputWord[i]);
			outputEle = i;
			Find(input, inputWord[i]);
		}
		for (int i = 0; i < k; i++) {
			cout << output[i][0] << " " << output[i][1] << endl;
		}
		cout << endl;
	}

	return 0;
}

