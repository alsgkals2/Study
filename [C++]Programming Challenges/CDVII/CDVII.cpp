// CDVII.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//시간대로정렬
int Partition(int left, int right, int* time, string* ID) {
	int first = left;
	int pivot = time[first];
	int tempI = 0;
	string tempS;
	++left;

	while (left <= right) {
		
		while (time[left] <= pivot && left < right) ++left;
		while (time[right] > pivot && left <= right) --right;

		if (left < right) {
			tempI = time[left];
			time[left] = time[right];
			time[right] = tempI;

			tempS = ID[left];
			ID[left] = ID[right];
			ID[right] = tempS;
		}

		else break;
	}
	tempI = time[first];
	time[first] = time[right];
	time[right] = tempI;

	tempS = ID[first];
	ID[first] = ID[right];
	ID[right] = tempS;

	return right;
}
void QuickSort(int left, int right, int* time, string* ID) {
	int index = 0;

	if (left < right) {
		index = Partition(left, right, time,ID);

		QuickSort(left, index - 1, time,ID);
		QuickSort(index + 1, right, time,ID);
	}
}

//id정렬
int Partition(int left, int right, string* ID) {
	int first = left;
	int pivot = ID[first][0];
	left++;
	bool forStopWhile = true;

	while (left <= right) {
		forStopWhile = true;

		while (ID[left][0] <= pivot && left < right && forStopWhile) {
			if(ID[left][0] != pivot)
				left++;
			else//같은경우
			{
				if (ID[left].compare(ID[first]) != 0)  //문자가 모두 일치하지 않으면
				{
					int leftSize = ID[left].size();
					int firstSize = ID[first].size();
					int comSmallSize = leftSize < firstSize ? leftSize : firstSize;
					bool ifSame = true;
					forStopWhile = true;
					for (int c = 1; c < comSmallSize; c++) {
		
						if (ID[left][c] < ID[first][c]) {
							left++; ifSame = false; break;
						}
						else if (ID[left][c] > ID[first][c]) {
							forStopWhile = false;
							ifSame = false;
							break;
						}
					
					}

					if (ifSame)//작은 길이만큼 모든문자열이 일치하는경우 ex)AA, AAA
					{
						if (leftSize < firstSize) left++;
						else forStopWhile = false;
					}
				}
				else //문자가 모두 일치하면
					left++;
			}
		}
		forStopWhile = true;

		while (ID[right][0] >= pivot && left <= right&&forStopWhile) {
			if (ID[left][0] != pivot)
				right--;
			else//같은경우
			{
				if (ID[right].compare(ID[first]) != 0)  //문자가 모두 일치하지 않으면
				{
					int rightSize = ID[right].size();
					int firstSize = ID[first].size();
					int comSmallSize = rightSize < firstSize ? rightSize : firstSize;
					bool ifSame = true;
					forStopWhile = true;
					for (int c = 1; c < comSmallSize; c++) {

						if (ID[right][c] > ID[first][c]) {
							right--; ifSame = false; break;
						}
						else if (ID[right][c] < ID[first][c]) {
							ifSame = false;
							forStopWhile = false;
							break;
						}

					}

					if (ifSame)//작은 길이만큼 모든문자열이 일치하는경우 ex)AA, AAA
					{
						if (rightSize > firstSize) right--;
						else forStopWhile = false;
					}
				}
				else //문자가 모두 일치하면
					break;
			}
		
		}
	
		if (left < right) {
			string temp = ID[left];
			ID[left] = ID[right];
			ID[right] = temp;
		}
		else break;
	}
	string temp = ID[right];
	ID[right] = ID[first];
	ID[first] = temp;

	return right;

}
void QuickSort(int left, int right, string* ID) {
	int index = 0;

	if (left < right) {
		index = Partition(left, right, ID);

		QuickSort(left, index - 1, ID);
		QuickSort(index + 1, right, ID);
	}
}


bool checkingPair(int com1,int com2,string& sortedInputLine1,string &sortedInputLine2) {
	int inc1 = com1 - 12;
	int inc2 = com2 - 12;

	for (int i = 0; i < 11; i++) {
		if (sortedInputLine1[inc1+i] != sortedInputLine2[inc2+i]) return false;
	}
	
	return true;//모두일치하면
}

int* saveTimeCharge = new int[24];
string* saveID;

int searchTimeCharge(int index, int saveidNum, string* sortedinputLine) {
	bool swit = false;
	bool exist = false;//짝이 존재하는여부
	int enterDistance = 0;
	int exitDistance = 0;
	int saveChargeIndex = -1;
	int returnCharge = 0;

	for (int i = index; i < saveidNum; i++) { //하나의 아이디구간
		if (sortedinputLine[i][0] == '.') continue;



		if (!swit)//enter
		{
			int inc = sortedinputLine[i].find(":");
			//첫 :의 인덱스

			string hh;
			hh += sortedinputLine[i][inc + 4];
			hh += sortedinputLine[i][inc + 5];

			saveChargeIndex = stoi(hh);//enter시간의 요금

			int size = sortedinputLine[i].size();

			string e;
			int dec = size - 1;
			if (sortedinputLine[i][dec] != ' ') --dec;//마지막 숫자를 저장하기위해

			for (int forDT = dec; forDT < size; forDT++) {
				e += sortedinputLine[i][forDT];
			}
			
			enterDistance = stoi(e);
			swit = true;
		}
		else {//exit
			int size = sortedinputLine[i].size();

			string e;
			int dec = size-1;
			if (sortedinputLine[i][dec] != ' ') --dec;//마지막 숫자를 저장하기위해

			for (int forDT = dec; forDT < size; forDT++) {
				e += sortedinputLine[i][forDT];
			}

			exitDistance = stoi(e);

			returnCharge += saveTimeCharge[saveChargeIndex] * abs(enterDistance - exitDistance);
			returnCharge += 100; //매 주행마다 1달러의 요금이 붙으므로

			swit = false;
			exist = true;
		}

	}
	if(exist)returnCharge += 200;//매달 2달러의 기본요금
	else {
		return -1;
	}
	return returnCharge;

}



