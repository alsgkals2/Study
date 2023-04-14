// WheresWaldorf.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
		}//새로갱신하려는게 더 위에있으면
		if (output[outputEle][1] > Index_j+1) {
			output[outputEle][1] = Index_j+1;
		}//새로갱신하려는게 더 왼쪽에 있으면
	

}
bool Find8direction(string* input, string inputWord, int Index_j, int Index_i) {

	int wordSize = inputWord.length();
	bool matchingSwit = true;
	int forWhile = 0;
	
	//위
	if (Index_i - wordSize >= -1) {
		while (++forWhile < wordSize) {
			if (input[Index_i - forWhile].at(Index_j) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//단어가 매칭이되면
			
			ResetOutput(Index_j, Index_i);
			return true;
		}
		forWhile = 0;
		matchingSwit = true;
	}
	//2시방향
	if (Index_i - wordSize >= -1 && Index_j + wordSize <= n) {
		while (++forWhile < wordSize) {
			if (input[Index_i - forWhile].at(Index_j+forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//단어가 매칭이되면

			return true;
		}
		forWhile = 0;
		matchingSwit = true;

	}
	//오른쪽
	if (Index_j + wordSize <= n) {
		while (++forWhile < wordSize) {
			if (input[Index_i].at(Index_j + forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//단어가 매칭이되면

			return true;
		}
		forWhile = 0;
		matchingSwit = true;
	}
	//5시방향
	if (Index_j + wordSize <= n && Index_i + wordSize <= m) {
		while (++forWhile < wordSize) {
			if (input[Index_i + forWhile].at(Index_j + forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//단어가 매칭이되면

			return true;
		}
		forWhile = 0;
		matchingSwit = true;

	}
	//아래
	if (Index_i + wordSize <= m) {
		while (++forWhile < wordSize) {
			if (input[Index_i + forWhile].at(Index_j) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//단어가 매칭이되면

			return true;
		}


		forWhile = 0;
		matchingSwit = true;
	}
	//7시방향
	if (Index_j - wordSize >= -1 && Index_i + wordSize <= m) {
		while (++forWhile < wordSize) {
			if (input[Index_i + forWhile].at(Index_j - forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//단어가 매칭이되면


			return true;
		}
		forWhile = 0;
		matchingSwit = true;

	}
	//왼쪽
	if (Index_j - wordSize >= -1) {
		while (++forWhile < wordSize) {
			if (input[Index_i].at(Index_j - forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//단어가 매칭이되면

			return true;
		}
		forWhile = 0;
		matchingSwit = true;

	}
	//10시방향
	if (Index_j - wordSize >= -1 && Index_i - wordSize >= -1) {
		while (++forWhile < wordSize) {
			if (input[Index_i - forWhile].at(Index_j - forWhile) != inputWord.at(forWhile)) {
				matchingSwit = false;
				break;
			}
		}
		if (matchingSwit) {//단어가 매칭이되면

			return true;
		}
		forWhile = 0;
		matchingSwit = true;
	}

	return false;
}
void Find(string* input, string inputWord) {
	//m:세로, n:가로
	
	

	for (int i = 0; i < m; i++) {
		if (input[i].find(inputWord.at(0)) != -1) {
			int startIndex_j = input[i].find(inputWord.at(0));

			//startindex부터 탐색시작
			//갯수탐색 및 매칭검사
			if (Find8direction(input, inputWord, startIndex_j, i)) {
				ResetOutput(startIndex_j, i);
				break; }
			else{//존재하는 단어가 없는경우
				 //그이후도 단어 존재할수 있으므로 탐색
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
		m = 0;//세로
		n = 0;//가로
		int k = 0;//키워드갯수

		cin >> m >> n;
		cin.ignore();
		string* input = new string[m];
		for (int i = 0; i < m; i++) {
			getline(cin, input[i]);
			AlphaTranlate(input[i]);//한줄입력할때마다 소문자로 변환
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

