// From Dusk Till Dawn.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	char cityName[100][33]; //도시이름(32글자 이내)
	Train TI[100][1000];//각 도시에대새허 노선정보
	int degree[100];//각 도시의 노선갯수
	int beforSorted[100];
	int cityNum = 0;
}Graph;


int EnterOverlap(Graph* G, char* cityN,bool& facn) {
	int i = 0;
	while (G->cityName[i][0]) {
		if (!strcmp(G->cityName[i], cityN)) return i; //일치하면
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
		else//같은경우
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

		if (cityList[eIndex] != qnIndex)//체크돼잇지 않으면
		{
			cityList[eIndex] = qnIndex;
			queueNum[qnIndex]++;
			minATime[eIndex] = G->TI[sIndex][j].arriveTime;
			finished = false;
		}
		else//중복되는 경우
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
					
						//목적지를 발견한경우
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

						else//중복되는 경우
						{

							//12시간내에 두번이상 환승가능한경우
							if (minATime[i] < G->TI[i][j].departTime)
							{
								//환승가능한데, 좀더 빨리 도착하는경우
								if (neededBlood[eIndex] == neededBlood[i] && G->TI[i][j].arriveTime < minATime[eIndex]) {
									neededBlood[eIndex] = neededBlood[i];
									minATime[eIndex] = G->TI[i][j].arriveTime;
								}
								//이전값은 피를한번 마셔야하는경운데 새로 갱신하는값은 피안마시고 환승가능한경우
								else if (neededBlood[eIndex] > neededBlood[i]) { // neededBlood값이 더 크면
									neededBlood[eIndex] = neededBlood[i];
									minATime[eIndex] = G->TI[i][j].arriveTime;
								}
							}
							//피를 한번 마셔야하는경우인데, 좀더 빨리 도착하는경우
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
	int startT, ing; //ing:start시간부터 걸리는시간
	int index;
	char startCity[33], endCity[33];
	int TC;
	cin >> TC;


	for(int tc=1; tc<=TC; tc++){
		Graph* G = new Graph();

		cin >> line; //경로갯수

		for (i = 0; i < line; i++) {
			cin >> cityS >> cityE >> startT >> ing;

			ing = (startT + ing);
			if ((startT < 18 && startT>6) || (ing % 24 < 18 && ing % 24 > 6)) continue; //기차탈수 없는경우 건너뜀.

			//기차 탈 수 있는 경우
			bool forAddCityName = false;
			index = EnterOverlap(G, cityS, forAddCityName);
			if (forAddCityName) strcpy(G->cityName[index],cityS);
			strcpy(G->TI[index][G->degree[index]].arriveCity, cityE);
			G->TI[index][G->degree[index]].departTime = startT;
			G->TI[index][G->degree[index]].arriveTime = ing;
			G->degree[index]++;//차수 증가

			//도착지 도시도 추가
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




