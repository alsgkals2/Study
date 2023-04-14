// Erdos Numcbers.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	tn.concerned = true;//���� ���������Ƿ� true
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
		if (inputNameErdosNum[n] == 0) return false; //���� ��� ���������� ������ �ʾҴ�.
	}
	return true;//��� ���������� ���ߴ�.
}
bool EnterComplete(int P) {
	for (int p = 0; p < P; p++) {
		if (thesisnum[p].concerned == false) return false; //��� ���� �˻���� �ʾҴ�.
	}
	return true;
}
bool searchErosNum2(ThesisNum &tn, char* compareName, int Erodosnum) {

	ThesisNumName* nextThesis = tn.Tn;
	while (nextThesis) {
		if (strncmp(compareName, nextThesis->name, 40) == 0) {
			tn.Erodsnum = Erodosnum;
			return true; //���������� 2�ξֵ��̴�.
		}
		nextThesis = nextThesis->Tn;
	}
	return false; //���������� 2�ξֵ��� �ƴϴ�.

}

int main()
{
	int database = 0;
	while (1) {
		database++;
		int P = 0, N = 0;
		cin >> P >> N;
		if (P == 0 && N == 0) break;

		//���� �迭 �ʱ�ȭ
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

						//���������� 1�������̸� ��ȣǥ��
						enterErdos(setName, thesisnum[i]);
						//��ũ�帮��Ʈ�� �̸��߰�
						addThesisNumName(i, setName);
						setName = new char[40];
						setNameElement = 0;
						incElement = incElement + 3;//.���� ���� �������Ͱ� �ٸ��̸�����
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




		int* inputNameErdosNum = new int[N];//���̸����� ���������ѹ�
		for (int n = 0; n < N; n++) { inputNameErdosNum[n] = 0; }

		//���ν��ѹ� 1 �˻�
		for (int i = 0; i < P; i++) {
			if (thesisnum[i].Erodsnum == 1)
				searchErosNum1(inputName, thesisnum[i], N, inputNameErdosNum, 1);

		}

		if (EnterComplete(P) == false) { //��� ���������� ������ �ʾҴٸ�
										 //���ε����ѹ� 2�˻�
			int Erodosnum = 0;

			char* compareName = new char[40];
			ThesisNumName *compareTn = new ThesisNumName();

			//������������ 2�Ͱ��õ� ��ũ�帮��Ʈ ã��
			int maxErosnum = 0;
			while (Erodosnum++ < P) {
				for (int p = 0; p < P; p++) {
					if (thesisnum[p].Erodsnum == Erodosnum) //��������1�ξֵ�ã����
					{
						compareTn = thesisnum[p].Tn;

						while (compareTn) {
							compareName = new char[40];
							compareName = compareTn->name;//1�� �ش��ϴ� �ֵ���
							compareTn = compareTn->Tn;


							for (int i = 0; i < P; i++) {
								if (EnterComplete(P) == true) break;

								if (thesisnum[i].concerned == false) {//���� ����������� ���鿡 ���ؼ�
									if (searchErosNum2(thesisnum[i], compareName, Erodosnum + 1) == true)//2�ξֵ��̸�
									{
										searchErosNum1(inputName, thesisnum[i], N, inputNameErdosNum, Erodosnum + 1);//������ ��ũ��ҵ�� name��ҵ�� ���Ѵ�.
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
			//������ ���� �˻簡 �������� ��ȣ�� �Ű��������� �ֵ鿡���ؼ� infinity�ο�

		}
	}
	return 0;
}

