// Stack'em.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <string.h>
using namespace std;


class TecNum {
public:
	int tecNum;
	int *i = new int[26];
	int *j = new int[26];

	TecNum();
};

TecNum::TecNum() {
	tecNum = 0;
	for (int init = 0; init < 26; init++)
		i[init] = -1;
	for (int init = 0; init < 26; init++)
		j[init] = -1;
}
char* transfer(int setNum) {

	if (setNum == 10) {return "Jack";}
	else if (setNum == 11) { return "Queen"; }
	else if (setNum == 12) { return "King"; }
	else if (setNum == 13) { return "Ace"; }
}

void print(int setNum) {
	
	if (setNum <= 13) {
		if (setNum >= 10) cout<<transfer((setNum % 14))<<" of ";
		else { cout << (setNum % 14) + 1 << " of "; }
	}
	else if (setNum <= 26) {
		if (setNum >= 23) cout << transfer(((setNum +1)% 14)) << " of ";
		else { cout << ((setNum+1) % 14) + 1 << " of "; }
	}
	else if (setNum <=39) {
		if (setNum >= 36) cout << transfer(((setNum + 2) % 14)) << " of ";
		else { cout << ((setNum + 2) % 14) + 1 << " of "; }
	}
	else {
		if (setNum >= 49) cout << transfer(((setNum + 3) % 14)) << " of ";
		else { cout << ((setNum + 3) % 14) + 1 << " of "; }
	}

	if ((setNum - 1) / 13 == 0) cout << "Clubs" << endl;
	else if ((setNum - 1) / 13 == 1)cout << "Diamonds" << endl;
	else if ((setNum - 1) / 13 == 2)cout << "Hearts" << endl;
	else cout << "Spades" << endl;
}

void change(int &i ,int& j) { //배열넣음
	int temp = 0;

	//요소를 넣는다.
	temp = j;
	j = i;
	i = temp;
}
const int startNum = 1;

int main()
{
	int T = 0;//테스트케이스 갯수
	int N = 0;//섞기방법갯수
	
	//cin >> T;
	//while (T-- != 0) {
		//cin.ignore();
		cin >> N;

		TecNum *tn = new TecNum[N];

		int ** setNum = new int*[N];
		for (int i = 0; i < N; i++) {
			setNum[i] = new int[52];
		}
		int start = startNum;

		//출력함수 1~52셋팅
		int* output = new int[52];
		for (int i = 0; i < 52; i++) {
			output[i] = start++;
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < 52; j++) {
				cin >> setNum[i][j];
			}

		int* k = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> k[i];
		}
		bool tnExist = false;
		start = startNum;
		int tnElementInc = 0;
		for (int i = 0; i < N; i++) {
			//cin >> k;
			tnExist = false;
			//k번째 섞기방법이 tn링크리스트에 존재하는지 검사	
			for (int j = 0; j < N; j++) {
				if (tn[j].tecNum == k[i]) {//존재하는 경우 값바꿈
					tnExist = true;

					tnElementInc = 0;
					while (1) {
						if (tn[j].i[tnElementInc] == -1) break;
						else {
							change(output[tn[j].i[tnElementInc]], output[tn[j].j[tnElementInc]]);
							tnElementInc++;
						}
					}
				}

			}
			if (tnExist == false)//존재하지 않으면 링크리스트에 추가하고 값바꿈
			{
				start = startNum;
				tnElementInc = 0;
				for (int z = 0; z < 52; z++) {
					if (setNum[i][z] != start++) {
						tn[i].tecNum = k[i];
						////
						while (1) {
							if (tn[i].i[tnElementInc] == -1) {
								tn[i].i[tnElementInc] = setNum[i][z]; break;
							}
							else if (tn[i].i[tnElementInc] != -1 && tn[i].j[tnElementInc] == -1)
							{
								tn[i].j[tnElementInc] = setNum[i][z];
								change(output[tn[i].i[tnElementInc] - 1], output[tn[i].j[tnElementInc] - 1]);
								break;
							}
							else tnElementInc++;
						}
					}
				}

			}

			for (int i = 0; i < 52; i++) {
				print(output[i]);
			}
		}


		for (int i = 0; i < N; i++) {
			delete[] setNum[i];
		}
		delete[] setNum;
		delete tn;

	//}


    return 0;
}

	