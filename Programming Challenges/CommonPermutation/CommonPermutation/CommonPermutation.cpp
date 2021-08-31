
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int MaxSizeChecking(string* saveCharacter) {

	int inc = -1;
	int returnSize = 0;
	int compareSize = 0;
	while (saveCharacter[++inc].size() > 0) {
		compareSize = saveCharacter[inc].size();
		if (compareSize > returnSize) {
			returnSize = compareSize;
		}
	}

	return compareSize;
}
void SortAlpha(string* savecharacter, string &output) {
	int inc = -1;
	int outputinc = 0;

	while (savecharacter[++inc].size() > 0) {

		//if (savecharacter[inc].size() == size) {
		output += savecharacter[inc];
		//}
	}

	int forDec = 0;
	char forTemp;

	//삽입정렬 실행
	for (int i = 1; i < output.size(); i++) {
		forDec = i;
		while (forDec-- != 0) {

			if (output.at(forDec + 1) < output.at(forDec)) { //뒤에요소가 앞에요소 알파벳보다 더 우선순위가 높으면

				forTemp = output[forDec + 1];
				output[forDec + 1] = output[forDec];
				output[forDec] = forTemp;

			}

		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	string input_a;
	string input_b;
	string temp_input;
	string* saveCharacter;
	bool saveCount[26];
	int maximumSize;
	string* output = new string[1001];
	int foroutput = -1;

	while (1) {
		++foroutput;

		for (int i = 0; i < 26; i++)saveCount[i] = true;
		int forOutputinc = 0;
		getline(cin, input_a);
		getline(cin, input_b);
		if (input_a == "" && input_b == "") break;


		saveCharacter = new string[1000];
		int forSCInc = 0;
		if (input_a.size() < input_b.size()) {
			temp_input = input_b;
			input_b = input_a;
			input_a = temp_input;
		}

		//input_b가 minisize
		//input_a가 maxisize
		for (int i = 0; i < input_b.size(); i++) {

			if (input_a.find(input_b.at(i)) != -1) {
				for (int j = input_a.find(input_b.at(i)); j < input_a.size(); j++, i++) {

					if (input_a[j] == input_b[i]) saveCharacter[0] += input_b[i];//알파벳일치하는요소부터 연속된문자열 검사

					else {
						break;
					}

				}
				i = i - 1;
				//forSCInc++;
			}

		}

		SortAlpha(saveCharacter, output[foroutput]);
	}
	int inc = -1;
	while (++inc != foroutput + 1)cout << output[inc] << endl;

	return 0;
}