void searchCouple(int *saveIdNum, string* sortedinputLine) {
	int inc = 0;
	int index = 0;

	while (saveIdNum[inc] != 0) {
		for (int i = index; i < saveIdNum[inc];) {
			if (i + 1 < saveIdNum[inc]) {
				int i_enter = sortedinputLine[i].find("enter");
				int i1_exit = sortedinputLine[i + 1].find("exit");
				//int i1_enter = sortedinputLine[i + 1].find("enter");
				//int i_exit = sortedinputLine[i].find("exit");

				if (i_enter != -1 && i1_exit != -1)
				{
					//두개의 시간기록이 일치하면
					if (checkingPair(i_enter, i1_exit,sortedinputLine[i],sortedinputLine[i+1])) {
						sortedinputLine[i][0] = '.';
						sortedinputLine[i+1][0] = '.';
					}

					i += 2;
				}
				/*else if(i1_enter != -1 && i_exit != -1)
				{
					if (checkingPair(i1_enter, i_exit, sortedinputLine[i], sortedinputLine[i + 1])) {
						sortedinputLine[i][0] = '.';
						sortedinputLine[i+1][0] = '.';
						
					}
					else {
						//enter먼저 앞으로 나오기위해 순서교환
						string temp = sortedinputLine[i + 1];
						sortedinputLine[i + 1] = sortedinputLine[i];
						sortedinputLine[i] = temp;
					}
					i += 2;
				}*/
				else
				{ sortedinputLine[i][0]='.'; i++; }//짝이맞지않는경우
			}
			else
			{ sortedinputLine[i][0]='.'; i++; }//짝이맞지않는경우
		
		}

		int charge = searchTimeCharge(index, saveIdNum[inc],sortedinputLine);
		if(charge!=-1)//짝이 존재하면
			cout<<saveID[index]<<" $"<<charge/100 <<"."<<charge%100<<endl;

		index = saveIdNum[inc];
		inc++;
	}
}
void TrnasformTimeToInt(int *saveIDtime,int firstindex, int lastindex, string* input) {
	int forsearchindex = 0;
	string dd, hh, mm;
	for (int i = firstindex; i < lastindex; i++) {
		forsearchindex = input[i].find(":");
		dd += input[i][forsearchindex + 1];
		dd += input[i][forsearchindex + 2];
		hh += input[i][forsearchindex + 4];
		hh += input[i][forsearchindex + 5];
		mm += input[i][forsearchindex + 7];
		mm += input[i][forsearchindex + 8];
		saveIDtime[i] = (stoi(dd) * 24 * 60) + (stoi(hh) * 60) + (stoi(mm));
		dd.clear(); hh.clear(); mm.clear();
	}

}


const int maxLineNum = 1000;
int main()
{
	int TC = 0;
	string* inputLine = new string[maxLineNum];
	string* sortedinputLine = new string[maxLineNum];//아아디들 정렬해서 넣기위해
	int* saveIdNum = new int[maxLineNum];//각 아이디의 갯수저장
	for (int i = 0; i < maxLineNum; i++)saveIdNum[i] = 0;
	int iLCount = 0;
	saveID = new string[maxLineNum];
	string* origin_saveID = new string[maxLineNum];
	
	for (int i = 0; i < 24; i++) cin >> saveTimeCharge[i];
	
	cin.ignore();
	while (1) {
		getline(cin,inputLine[iLCount]);
		
		if (inputLine[iLCount][0] != '\0') {
			
			for (int i = 0; inputLine[iLCount][i] != ' '; i++) {
				saveID[iLCount] += inputLine[iLCount][i];
			}
			origin_saveID[iLCount] = saveID[iLCount];
			
			iLCount++;
		}

		else break;
	}
	
	QuickSort(0, iLCount - 1, saveID);//아이디들 정렬
	
	int searchIndex = 0;
	int sameNum = 1;
	int forstopNum = 0;
	int saveIDNumIndex = 0;
	int* saveIDtime;
	//sortedinputline에아이디 정렬순으로 넣기
	for (int IDindex = 1; IDindex < iLCount+1;) {
		if (saveID[searchIndex].compare(saveID[IDindex]) == 0) {
			sameNum++;//아이디 총갯수
			IDindex++;
		}
		else if (saveID[searchIndex].compare(saveID[IDindex]) != 0) {

			//아이디 갯수저장
			saveIdNum[saveIDNumIndex++] = sameNum;

			int saveforstopNum = forstopNum;//정렬을 위한 인덱스저장

			for (int inc = 0; inc < iLCount && forstopNum!=sameNum; inc++) {//아이디를 모두 찾았으면 종료하는조건 추가.
				if (origin_saveID[inc].compare(saveID[searchIndex])==0) {
					sortedinputLine[forstopNum] = inputLine[inc];//아이디 정렬된순으로 inputline에 삽입
					
					forstopNum++;//아이디 총갯수와 일치하면 멈추기위한 변수
				}
			
			}
			saveIDtime = new int[sameNum - saveforstopNum];
			TrnasformTimeToInt(saveIDtime, saveforstopNum, sameNum, sortedinputLine);
			QuickSort(saveforstopNum, sameNum - 1, saveIDtime, sortedinputLine);

			searchIndex = IDindex;
		}
	}

	searchCouple(saveIdNum, sortedinputLine);

	

	return 0;
}