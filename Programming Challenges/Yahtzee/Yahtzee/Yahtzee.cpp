// Yahtzee.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
using namespace std;

int *sum = new int[13];
int** numOfInput = new int*[13];

void enterInput(int inputNum, int i)
{
	numOfInput[i][inputNum - 1]++;

}

void chance(int* category) {
	bool swit = false;
	int forCompare = -1; //비교할요소

						 //찬스(13번)탐색
	for (int i = 0; i < 13; i++) {
		if (category[i] == 0) {
			if (!swit) {
				forCompare = i;
				swit = true;
			}
			else if (sum[forCompare] < sum[i]) {
				forCompare = i;
			}
		}
	}
	category[forCompare] = 13;
}

bool forEnterSeven = false;
bool forInc = false;
bool firstCome = false;
void EnterSeven(int** category, int** numOfInput, bool** check1to6, int& categoryEleInc, int inc, int bcElement, int bcEValue)//7~13카테고리
{
	//카테고리 정보가 0인애들 대상으로 
	//갯수정보(2차원)을 이용해서 
	//7~12카테고리 (6이많은순부터) 해서 카테고리정보 수정
	//남은애들중에 해당하는게 하나도 없으면 카테고리정보 수정안함

	//////////
	int copyBaseCategory[13];
	int saveNum = 0;

	copy(category[categoryEleInc], category[categoryEleInc] + 13, copyBaseCategory);


	if (inc < 7) {//bcEValue != 0 : 값이 들어있으면 배열에 이전의 값정보를 넣는다.
		forInc = false;
		//saveNum = 0;

		for (int i = -1; i < 12;) {
			if (categoryEleInc == 10000) break;
			i++;

			if (!forEnterSeven) {
				for (int j = 0; j < 13; j++) {
					category[categoryEleInc][j] = copyBaseCategory[j];
				}
			}

			if (inc != 7 && category[categoryEleInc][i] == 0) {
				
				//if (numOfInput[i][6 - inc] != saveNum) {
					if (numOfInput[i][6 - inc] != 0) {
					saveNum = numOfInput[i][6 - inc];

					category[categoryEleInc][i] = 6 + inc;

					forInc = true;
					forEnterSeven = true;


					if (inc == 6) {
						chance(category[categoryEleInc]);
						forEnterSeven = false;
						categoryEleInc++;

						if (categoryEleInc == 10000)
						{ break; }
						continue;
					}

					else {
						EnterSeven(category, numOfInput, check1to6, categoryEleInc, inc + 1, i, 5 + inc + 1);
					}
				}
			}
		}

		if (inc < 6 && !forInc) {
			inc++; //numofinput이 모두 0이여서 for문에 진입하지 못하는 경우
			EnterSeven(category, numOfInput, check1to6, categoryEleInc, inc, 0, 0);
		}
	}
}


void Enter5to6(int** category, bool** check1to6, int i, int& categoryEleInc, int** element56) {



	//5번 카테고리

	i = i - 1;
	int eleInc = 0;
	int Inc = 1;

	for (int j = 0; j < 13; j++) {
		if (category[categoryEleInc][j] == 0) {
			if (element56[i - 4][eleInc] != 0) {
				if (check1to6[element56[i - 4][eleInc]][i])
				{
					category[categoryEleInc][element56[i - 4][eleInc]] = i + 1;//요소의 5~6 카테고리 정보 저장
				}
			}

			if (i == 4) {
				Enter5to6(category, check1to6, 6, categoryEleInc, element56);
			}


			else if (i == 5) {
				EnterSeven(category, numOfInput, check1to6, categoryEleInc, Inc, 0, 0);//6까지 저장이 됐으면

				//categoryEleInc++;
			}
			if (element56[i - 4][eleInc++] == 0) break;
		}
	}
}


