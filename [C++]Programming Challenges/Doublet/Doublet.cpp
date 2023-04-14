// Doublet.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;
string* input;//단어입력용
 bool** insideWord;
int wordNum;//사전갯수
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
		if (!cInsideWord[firstEle][i])//더블릿이고 (tracking)
		{
			if (size < minSize) {// 가장 작은 시퀀스갯수보다 작은상태인경우

				thisSaveSequence[size] = i;

				if (i == lastEle) {//lastele에 도달했다면

					minSize = size;
					for (int s = 0; s < size+1; s++)
						savesequence[sequenceEle][s] = thisSaveSequence[s];
					sequenceEle++;
					break; //더이상 알아볼필요가 없으므로 (back)
				}
				else {
					cInsideWord[i][firstEle] = true;//무방향 행렬그래프이므로 대칭이므로 둘다 거쳐갔음(더이상 안거쳐도됨)을 표시
					cInsideWord[firstEle][i] = true;
					checkingSequence(i, lastEle, savesequence, size+1, thisSaveSequence);
				}
			}

			//기존에 저장된 시퀀스갯수보다 작지않으므로 더이상 검사할필요 없으므로 배열초기화 및 for문 종료
			else {
				int inc = -1;
				break;
			}
		}
	}
}

int main()
{
	input = new string[25144];//사전
	string* firstInput; string* lastInput; //탐색할단어


	wordNum = -1;
	int numDifference = 0;

	//<그래프 형성하기>
	//단어입력받으면
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

		//복사본 insideWord
		cInsideWord = new bool*[wordNum + 1];
		for (int i = 0; i < wordNum + 1; i++) cInsideWord[i] = new bool[wordNum + 1];
		cInsideWord = copyBool(insideWord,wordNum+1);


		int inputinc = -1;
		int saveFirstInput = -1, saveLastInput = -1;
		//firstinput,lastinput의 요소를 구한다.
		while (input[++inputinc][0] != NULL) {
			if (input[inputinc].compare(firstInput[tk]) == 0) { saveFirstInput = inputinc; }
			else if (input[inputinc].compare(lastInput[tk]) == 0) { saveLastInput = inputinc; }

			if (saveFirstInput != -1 && saveLastInput != -1) break;
		}
		//초기화
		int** saveSequence = new int*[100];
		for (int i = 0; i < 100; i++) {
			saveSequence[i] = new int[wordNum+1];
			for (int j = 0; j < wordNum + 1; j++)
				saveSequence[i][j] = -1;
		}
		//초기화
		int* cSaveSequence = new int[wordNum + 1];
		for (int i = 0; i < wordNum + 1; i++) cSaveSequence[i] = -1;

		checkingSequence(saveFirstInput, saveLastInput,  saveSequence, 0, cSaveSequence); //백트랙킹 시작


		if (saveSequence[0][0] != -1) { //시퀀스가 저장된상태이면
			int smallestEle = 25144;
			int forCompareSize = 25144;

			//가장짧은 단어시퀀스 검사
			for (int i = 0; saveSequence[i][0] != -1; i++) {
				int j = 0;
				for (int size = 0; saveSequence[i][j] != -1; j++) {
				}

				if (j < forCompareSize) { smallestEle = i; forCompareSize = j; }
				if (j == 1) break; //가장 짧은경우
			}
		
			resultEle[tk] = saveSequence[smallestEle];//가장짧은 시퀀스 저장
		}
		tk++;
		twoInput.clear(); //그다음의 입력을위해 clear
	}

	for (int i = 0; i < tk; i++) {
		if (resultEle[i][0] == -1) cout << "No Soultion." << "\n\n"; //시퀀스가 발견되지않은 경우
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

