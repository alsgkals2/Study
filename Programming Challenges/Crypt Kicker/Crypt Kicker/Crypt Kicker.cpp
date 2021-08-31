// Crypt Kicker.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct AlphaInform 
{
	char a='.';
	int num=1;
	AlphaInform *nextI = NULL;

}Ainform;

char* input = new char();
int n = 0;

void CandidateSave(char** dic,int** candidate, int alphaCount, int n, int* numInform, Ainform* alphaLink, int inputElement, int wordcount, int linkcount) {
	//input[inputelement]에 해당하는 글자를 alphaLink에서 탐색

	char firstAlpha = NULL;
	Ainform* next = new Ainform;
	int elementCount = 0;
	int i = 0;
	for (int lc = 0; lc < linkcount; lc++) {
		if (input[inputElement] == alphaLink[lc].a) {
			

			//alphaLink안의 알파벳과 dic에 해당하는 첫글자와 같고, 글자크기 일치하면 candidate에 저장
			next = &alphaLink[lc];
			if (next->nextI) {
				next = next->nextI;
				for (int nn = 0; nn < n; nn++) {
					if (next->a == dic[nn][0] && alphaCount == numInform[nn]) {
						candidate[wordcount - 1][elementCount++] = nn;
					}
				}
			}
		}
		
	}

}


char* CandidateEdit(char** dic, int** candidate, int wordcount, int inputElement, Ainform* alphaLink,int alphaCount,int* numInform,int alpha_count) {//wordcount는 1부터 시작
	int i = 0;
	int elementCount = 0;
	//첫글자에 해당하는 후보알파벳 탐색

	//candidate에 첫글자에 대한 후보들 추가
	inputElement = inputElement + 1;
	elementCount = 0;
	i = 0;
	int dicElement = 1;
	Ainform* next = new Ainform;
	while (input[inputElement] != ' ') {
		if (input[inputElement] == alphaLink[i].a) {//링크리스트에서 두번째알파벳과 일치하는걸 찾으면
			next =& alphaLink[i];
													//후보들중의 두번째알파벳과 일치하는지 검사한다.
			for (int nn = 0; nn < n; nn++)
				if (candidate[wordcount - 1][nn] >= 0)
				{
					//검사하면서 일치하지 않는 후보들은 -1로 수정
					while (next->nextI) {
						next = next->nextI;
						if (dic[candidate[wordcount - 1][nn]][dicElement] != next->a) {
							candidate[wordcount - 1][nn] = -1;
						}
					}
				}

			inputElement++;
			dicElement++;
			wordcount++;
			i = 0;
		}
		else i++;
	}
	//반복해서 남은후보값리턴
	

	//일치하지 않으면'.'
	 return ".";
 }

void Delete(Ainform a[]) {
	Ainform* first = a;

	Ainform* next = a;
	int high = 0;

	//num이 가장높은값 탐색
		while (next->nextI) {
			next = next->nextI;
			if (next->num>high) {
				high = next->num;
			}
		}


	next = a;
	
	//가장높은값 아니면 삭제
	AlphaInform *before = new AlphaInform;

		while (next->nextI) {
			before = next;
			next = next->nextI;
			
			if (next->num != high) {
				if (next->nextI) {
					next = next->nextI;
					before->nextI = next;
				}
				else if(!next->nextI) {
					before->nextI = NULL;
					break;
				}
			}
		}
}

