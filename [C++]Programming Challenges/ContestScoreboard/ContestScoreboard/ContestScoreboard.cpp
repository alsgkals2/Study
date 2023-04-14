// ContestScoreboard.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <iostream>


using namespace std;

struct inform {
//	int timePanalty = 0;
	bool correctJudge = false;
};
struct team {
	int teamNum = 0;
	inform* in;
};

int EnterCIRUE(char CIRUE) {
	if (CIRUE == 'C')//�����ΰ��
		return 1;
	else if (CIRUE == 'I')//�����ΰ��
		return 2;
	else return 0;
}

int main()
{

	int Tc = 0;
	cin >> Tc;
	cin.ignore();
	bool *teamExist;
	team* T;
	int*** output;
	char CIRUE = NULL;
	int enterCIRUE = 0;
	int teamNum = 0, problemNum = 0, timePanalty = 0;
	int* incT=new int[Tc];
	int** teamNumList = new int*[Tc];
	for (int i = 0; i < Tc; i++) {
		teamNumList[i] = new int[100];
	}
	
	int forOutput = -1;

	output = new int**[Tc];//1���� ����ȣ, 2���� ���᰹��, 3���� ��Ÿ���г�Ƽ
	for (int i = 0; i < Tc; i++) {
		output[i] = new int*[100];
	}


	while (forOutput++ != Tc-1) {
		cin.ignore();

		//���������θ� �˱����� ���� ����
		teamExist = new bool[100];

		//�������� 9�������� inform����
		T = new team[100]; incT[forOutput] = 0;


		while (cin.peek() != '\n') {

			cin >> teamNum >> problemNum >> timePanalty >> CIRUE;
			enterCIRUE = EnterCIRUE(CIRUE);
			if (enterCIRUE != 0) {//CIRUE���� C�ų� I�ΰ��

				if (teamExist[teamNum - 1])//���� �������� ������
				{
					teamNumList[forOutput][incT[forOutput]++] = teamNum;

					T[teamNum-1].in = new inform[9];
					T[teamNum-1].teamNum = teamNum;

					output[forOutput][teamNum-1] = new int[3]; //��¹迭 �ʰ�ȭ
					for (int forout = 0; forout < 3; forout++)
						output[forOutput][teamNum-1][forout] = 0;

					output[forOutput][teamNum-1][0] = teamNum;

					if (enterCIRUE == 1) {//correct
						T[teamNum-1].in[problemNum - 1].correctJudge = true;
						output[forOutput][teamNum-1][1]++;
						output[forOutput][teamNum-1][2] = timePanalty;
					}
					else {//INCORRECT
						output[forOutput][teamNum-1][2] = 20;
					}
					teamExist[teamNum - 1] = false;
				}
				else //�����ϸ�
				{

					inform* teamsProblemNum = &T[teamNum-1].in[problemNum - 1];

					if (!teamsProblemNum->correctJudge) {

						if (enterCIRUE == 1) {//correct
							teamsProblemNum->correctJudge = true;//�����̸� ���̻� ���������ʵ��� trueó��
							//teamsProblemNum->timePanalty = teamsProblemNum->timePanalty + timePanalty;
							output[forOutput][teamNum-1][1]++;
							output[forOutput][teamNum-1][2] += timePanalty;
					
						}
						else {//incorrect
							 output[forOutput][teamNum-1][2] += 20;
						}
					}

				}
			}

			cin.ignore();
		}
		delete teamExist;
		//delete[] T;
			//delete T[teamNum].in;
			delete T;
	}

		//�������� ����
	int *** test = output;
		int *temp = new int[3];
		int decrease = 0;

		for (int o = 0; o < forOutput; o++)
			for (int i = 0; i < incT[o]; i++) {
				for (int j = i - 1; j >= 0; j--) {
					if (output[o][teamNumList[o][j] - 1][1] < output[o][teamNumList[o][j + 1] - 1][1]) {
						temp = output[o][teamNumList[o][j] - 1];
						output[o][teamNumList[o][j] - 1] = output[o][teamNumList[o][j + 1] - 1];
						output[o][teamNumList[o][j + 1] - 1] = temp;
					}
					else if (output[o][teamNumList[o][j] - 1][1] == output[o][teamNumList[o][j + 1] - 1][1]) {
						if (output[o][teamNumList[o][j] - 1][2] > output[o][teamNumList[o][j + 1] - 1][2]) {
							temp = output[o][teamNumList[o][j] - 1];
							output[o][teamNumList[o][j] - 1] = output[o][teamNumList[o][j + 1] - 1];
							output[o][teamNumList[o][j + 1] - 1] = temp;
						}
					}
					else break;
				}
			}

		for (int o = 0; o < forOutput; o++) {
			for (int i = 0; i < incT[o]; i++) {
				cout << output[o][teamNumList[o][i]-1][0] << " " << output[o][teamNumList[o][i]-1][1] << " " << output[o][teamNumList[o][i]-1][2] << endl;
			}
			cout << endl;
		}

		
		/*for (int i = 0; i < incT; i++) {
			delete[] output[teamNumList[i]];
		}*/


	/*	int Tc = 0;
	cin >> Tc;
	cin.ignore();
	bool *teamExist;
	team* T;
	int** output;
	char CIRUE = NULL;
	int enterCIRUE = 0;
	int teamNum = 0, problemNum = 0, timePanalty = 0;
	int incT;
	int* teamNumList;*/



	return 0;
}

