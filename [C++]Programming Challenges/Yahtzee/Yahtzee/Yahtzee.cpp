// Yahtzee.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	int forCompare = -1; //���ҿ��

						 //����(13��)Ž��
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
void EnterSeven(int** category, int** numOfInput, bool** check1to6, int& categoryEleInc, int inc, int bcElement, int bcEValue)//7~13ī�װ�
{
	//ī�װ� ������ 0�ξֵ� ������� 
	//��������(2����)�� �̿��ؼ� 
	//7~12ī�װ� (6�̸���������) �ؼ� ī�װ����� ����
	//�����ֵ��߿� �ش��ϴ°� �ϳ��� ������ ī�װ����� ��������

	//////////
	int copyBaseCategory[13];
	int saveNum = 0;

	copy(category[categoryEleInc], category[categoryEleInc] + 13, copyBaseCategory);


	if (inc < 7) {//bcEValue != 0 : ���� ��������� �迭�� ������ �������� �ִ´�.
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
			inc++; //numofinput�� ��� 0�̿��� for���� �������� ���ϴ� ���
			EnterSeven(category, numOfInput, check1to6, categoryEleInc, inc, 0, 0);
		}
	}
}


void Enter5to6(int** category, bool** check1to6, int i, int& categoryEleInc, int** element56) {



	//5�� ī�װ�

	i = i - 1;
	int eleInc = 0;
	int Inc = 1;

	for (int j = 0; j < 13; j++) {
		if (category[categoryEleInc][j] == 0) {
			if (element56[i - 4][eleInc] != 0) {
				if (check1to6[element56[i - 4][eleInc]][i])
				{
					category[categoryEleInc][element56[i - 4][eleInc]] = i + 1;//����� 5~6 ī�װ� ���� ����
				}
			}

			if (i == 4) {
				Enter5to6(category, check1to6, 6, categoryEleInc, element56);
			}


			else if (i == 5) {
				EnterSeven(category, numOfInput, check1to6, categoryEleInc, Inc, 0, 0);//6���� ������ ������

				//categoryEleInc++;
			}
			if (element56[i - 4][eleInc++] == 0) break;
		}
	}
}


void EnterSix(int* data, bool* check1to6) {//1~6ī�װ�
										   //�������� 5��
	for (int i = 0; i < 6; i++) {
		if (data[i] == 5) {
			check1to6[0] = true;
			break;
		}
		//���� ���� �װ�
		else if (data[i] == 4) {
			check1to6[4] = true; break;
		}

	}

	for (int i = 0; i < 6; i++) {
		if (data[i] == 3)
		{
			for (int j = 0; j < 6; j++) {
				//Ǯ�Ͽ콺
				if (data[j] == 2) {
					check1to6[1] = true;
					break;
				}
			}
			check1to6[5] = true;//�������� ����
		}
	}

	//�ս�Ʈ����Ʈ
	if (data[0] != 0 && data[1] != 0 && data[2] != 0 && data[3] != 0 && data[4] != 0)
	{
		check1to6[2] = true;
	}
	else if (data[1] != 0 && data[2] != 0 && data[3] != 0 && data[4] != 0 && data[5] != 0)
	{
		check1to6[2] = true;
	}
	//��Ʈ ��Ʈ����Ʈ
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

	sum = (numOfInput[i][0] * 1) + (numOfInput[i][1] * 2) + (numOfInput[i][2] * 3) + (numOfInput[i][3] * 4) + (numOfInput[i][4] * 5) + (numOfInput[i][5] * 6);//����X�ֻ�������
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

			for (int j = 0; j < 13; j++) {//�����ʱ�ȭ
				check1to6[i][j] = false;
				numOfInput[i][j] = 0;
			}


			//�Է¹����� ���ÿ� ��������, 1~6���� üŷ,�� ����
			for (int a = 0; a < 5; a++) {
				cin >> input;
				enterInput(input, i);
			}
			EnterSix(numOfInput[i], check1to6[i]);
			sum[i] = Sum(i);
		}

		//1~4���� ������ �ߺ��Ǵ� ��Ұ� ������ sum�� �����ַ� ����

		saveJ = 0;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 13; j++) {
				if (check1to6[j][i] && category[j] == 0)
				{
					saveJ = j;

					for (int a = j + 1; a < 13; a++) {
						if (check1to6[a][i]) {//�ߺ���� �˻�
							if (sum[a] < sum[saveJ]) {
								check1to6[saveJ][i] = false;//ū�� FALSE
								saveJ = a;
							}
						}
					}
					category[saveJ] = i + 1;//����� 1~6 ī�װ� ���� ����
					break;
				}
			}

		//����Ǽ� ����
		fsInc = 0;

		categoryList = new int*[10000];

		//�ʱ�ȭ

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