int main()
{
	int i = 0, count = 0;

	cin >> n;

	char** dic = new char*[n];
	int *numInform = new int[n]; int numEnd = 1;//각 단어마다 알파뱃갯수 저장

	for (i = 0; i < n; i++) {
		numInform[i] = 0;
	}
	int swit = true;

	for (i = 0; i < n; i++) {
		dic[i] = new char();//암호화할 단어들
		cin >> dic[i];

		//암호화할 단어들의 글자크기 정보 저장
		count = 0; swit = true;
		for (int j = 0; dic[i][j]; j++) {
			count++;
		}
		numInform[i] = count;//숫자정보에 각 단어의 알파뱃 수 저장
	}

	//복호화할 단어 입력
	cin.ignore();//엔터입력 무시
	cin.getline(input, 80);

	//input(복호화 배열) 크기측정
	int input_count = 0;
	for (i = 0; input[i]; i++) { input_count++; }
	input[input_count++] = ' ';//맨마지막에도 공백값 추가

	//복호화할 단어들에 대해서 링크드리스트에 정보 추가
	Ainform *AlphaInform = new Ainform;
	int alpha_count = 0;
	swit = false;


	//복호화할 단어 목록 생성
	for (i = 0; i < input_count; i++) {
		if (input[i] != ' ') {
			//복호화할 단어 알파벳이 저장돼있는지 확인
			swit = false;
			for (int e = 0; e < alpha_count; e++) {
				//저장돼있으면 break
				if (AlphaInform[e].a == input[i]) { swit = true;  break; }
			}
			//저장돼있지 않으면 저장
			if (swit == false)
			{
				AlphaInform[alpha_count].a = input[i];
				AlphaInform[alpha_count].num = 1;
				AlphaInform[alpha_count].nextI = NULL;
				alpha_count++;
			}
		}
	}
	//빈도수 저장(dic,numinform을 이용해서 ainform에 정보연결

	Ainform *nextInform = new Ainform;
	count = 0;//복호화할 배열범위 카운팅
	int word_count = 0; //단어 카운팅
	swit = false;
	bool switinptWordCount = false;
	int wordcount = 0;
	int plusCount = 0;
	for (i = 0; i < input_count; i++) {//input 배열크기
		word_count++;
		if (input[i] != ' '&&switinptWordCount == false) {
			switinptWordCount = true;
			wordcount++;
		}
		else if (input[i] == ' ') {
			//단어 크기와 동일한 단어정보 링크
			switinptWordCount = false;
			--word_count;
			for (int j = 0; j < n; j++) {//n=사전단어갯수
				if (word_count == numInform[j]) { //사전에서 같은글자수를 가지면
					plusCount = -1;

					while (++plusCount != word_count) {//input에 넣은 한단어범위내에서 링크리스트에 추가하려고함.
						for (int a_count = 0; a_count < alpha_count; a_count++) {//alpha_count는 링크리스트갯수
							if (AlphaInform[a_count].a == input[i - word_count+plusCount]) {//링크에서 같은알파벳을 찾았으면
								swit = false;

								nextInform = &AlphaInform[a_count];
								//Ainform *lastInform = &AlphaInform[a_count];
								while (nextInform->nextI)
								{
									nextInform = nextInform->nextI;
									if (nextInform->a == dic[j][plusCount])
									{
										nextInform->num++; swit = true; break;
									}
								}
								if (swit == false)//정보가 저장돼있지 않으면
								{
									
									/*while (lastInform->nextI) { //마지막위치탐색
										lastInform = lastInform->nextI;
									}*/
									nextInform->nextI = new Ainform;
									nextInform = nextInform->nextI;

									nextInform->a = dic[j][plusCount];

									
									break;
								}
							}
						}
					}
				}
			}
			word_count = 0;//글자갯수 초기화
		}
	}
	

//링크드리스트중 빈도수가 가장높은것(들) 이외에 모두 삭제.
	for (i = 0; i < alpha_count; i++) {
		Delete(&AlphaInform[i]);
	}


	//복호화

	//wordcount:input단어단위 갯수
	int** candidate = new int*[wordcount];//각 input단어에 대한 후보들의 요소를 저장함
	for (i = 0; i < wordcount; i++) {
		candidate[i] = new int();
	}

	//단어단위만큼의 배열에 알파벳갯수 저장
	int* alphaCount = new int[wordcount]; //알파벳갯수
	for (i = 0; i < wordcount; i++) {
		alphaCount[i] = 0;
	}

	int j = 0;
	for(i=0; i<input_count; i++)
	{
		if (input[i] != ' ')
		{
			alphaCount[j]++;
		}
		else if (input[i] == ' ')
		{
			j++;
		}
	}



	//후보들 저장
	switinptWordCount = false;
	wordcount = 0;
	for (i = 0; i < input_count; i++) {
		//input[i]가 ' '가 아닌경우 가장첫글자에 해당하는 후보목록들을 candidate에 저장하는 함수
		if (input[i] != ' '&&switinptWordCount == false) {//첫글자인경우
			switinptWordCount = true; wordcount++;
			CandidateSave(dic,candidate,alphaCount[wordcount-1],n,numInform,AlphaInform,i,wordcount,alpha_count);
		}
		else if (input[i] == ' ') { switinptWordCount = false; }//공백인경우
	}



	//후보들 비교

	switinptWordCount = false;
	wordcount = 0;
	for (i = 0; i < input_count; i++) {
	 //input[i]가 ' '가 아닌경우 가장첫글자에 해당하는 후보목록들을 candidate에 저장하는 함수
		if (input[i] != ' '&&switinptWordCount == false) {//첫글자인경우
			switinptWordCount = true; wordcount++;
			CandidateEdit(dic,candidate ,wordcount,i, AlphaInform, alphaCount[wordcount-1], numInform, alpha_count);
		}
		else if (input[i] == ' ') { switinptWordCount = false; }//공백인경우
	}


	//할당 해제

	return 0;
}