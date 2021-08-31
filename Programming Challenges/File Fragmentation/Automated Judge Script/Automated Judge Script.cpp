// Automated Judge Script.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int outputNum;

string CheckOverraping(string **input ) {
	
	string* forCheckingOr = new string[15000];
	int fck = 0;
	int judgeOr = 0;
	string saveOr;
	int checkingStartEle = 0;

	for (int i = 1; i < (outputNum / 2)+1; i++) {
		
		for (int j = 0; input[i][j][0]; j++) {
			int z = 0;
			while (input[outputNum - i][z][0]) {
				if (outputNum - i == i && j == z) break;
				forCheckingOr[fck++] = input[i][j] + input[outputNum - i][z];
				forCheckingOr[fck++] = input[outputNum - i][z] + input[i][j];
				z++;
			}
		}
	
		judgeOr = 0;
		for (int j = checkingStartEle; forCheckingOr[j][0]&&judgeOr!=2; j++) {
			for (int a = checkingStartEle; a < fck&&judgeOr!=2 ; a++) {
				if (a == j) continue;

				if (forCheckingOr[j].compare(forCheckingOr[a]) == 0)//�ߺ��Ǹ�(������)
				{
					if (!judgeOr) {
						judgeOr = 1;
						saveOr = forCheckingOr[j];
					}
					else {//�ߺ��Ȱ��� �ΰ��̻��̴�. �׷��� �״������� ��� �˾ƺ����Ѵ�.
						
						judgeOr = 2;
					}

				}
			}
			
		}

		if (judgeOr == 1) return saveOr;//�ߺ��Ȱ��� �Ѱ�.
		else {
			
			checkingStartEle = fck;
		}
	}

	//�ߺ��Ȱ��� ��� �� 2���̻� ���ͼ� for���� ��� ����°��
	int* saveORCount = new int[fck];
	for (int i = 0; i < fck; i++) saveORCount[i] = 0;
	
	int saveEle = saveORCount[0];
	string* copySaveOr = new string[fck];
	for (int i = 0; i < fck; i++) copySaveOr[i] = forCheckingOr[i];


	for (int j = 0; j < fck; j++) {
		for (int i =0; i < fck; i++) {
			if (i!=j &&copySaveOr[j].compare(copySaveOr[i]) == 0&& copySaveOr[i] != ".")//������
			{
				saveORCount[j]++;
				copySaveOr[i] = ".";
			}
		}
		copySaveOr[j] = ".";

		if (saveORCount[j] > saveORCount[saveEle]) {
			saveEle = j;
		}

	}


	//saveor�˻�
	return forCheckingOr[saveEle];

}

int main()
{
	string input;
	string** saveBreakedinform = new string*[289];


	int numCount = 0;
	int size = 0;
	int fordevice = 0;
	int inc = 0;

	int t = 0;
	cin >> t;
	cin.ignore(); cin.ignore();
	
	string* foroutput = new string[t];

	for(int t_inc=0; t_inc<t; t_inc++){
		numCount = 0;
		size = 0;
		fordevice = 0;
		inc = 0;
		for (int i = 0; i < 289; i++) {
			saveBreakedinform[i] = new string[145];
		}

		while (1) {

			getline(cin, input);
			if (input[0] == NULL) break;

			size = input.size();
			inc = -1;

			while (1) {
				if (saveBreakedinform[size][++inc][0] == NULL)
				{
					saveBreakedinform[size][inc] = input;
					break;
				}
			}
			numCount += size;
			fordevice++;

		}

		outputNum = (numCount) / (fordevice / 2); //��¹��ڰ���

		foroutput[t_inc] = CheckOverraping(saveBreakedinform);
			 
	}

	for (int i = 0; i < t; i++) {
		cout << foroutput[i] << endl << endl;
	}

	
    return 0;
}

