// From Dusk Till Dawn.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

typedef struct TrainInform {
	char arriveCity[33];
	int departTime;
	int arriveTime;
	int neededBlood = 0;
}Train;

typedef struct Graph {
	char cityName[100][33]; //�����̸�(32���� �̳�)
	Train TI[100][1000];//�� ���ÿ������ �뼱����
	int degree[100];//�� ������ �뼱����
	int beforSorted[100];
	int cityNum = 0;
}Graph;


int EnterOverlap(Graph* G, char* cityN,bool& facn) {
	int i = 0;
	while (G->cityName[i][0]) {
		if (!strcmp(G->cityName[i], cityN)) return i; //��ġ�ϸ�
		i++;
	}
	G->beforSorted[G->cityNum] = G->cityNum;
	G->cityNum++;
	facn = true;
	return i;
}

int Partition(Graph* G, int left, int right) {
	int t;

	int first = left;
	left++;

	while (left <= right) {
		while (left < right && strcmp(G->cityName[left], G->cityName[first]) <= 0) left++;
		while (left <= right && strcmp(G->cityName[right], G->cityName[first]) > 0) right--;

		if (left < right) {
			char temp[33];
			strcpy(temp, G->cityName[right]);
			strcpy(G->cityName[right], G->cityName[left]);
			strcpy(G->cityName[left], temp);

			t = G->beforSorted[right];
			G->beforSorted[right] = G->beforSorted[left];
			G->beforSorted[left] = t;
		}
		else break;
	}
	char temp[33];
	strcpy(temp,  G->cityName[right]);
	strcpy(G->cityName[right], G->cityName[first]);
	strcpy(G->cityName[first],temp);

	t = G->beforSorted[right];
	G->beforSorted[right] = G->beforSorted[first];
	G->beforSorted[first] = t;

	return right;

}

void QuickSort(Graph* G, int left, int right) {
	static int index;
	if (left < right) {
		index = Partition(G, left, right);
		QuickSort(G, left, index - 1);
		QuickSort(G, index+1, right);
	}
}


int BinarySearch(Graph* G,int left, int right,char* cityName) {

	int cmpValue;
	while (left <= right) {
		int middle = (left + right) / 2;
		cmpValue = strcmp(G->cityName[middle], cityName);
		if (cmpValue < 0)
			left = middle + 1;
		else if (cmpValue > 0)
			right = middle - 1;
		else//�������
			return middle;
	}
}



int cityList[100];
int neededBlood[100];
int queueNum[100];
int finalOutput = -1;

void init() {
	finalOutput = -1;

	for (int i = 0; i < 100; i++)
	{
		cityList[i] = -2;
		neededBlood[i] = 0;
		queueNum[i] = 0;
	}

}