void EnterSix(int* data, bool* check1to6) {//1~6카테고리
										   //같은숫자 5개
	for (int i = 0; i < 6; i++) {
		if (data[i] == 5) {
			check1to6[0] = true;
			break;
		}
		//같은 숫자 네개
		else if (data[i] == 4) {
			check1to6[4] = true; break;
		}

	}

	for (int i = 0; i < 6; i++) {
		if (data[i] == 3)
		{
			for (int j = 0; j < 6; j++) {
				//풀하우스
				if (data[j] == 2) {
					check1to6[1] = true;
					break;
				}
			}
			check1to6[5] = true;//같은숫자 세개
		}
	}

	//롱스트레이트
	if (data[0] != 0 && data[1] != 0 && data[2] != 0 && data[3] != 0 && data[4] != 0)
	{
		check1to6[2] = true;
	}
	else if (data[1] != 0 && data[2] != 0 && data[3] != 0 && data[4] != 0 && data[5] != 0)
	{
		check1to6[2] = true;
	}
	//쇼트 스트레이트
	if (data[0] != 0 && data[1] != 0 && data[2] != 0 && data[3] != 0) {
		check1to6[3] = true;
	}
	else if (data[1] != 0 && data[2] != 0 && data[3] != 0 && data[4] != 0) {
		check1to6[3] = true;
	}
	else if (data[2] != 0 && data[3] != 0 && data[4] != 0 && data[5] != 0) {
		check1to6[3] = true;
	}

}

int Sum(int i) {
	int sum = 0;

	sum = (numOfInput[i][0] * 1) + (numOfInput[i][1] * 2) + (numOfInput[i][2] * 3) + (numOfInput[i][3] * 4) + (numOfInput[i][4] * 5) + (numOfInput[i][5] * 6);//갯수X주사위숫자
	return sum;
}


