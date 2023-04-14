// Doublet.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;
string* input;//�ܾ��Է¿�
 bool** insideWord;
int wordNum;//��������
bool** cInsideWord;


bool** copyBool(bool** insideWord, int wordnum) {
	bool** cInsideWord = new bool*[wordnum];
	
	for (int i = 0; i < wordnum; i++) {
		cInsideWord[i] = new bool[wordnum];
		
		
		for (int j = 0; j < wordnum; j++) cInsideWord[i][j] = insideWord[i][j];
	}

	return cInsideWord;
}

int minSize = 25144;
int sequenceEle = 0;

void checkingSequence(int firstEle, int lastEle, int** savesequence,int size,int* cSaveSequence) {

	int* thisSaveSequence = new int[wordNum+1];
	for(int i=0; i<size; i++)
		thisSaveSequence[i] = cSaveSequence[i];

	for (int i = 0; i < wordNum+1; i++) {
		if (!cInsideWord[firstEle][i])//�����̰� (tracking)
		{
			if (size < minSize) {// ���� ���� �������������� ���������ΰ��

				thisSaveSequence[size] = i;

				if (i == lastEle) {//lastele�� �����ߴٸ�

					minSize = size;
					for (int s = 0; s < size+1; s++)
						savesequence[sequenceEle][s] = thisSaveSequence[s];
					sequenceEle++;
					break; //���̻� �˾ƺ��ʿ䰡 �����Ƿ� (back)
				}
				else {
					cInsideWord[i][firstEle] = true;//������ ��ı׷����̹Ƿ� ��Ī�̹Ƿ� �Ѵ� ���İ���(���̻� �Ȱ��ĵ���)�� ǥ��
					cInsideWord[firstEle][i] = true;
					checkingSequence(i, lastEle, savesequence, size+1, thisSaveSequence);
				}
			}

			//������ ����� �������������� ���������Ƿ� ���̻� �˻����ʿ� �����Ƿ� �迭�ʱ�ȭ �� for�� ����
			else {
				int inc = -1;
				break;
			}
		}
	}
}

int main()
{
	input = new string[25144];//����
	string* firstInput; string* lastInput; //Ž���Ҵܾ�


	wordNum = -1;
	int numDifference = 0;

	//<�׷��� �����ϱ�>
	//�ܾ��Է¹�����
	while (cin.peek() != '\n') {
		getline(cin, input[++wordNum]);
	}

	insideWord = new bool*[wordNum+1];
	for (int i = 0; i < wordNum+1; i++) { insideWord[i] = new bool[wordNum+1]; }

	for (int i = 0; i <= wordNum; i++) {
		for (int j =i+1; j<=wordNum; j++) {
		
			if (i == j || !insideWord[i][j] || input[i].size() != input[j].size())
				continue;

			int inc = 0;
			numDifference = 0;
			while (1) {
				if(input[i][inc] != input[j][inc] != NULL) {
					numDifference++;
					if (numDifference >= 2) break;
				}
				else if (input[j][inc] == NULL) break;
				inc++;
			}
				if (numDifference == 1) {
					insideWord[i][j] = false;
					insideWord[j][i] = false;
				}
		}
	
	}

	int tk = 0;
	int** resultEle = new int*[100];

	cin.ignore();
	string twoInput;
	firstInput = new string[wordNum + 1]; lastInput = new string[wordNum + 1];

	while (1) {
		int i = 0;
		getline(cin, twoInput);
		if (twoInput.empty()) break;

		for (int i = 0; twoInput[i]; i++) {
			if (twoInput[i] == ' ') {
				int twoinputsize = twoInput.size();
				for (int j = i + 1; j < twoinputsize; j++)
				{ lastInput[tk] += twoInput[j]; }
				break;
				
			}
			firstInput[tk] += twoInput[i];

		}
		

		resultEle[tk] =new int[wordNum+1];
		for (int i = 0; i < wordNum + 1; i++)
			resultEle[tk][i] = -1;

		//���纻 insideWord
		cInsideWord = new bool*[wordNum + 1];
		for (int i = 0; i < wordNum + 1; i++) cInsideWord[i] = new bool[wordNum + 1];
		cInsideWord = copyBool(insideWord,wordNum+1);


		int inputinc = -1;
		int saveFirstInput = -1, saveLastInput = -1;
		//firstinput,lastinput�� ��Ҹ� ���Ѵ�.
		while (input[++inputinc][0] != NULL) {
			if (input[inputinc].compare(firstInput[tk]) == 0) { saveFirstInput = inputinc; }
			else if (input[inputinc].compare(lastInput[tk]) == 0) { saveLastInput = inputinc; }

			if (saveFirstInput != -1 && saveLastInput != -1) break;
		}
		//�ʱ�ȭ
		int** saveSequence = new int*[100];
		for (int i = 0; i < 100; i++) {
			saveSequence[i] = new int[wordNum+1];
			for (int j = 0; j < wordNum + 1; j++)
				saveSequence[i][j] = -1;
		}
		//�ʱ�ȭ
		int* cSaveSequence = new int[wordNum + 1];
		for (int i = 0; i < wordNum + 1; i++) cSaveSequence[i] = -1;

		checkingSequence(saveFirstInput, saveLastInput,  saveSequence, 0, cSaveSequence); //��Ʈ��ŷ ����


		if (saveSequence[0][0] != -1) { //�������� ����Ȼ����̸�
			int smallestEle = 25144;
			int forCompareSize = 25144;

			//����ª�� �ܾ������ �˻�
			for (int i = 0; saveSequence[i][0] != -1; i++) {
				int j = 0;
				for (int size = 0; saveSequence[i][j] != -1; j++) {
				}

				if (j < forCompareSize) { smallestEle = i; forCompareSize = j; }
				if (j == 1) break; //���� ª�����
			}
		
			resultEle[tk] = saveSequence[smallestEle];//����ª�� ������ ����
		}
		tk++;
		twoInput.clear(); //�״����� �Է������� clear
	}

	for (int i = 0; i < tk; i++) {
		if (resultEle[i][0] == -1) cout << "No Soultion." << "\n\n"; //�������� �߰ߵ������� ���
		else {
			cout << firstInput[i] << '\n';
			for (int j = 0; resultEle[i][j] != -1; j++) {
				cout << input[resultEle[i][j]] << '\n';
			}
			cout << '\n';

		}

	}

	return 0;
}

