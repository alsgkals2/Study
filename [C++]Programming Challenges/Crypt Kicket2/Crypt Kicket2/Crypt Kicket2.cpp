// Crypt Kicket2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <string>
using namespace std;
const string CONTACT = "the quick brown fox jumps over the lazy dog";
const int CONSTACT_SIZE = CONTACT.size();

bool AtoZCehcking(string input,char* saveAlpha){//,int inputsize) {
	int i = 0;
	char* forReturnSaveAlpha = new char[27];

	for ( i = 0; i < 26; i++)forReturnSaveAlpha[i] = NULL;//초기화

	for ( i = 0; i < CONSTACT_SIZE; i++)
	{
		if (CONTACT[i] == ' ')continue;

		if (forReturnSaveAlpha[input[i] - 97] == CONTACT[i]) continue; //이미 저장된값이 있는데 그값이 갱신하려는값과 같으면 건너뜀
		else if(forReturnSaveAlpha[input[i]-97] == NULL)//아직 저장하지 않은상태이면 저장
			forReturnSaveAlpha[input[i] - 97] = CONTACT[i];
		else //저장은되있는데 값이 저장된값과 다른경우
		{
			return false;
		}
	}

	for ( i = 0; i <26; i++) {
		saveAlpha[i] = forReturnSaveAlpha[i];
	}
	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	string* input = new string[101];
	char* saveAlpha = new char[27];//a = a-97
	int inc = 0;
	int i = 0;
	
	//	for (i = 0; i < 26; i++)  saveAlpha[i] = NULL;
		inc = 0;


		while (scanf("%s", input[inc]) != '\n'//cin.peek() != '\n') {
			
			scanf("%s", input[inc++]);
			//getline(cin, input[inc++]);
		}

		bool forChecking = false;
		int inputsize = 0;
		
		for ( i = 0; i < inc; i++) {
	//		inputsize = input[i].size();
		//	if (inputsize == CONSTACT_SIZE) {//길이검사
			//	if (SpotChecking(input[i])) {//위치일치검사
				if (AtoZCehcking(input[i], saveAlpha)){//,inputsize)) {

					for (i = 0; i < inc; i++) {
						for (int j = 0; j < input[i].size(); j++) {
							if (input[i][j] != ' ') {
								printf("%c", saveAlpha[input[i][j] - 97]); //cout << saveAlpha[input[i][j] - 97];
							}
							else {
								printf(" "); continue;// cout << ' '; continue;
							}
						}
						cout << '\n';
					}
					break;
				}
				else if(i==inc-1){
					cout << "No solution." << '\n'; break;
				}
		//	}
		//	else if(i == inc - 1) {
		//		cout << "No solution." << '\n'; break;
		//	}
		}


		return 0;
}

