// TranslateCompany.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

			//좌측회사명
			while (!swit && company[++inc] != '"') {
				old_company+= company[inc];
			}
			if (!swit && company[inc] == '"') {
				swit = true;
				continue;
			}
			
			//우측회사명
			while (swit && company[++inc] != '"') {
				new_company += company[inc];
			}
		}
	}

}
void match(string& inputText, string* old_company, string* new_company, int companyNum) {
	//old_company의 첫번째 단어와 일치하는 알파벳을 찾으면
	//모든 단어가 일치하는지 검사하고
	//translate함수 실행

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
			if (inputText.at(fortextinc) == old_company[forcompanyInc].at(0)) {//첫번째 단어와 일치하는 알파벳이 있으면

				limitedSize = old_company[forcompanyInc].size();
				for (ReplaceNum = 0; ReplaceNum < limitedSize && fortextinc + ReplaceNum < inputSize; ReplaceNum++) {
					//하나라도 다르면
					if (old_company[forcompanyInc].at(ReplaceNum) != inputText.at(fortextinc + ReplaceNum)) {
						forSameJudge = false;
						break;
					}
				}

				if (forSameJudge)//모두 일치하면
				{
					inputText.replace(fortextinc, ReplaceNum, new_company[forcompanyInc]);
					fortextinc += new_company[forcompanyInc].length() - 1;//시작위치 갱신
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
		///회사명 입력
		cin.getline(company[i], 1000);

		input(company[i], old_company[i], new_company[i]);//쌍따옴표 안의 회사명 각각 저장

	}

	cin >> lineNum;
	cin.ignore();
	
	string* inputText = new string[lineNum];
	for (i = 0; i < lineNum; i++) {
		//inputText[i] = "";
		
		//텍스트 입력
		getline(cin,inputText[i]);

		//메치
		match(inputText[i],old_company,new_company,companyNum);
		
	}

	for (i = 0; i < lineNum; i++) {
	
		cout << inputText[i] << endl;
	}

			
	



	    return 0;
}