void seperatedScore(int* category, int* resultOutput, int & sum7to12) {
	int exceptedSum = 0;
	sum7to12 = 0;

	for (int i = 0; i < 13; i++) {
		if (category[i] == 1) {
			resultOutput[9] = 50;
		}
		else if (category[i] == 2) {
			resultOutput[12] = 40;
		}
		else if (category[i] == 3) {
			resultOutput[11] = 35;
		}
		else if (category[i] == 4) {
			resultOutput[10] = 25;
		}
		else if (category[i] == 5) {
			resultOutput[8] = sum[i];
		}
		else if (category[i] == 6) {
			resultOutput[7] = sum[i];
		}
		else if (category[i] == 7) {
			sum7to12 += resultOutput[5] = numOfInput[i][5] * 6;
		}
		else if (category[i] == 8)
		{
			sum7to12 += resultOutput[4] = numOfInput[i][4] * 5;
		}
		else if (category[i] == 9)
		{
			sum7to12 += resultOutput[3] = numOfInput[i][3] * 4;
		}
		else if (category[i] == 10)
		{
			sum7to12 += resultOutput[2] = numOfInput[i][2] * 3;
		}
		else if (category[i] == 11)
		{
			sum7to12 += resultOutput[1] = numOfInput[i][1] * 2;
		}
		else if (category[i] == 12)
		{
			sum7to12 += resultOutput[0] = numOfInput[i][0];
		}
		else if (category[i] == 13) {
			resultOutput[6] = sum[i];
		}
	}
}
int AllSum(int* category) {
	int sum7to12 = 0;
	int exceptedSum = 0;
	for (int i = 0; i < 13; i++) {
		if (category[i] == 1) {
			exceptedSum += 50;
		}
		else if (category[i] == 2) {
			exceptedSum += 40;
		}
		else if (category[i] == 3) {
			exceptedSum += 35;
		}
		else if (category[i] == 4) {
			exceptedSum += 25;
		}
		else if (category[i] == 5) {
			exceptedSum += sum[i];
		}
		else if (category[i] == 6) {
			exceptedSum += sum[i];
		}
		else if (category[i] == 7) {
			sum7to12 += numOfInput[i][5] * 6;
		}
		else if (category[i] == 8)
		{
			sum7to12 += numOfInput[i][4] * 5;
		}
		else if (category[i] == 9)
		{
			sum7to12 += numOfInput[i][3] * 4;
		}
		else if (category[i] == 10)
		{
			sum7to12 += numOfInput[i][2] * 3;
		}
		else if (category[i] == 11)
		{
			sum7to12 += numOfInput[i][1] * 2;
		}
		else if (category[i] == 12)
		{
			sum7to12 += numOfInput[i][0];
		}
		else if (category[i] == 13) {
			exceptedSum += sum[i];
		}
	}
	int addScore = 0;
	if (sum7to12 >= 63) addScore = 35;

	return sum7to12 + exceptedSum + addScore;
}
int main()
{


	int input = 0;

	bool** check1to6 = new bool*[13];
	int* category = new int[13];
	int saveJ;
	int fsInc = 0;

	int** categoryList = new int*[60000];
	int categoryEleInc = 0;
	int** element56 = new int*[2]; int e5Inc = 0; int e6Inc = 0;
	int* TEST_SUMLIST;
	int resultsumEle = 0;

	int* resultoutput;
	int sum7to12;


	while (1) {
		for (int i = 0; i < 13; i++) {

			check1to6[i] = new bool[13];
			numOfInput[i] = new int[13];
			sum[i] = 0;
			category[i] = 0;

			for (int j = 0; j < 13; j++) {//변수초기화
				check1to6[i][j] = false;
				numOfInput[i][j] = 0;
			}


			//입력받음과 동시에 갯수저장, 1~6여부 체킹,합 저장
			for (int a = 0; a < 5; a++) {
				cin >> input;
				enterInput(input, i);
			}
			EnterSix(numOfInput[i], check1to6[i]);
			sum[i] = Sum(i);
		}

		//1~4까지 정보중 중복되는 요소가 있으면 sum이 낮은애로 선택

		saveJ = 0;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 13; j++) {
				if (check1to6[j][i] && category[j] == 0)
				{
					saveJ = j;

					for (int a = j + 1; a < 13; a++) {
						if (check1to6[a][i]) {//중복요소 검사
							if (sum[a] < sum[saveJ]) {
								check1to6[saveJ][i] = false;//큰값 FALSE
								saveJ = a;
							}
						}
					}
					category[saveJ] = i + 1;//요소의 1~6 카테고리 정보 저장
					break;
				}
			}

		//경우의수 조사
		fsInc = 0;

		categoryList = new int*[10000];

		//초기화

		for (int i = 0; i < 10000; i++) {
			categoryList[i] = new int[13];
			for (int j = 0; j < 13; j++)
				categoryList[i][j] = category[j];
		}

		categoryEleInc = 0;
		e5Inc = 0;  e6Inc = 0;
		element56[0] = new int[13];
		element56[1] = new int[13];

		for (int i = 0; i < 13; i++) {
			element56[0][i] = 0;
			element56[1][i] = 0;
		}
		for (int i = 0; i < 13; i++) {
			if (check1to6[i][4] == true) {
				element56[0][e5Inc++] = i;
			}
			if (check1to6[i][5] == true) {
				element56[1][e6Inc++] = i;
			}
		}
		Enter5to6(categoryList, check1to6, 5, categoryEleInc, element56);

		int sumMaximumEle = 0;

		for (int i = 1; i < categoryEleInc; i++) {
			if (AllSum(categoryList[sumMaximumEle]) < AllSum(categoryList[i])) sumMaximumEle = i;
		}

		resultoutput = new int[14];
		sum7to12 = 0;

		for (int i = 0; i < 14; i++) { resultoutput[i] = 0; }

		seperatedScore(categoryList[sumMaximumEle], resultoutput, sum7to12);

		resultoutput[13] = sum7to12 >= 63 ? 35 : 0;
//		if (sum7to12 >= 63) resultoutput[13] = 35; else resultoutput[13] = 0;

		for (int i = 0; i < 14; i++) {
			cout << resultoutput[i] << " ";
		}
		cout << AllSum(categoryList[sumMaximumEle]) << endl;


	}


	return 0;
}

