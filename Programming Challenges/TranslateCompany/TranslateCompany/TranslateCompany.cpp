// TranslateCompany.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void input(char* company, string& old_company, string &new_company) {
	int inc = -1;
	int swit = false;

	while (company[++inc]) {
		
		if (company[inc] == '"') {

			//int forseperInc = -1;

			//����ȸ���
			while (!swit && company[++inc] != '"') {
				old_company+= company[inc];
			}
			if (!swit && company[inc] == '"') {
				swit = true;
				continue;
			}
			
			//����ȸ���
			while (swit && company[++inc] != '"') {
				new_company += company[inc];
			}
		}
	}

}
void match(string& inputText, string* old_company, string* new_company, int companyNum) {
	//old_company�� ù��° �ܾ�� ��ġ�ϴ� ���ĺ��� ã����
	//��� �ܾ ��ġ�ϴ��� �˻��ϰ�
	//translate�Լ� ����

	int fortextinc = -1;
	int forcompanyInc = -1;
	bool forSameJudge = true;
	int ReplaceNum = 0;
	int limitedSize = 0;
	int inputSize = inputText.size();

	for (int fortextinc = 0; fortextinc < inputSize; fortextinc++)
	{
		while (++forcompanyInc != companyNum)
		{
			if (inputText.at(fortextinc) == old_company[forcompanyInc].at(0)) {//ù��° �ܾ�� ��ġ�ϴ� ���ĺ��� ������

				limitedSize = old_company[forcompanyInc].size();
				for (ReplaceNum = 0; ReplaceNum < limitedSize && fortextinc + ReplaceNum < inputSize; ReplaceNum++) {
					//�ϳ��� �ٸ���
					if (old_company[forcompanyInc].at(ReplaceNum) != inputText.at(fortextinc + ReplaceNum)) {
						forSameJudge = false;
						break;
					}
				}

				if (forSameJudge)//��� ��ġ�ϸ�
				{
					inputText.replace(fortextinc, ReplaceNum, new_company[forcompanyInc]);
					fortextinc += new_company[forcompanyInc].length() - 1;//������ġ ����
				}
				forSameJudge = true;
				break;
			}
		}
		forcompanyInc = -1;
	}
}

int main()
{

	int i = 0;
	int companyNum = 0;

	cin >> companyNum;
	char** company = new char*[companyNum];
	string* old_company = new string[companyNum];
	string* new_company = new string[companyNum];

	int lineNum = 0;


	cin.ignore();
	for (i = 0; i < companyNum; i++) {
		company[i] = new char[1000];
		///ȸ��� �Է�
		cin.getline(company[i], 1000);

		input(company[i], old_company[i], new_company[i]);//�ֵ���ǥ ���� ȸ��� ���� ����

	}

	cin >> lineNum;
	cin.ignore();
	
	string* inputText = new string[lineNum];
	for (i = 0; i < lineNum; i++) {
		//inputText[i] = "";
		
		//�ؽ�Ʈ �Է�
		getline(cin,inputText[i]);

		//��ġ
		match(inputText[i],old_company,new_company,companyNum);
		
	}

	for (i = 0; i < lineNum; i++) {
	
		cout << inputText[i] << endl;
	}

			
	



	    return 0;
}

