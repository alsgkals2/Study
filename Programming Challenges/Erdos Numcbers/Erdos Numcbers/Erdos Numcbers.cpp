// Erdos Numcbers.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <iostream>
#include <string.h>
using namespace std;


struct ThesisNumName {
	char* name = new char[40];
	ThesisNumName* Tn = NULL;
};
struct ThesisNum {
	int Num = -1;
	int Erodsnum = 0;
	bool concerned = false;
	ThesisNumName* Tn = NULL;
};

ThesisNum* thesisnum;
void addThesisNumName(int thesisnumElement, char* name) {
	if (!thesisnum[thesisnumElement].Tn) {
		thesisnum[thesisnumElement].Tn = new ThesisNumName();
		thesisnum[thesisnumElement].Tn->name = name;
	}
	else if (thesisnum[thesisnumElement].Tn) {
		ThesisNumName *startName = thesisnum[thesisnumElement].Tn;
		while (startName->Tn) {
			startName = startName->Tn;
		}
		startName->Tn = new ThesisNumName();
		startName->Tn->name = name;
	}
}
void enterErdos(char* setName, ThesisNum& tn) {
	if (strncmp("Erdos, P.", setName, 9) == 0) {
		tn.Erodsnum = 1;
	}
}
void searchErosNum1(char** inputName, ThesisNum& tn, int N, int* inputNameErdosNum, int erodosNum) {
	tn.concerned = true;//논문이 관여됐으므로 true
	ThesisNumName *next = tn.Tn;

	while (next) {
		for (int n = 0; n < N; n++) {

			if (strncmp(next->name, inputName[n], strlen(inputName[n])) == 0 && inputNameErdosNum[n] == 0) {

				inputNameErdosNum[n] = erodosNum;
			}
		}
		next = next->Tn;
	}
}
bool EnterComplete(int* inputNameErdosNum, int N) {
	for (int n = 0; n < N; n++) {
		if (inputNameErdosNum[n] == 0) return false; //아직 모두 에르도스를 구하지 않았다.
	}
	return true;//모든 에르도스를 구했다.
}
bool EnterComplete(int P) {
	for (int p = 0; p < P; p++) {
		if (thesisnum[p].concerned == false) return false; //모든 논문이 검사되지 않았다.
	}
	return true;
}
bool searchErosNum2(ThesisNum &tn, char* compareName, int Erodosnum) {

	ThesisNumName* nextThesis = tn.Tn;
	while (nextThesis) {
		if (strncmp(compareName, nextThesis->name, 40) == 0) {
			tn.Erodsnum = Erodosnum;
			return true; //에르도스가 2인애들이다.
		}
		nextThesis = nextThesis->Tn;
	}
	return false; //에르도스가 2인애들이 아니다.

}

int main()
{
	int database = 0;
	while (1) {
		database++;
		int P = 0, N = 0;
		cin >> P >> N;
		if (P == 0 && N == 0) break;

		//논문명 배열 초기화
		char ** inputThesisName = new char*[P];
		for (int i = 0; i < P; i++) {
			inputThesisName[i] = new char[250];
		}
		for (int i = 0; i < P; i++)
			for (int j = 0; j < 250; j++) {
				inputThesisName[i][j] = NULL;
			}

		cin.ignore();
		for (int i = 0; i < P; i++) {
			cin.getline(inputThesisName[i], 250);
		}

		int incElement = 0;

		thesisnum = new ThesisNum[P];
		int startElement = 0;
		int setNameElement = 0;
		char* setName = new char[40];

		for (int i = 0; i < P; i++) {
			thesisnum[i].Num = i;
			incElement = 0;
			while (1) {
				if (inputThesisName[i][incElement] == '.') {
					if (inputThesisName[i][incElement + 1] == ',')
					{
						setName[setNameElement] = '.';

						//에르도스와 1연관인이면 번호표시
						enterErdos(setName, thesisnum[i]);
						//링크드리스트에 이름추가
						addThesisNumName(i, setName);
						setName = new char[40];
						setNameElement = 0;
						incElement = incElement + 3;//.다음 다음 다음부터가 다른이름시작
					}
					else if (inputThesisName[i][incElement + 1] == ':')
					{
						setName[setNameElement] = '.';

						enterErdos(setName, thesisnum[i]);
						addThesisNumName(i, setName);
						setName = new char[40];
						setNameElement = 0;
						incElement = 0; break;
					}
				}
				setName[setNameElement++] = inputThesisName[i][incElement];
				incElement++;
			}
		}

		char** inputName = new char*[N];

		for (int i = 0; i < N; i++) {
			inputName[i] = new char[40];
			cin.getline(inputName[i], 40);
		}




		int* inputNameErdosNum = new int[N];//각이름대한 에르도스넘버
		for (int n = 0; n < N; n++) { inputNameErdosNum[n] = 0; }

		//에로스넘버 1 검사
		for (int i = 0; i < P; i++) {
			if (thesisnum[i].Erodsnum == 1)
				searchErosNum1(inputName, thesisnum[i], N, inputNameErdosNum, 1);

		}

		if (EnterComplete(P) == false) { //모든 에르도스를 구하지 않았다면
										 //에로도스넘버 2검사
			int Erodosnum = 0;

			char* compareName = new char[40];
			ThesisNumName *compareTn = new ThesisNumName();

			//에르도스연관 2와관련된 링크드리스트 찾기
			int maxErosnum = 0;
			while (Erodosnum++ < P) {
				for (int p = 0; p < P; p++) {
					if (thesisnum[p].Erodsnum == Erodosnum) //에르도스1인애들찾으면
					{
						compareTn = thesisnum[p].Tn;

						while (compareTn) {
							compareName = new char[40];
							compareName = compareTn->name;//1에 해당하는 애들이
							compareTn = compareTn->Tn;


							for (int i = 0; i < P; i++) {
								if (EnterComplete(P) == true) break;

								if (thesisnum[i].concerned == false) {//아직 조사되지않은 논문들에 대해서
									if (searchErosNum2(thesisnum[i], compareName, Erodosnum + 1) == true)//2인애들이면
									{
										searchErosNum1(inputName, thesisnum[i], N, inputNameErdosNum, Erodosnum + 1);//각각의 링크요소들과 name요소들과 비교한다.
									}
								}
							}
						}
					}
				}
			}

			//cout << endl;
			cout << "Database #" << database << endl;
			for (int n = 0; n < N; n++) {
				cout << inputName[n] << " ";
				if (inputNameErdosNum[n] != 0) cout <<":"<< inputNameErdosNum[n] << endl;
				else { cout << "infinity" << endl; }
			}
			//모든논문에 대한 검사가 끝났으면 번호가 매겨지지않은 애들에대해선 infinity부여

		}
	}
	return 0;
}

