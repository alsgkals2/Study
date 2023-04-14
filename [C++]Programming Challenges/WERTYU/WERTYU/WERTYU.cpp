	// WERTYU.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
	//
	#include <string>
	#include <iostream>

	using namespace std;

	int main()
	{
		string* saveLeftAlpha = new string[128];
		saveLeftAlpha[92] = ']';
		saveLeftAlpha[']'] = '[';
		saveLeftAlpha['['] = 'P';
		saveLeftAlpha['P'] = 'O';
		saveLeftAlpha['O'] = 'I';
		saveLeftAlpha['I'] = 'U';
		saveLeftAlpha['U'] = 'Y';
		saveLeftAlpha['Y'] = 'T';
		saveLeftAlpha['T'] = 'R';
		saveLeftAlpha['R'] = 'E';
		saveLeftAlpha['E'] = 'W';
		saveLeftAlpha['W'] = 'Q';
		saveLeftAlpha[39] = 59;
		saveLeftAlpha[59] = 'L';
		saveLeftAlpha['L'] = 'K';
		saveLeftAlpha['K'] = 'J';
		saveLeftAlpha['J'] = 'H';
		saveLeftAlpha['H'] = 'G';
		saveLeftAlpha['G'] = 'F';
		saveLeftAlpha['F'] = 'D';
		saveLeftAlpha['D'] = 'S';
		saveLeftAlpha['S'] = 'A';
		saveLeftAlpha['/'] = '.';
		saveLeftAlpha['.'] = ',';
		saveLeftAlpha[','] = 'M';
		saveLeftAlpha['M'] = 'N';
		saveLeftAlpha['N'] = 'B';
		saveLeftAlpha['B'] = 'V';
		saveLeftAlpha['V'] = 'C';
		saveLeftAlpha['C'] = 'X';
		saveLeftAlpha['X'] = 'Z';
		saveLeftAlpha['='] = '-';
		saveLeftAlpha['-'] = '0';
		saveLeftAlpha['0'] = '9';
		saveLeftAlpha['9'] = '8';
		saveLeftAlpha['8'] = '7';
		saveLeftAlpha['7'] = '6';
		saveLeftAlpha['6'] = '5';
		saveLeftAlpha['5'] = '4';
		saveLeftAlpha['4'] = '3';
		saveLeftAlpha['3'] = '2';
		saveLeftAlpha['2'] = '1';
		saveLeftAlpha['1'] = '`';


		string inNoutput;
		string* output = new string[1000000];
		int inc = 0;
	
	
		while (cin.peek()!='\n') {
			getline(cin, inNoutput);

			for (int i = 0; i < inNoutput.size(); i++) {
				if (inNoutput.at(i) != ' ') {
					inNoutput.replace(i, 1, saveLeftAlpha[inNoutput.at(i)]);
				}
			}
			output[inc++] = inNoutput;

			inNoutput.clear();
		}
	
		for(int i=0; i<inc; i++)
		cout << output[i] << endl;


	
		return 0;
	}