void solve(Graph* G, char* sc, char* ec) {
	int i = 0;
	int sIndex;
	int eIndex;
	int finalIndex;
	int qnIndex = 0;
	int originIndex;
	int minATime[100];
	bool finished = true;



	QuickSort(G, 0, G->cityNum - 1);

	sIndex = BinarySearch(G, 0, G->cityNum - 1, sc);
	sIndex = G->beforSorted[sIndex];
	finalIndex = BinarySearch(G, 0, G->cityNum - 1, ec);
	finalIndex = G->beforSorted[finalIndex];

	for (int j = 0; j < G->degree[sIndex]; j++)
	{
		eIndex = BinarySearch(G, 0, G->cityNum - 1, G->TI[sIndex][j].arriveCity);
		eIndex = G->beforSorted[eIndex];

		if (cityList[eIndex] != qnIndex)//üũ������ ������
		{
			cityList[eIndex] = qnIndex;
			queueNum[qnIndex]++;
			minATime[eIndex] = G->TI[sIndex][j].arriveTime;
			finished = false;
		}
		else//�ߺ��Ǵ� ���
		{
			if (minATime[eIndex] > G->TI[sIndex][j].arriveTime)

				minATime[eIndex] = G->TI[sIndex][j].arriveTime;
		}
	}
	qnIndex++;

	while (!finished) {
		finished = true;

		while (queueNum[qnIndex - 1]-- != 0) {

			for (i = 0; i < G->cityNum; i++) {
				if (cityList[i] == qnIndex - 1) {
					cityList[i] = -1;

					for (int j = 0; j < G->degree[i]; j++)
					{
						eIndex = BinarySearch(G, 0, G->cityNum - 1, G->TI[i][j].arriveCity);
						eIndex = G->beforSorted[eIndex];
					
						//�������� �߰��Ѱ��
						if (eIndex == finalIndex && (finalOutput == -1 || neededBlood[i] < finalOutput))
						{
							if (minATime[i] < G->TI[i][j].departTime)
								finalOutput = neededBlood[i];
							else
							{
								finalOutput = neededBlood[i] + 1;
							}

							continue;
						}

						if (cityList[eIndex] != qnIndex && cityList[eIndex] != -1) {
							finished = false;

							cityList[eIndex] = qnIndex;
							queueNum[qnIndex]++;

							if (minATime[i] < G->TI[i][j].departTime)
							{
								neededBlood[eIndex] = neededBlood[i];
								minATime[eIndex] = G->TI[i][j].arriveTime;

							}
							else
							{
								neededBlood[eIndex] = neededBlood[i] + 1;
								minATime[eIndex] = G->TI[i][j].arriveTime;
							}
						}

						else//�ߺ��Ǵ� ���
						{

							//12�ð����� �ι��̻� ȯ�°����Ѱ��
							if (minATime[i] < G->TI[i][j].departTime)
							{
								//ȯ�°����ѵ�, ���� ���� �����ϴ°��
								if (neededBlood[eIndex] == neededBlood[i] && G->TI[i][j].arriveTime < minATime[eIndex]) {
									neededBlood[eIndex] = neededBlood[i];
									minATime[eIndex] = G->TI[i][j].arriveTime;
								}
								//�������� �Ǹ��ѹ� ���ž��ϴ°� ���� �����ϴ°��� �Ǿȸ��ð� ȯ�°����Ѱ��
								else if (neededBlood[eIndex] > neededBlood[i]) { // neededBlood���� �� ũ��
									neededBlood[eIndex] = neededBlood[i];
									minATime[eIndex] = G->TI[i][j].arriveTime;
								}
							}
							//�Ǹ� �ѹ� ���ž��ϴ°���ε�, ���� ���� �����ϴ°��
							else if (neededBlood[eIndex] > neededBlood[i] && G->TI[i][j].arriveTime < minATime[eIndex])
							{
								minATime[eIndex] = G->TI[i][j].arriveTime;
							}

						}
					}

				}

			}
		}
		qnIndex++;
	}




}




int main()
{
	int line;
	int i;
	char cityS[33], cityE[33];
	int startT, ing; //ing:start�ð����� �ɸ��½ð�
	int index;
	char startCity[33], endCity[33];
	int TC;
	cin >> TC;


	for(int tc=1; tc<=TC; tc++){
		Graph* G = new Graph();

		cin >> line; //��ΰ���

		for (i = 0; i < line; i++) {
			cin >> cityS >> cityE >> startT >> ing;

			ing = (startT + ing);
			if ((startT < 18 && startT>6) || (ing % 24 < 18 && ing % 24 > 6)) continue; //����Ż�� ���°�� �ǳʶ�.

			//���� Ż �� �ִ� ���
			bool forAddCityName = false;
			index = EnterOverlap(G, cityS, forAddCityName);
			if (forAddCityName) strcpy(G->cityName[index],cityS);
			strcpy(G->TI[index][G->degree[index]].arriveCity, cityE);
			G->TI[index][G->degree[index]].departTime = startT;
			G->TI[index][G->degree[index]].arriveTime = ing;
			G->degree[index]++;//���� ����

			//������ ���õ� �߰�
			forAddCityName = false;
			index = EnterOverlap(G, cityE, forAddCityName);
			if (forAddCityName) strcpy(G->cityName[index],  cityE);


		}

		cin >> startCity >> endCity;

		init();
		solve(G, startCity, endCity);

		cout << "Test Case " << tc << "." << '\n';

		if (finalOutput == -1) cout << "There is no route Vladimir can take." << '\n';
		else
			cout << "Vladimir needs " << finalOutput << " litre(s) of blood." << '\n';
		
		delete G;
	}
    return 0;
}




