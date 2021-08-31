// Soccor.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Team {
public:
	string name;
	int score = 0;
	int playNum = 0;
	int winPlay = 0;
	int drawPlay = 0;
	int losePlay = 0;
	int putGoal = 0;
	int awayGoal = 0;
	int mGoal = 0;
};

bool Checking6(Team &firstTeam, Team &left_rightTeam) {
	int firstTeamSize = firstTeam.name.size();
	int left_rightTeamSize = left_rightTeam.name.size();

	int smallestTeamSize = firstTeamSize < left_rightTeamSize ? firstTeamSize : left_rightTeamSize;//�� ª���� ������ϱ�

	string firstTeamName = firstTeam.name;
	string left_rightTeamName = left_rightTeam.name;

	for (int s = 0; s < smallestTeamSize; s++) {
		if (firstTeamName[s] >= 65 && firstTeamName[s] <= 90)firstTeamName[s] += 32;
		if (left_rightTeamName[s] >= 65 && left_rightTeamName[s] <= 90)left_rightTeamName[s] += 32;
		if (firstTeamName[s] > left_rightTeamName[s]) return false;
		else if (firstTeamName[s] < left_rightTeamName[s]) return true;
	}
	
	if (smallestTeamSize == firstTeamSize) return true; // ex) brazil�� brazilll�� �ִ°�� ������ �켱�����̹Ƿ�
	else return false;

}
bool Checking5(Team &firstTeam, Team &left_rightTeam) {
	//���Ӽ� ������
	if (firstTeam.playNum == left_rightTeam.playNum)
	{
		return Checking6(firstTeam, left_rightTeam);
	}
	else if (firstTeam.playNum > left_rightTeam.playNum) {
		return false;
	}
	else return true;

}
bool Checking4(Team &firstTeam, Team &left_rightTeam) {
	if (firstTeam.putGoal == left_rightTeam.putGoal)
	{
		return Checking5(firstTeam, left_rightTeam);
	}
	else if (firstTeam.putGoal < left_rightTeam.putGoal) {
		return false;
	}
	else return true;

}
bool Checking3(Team &firstTeam, Team &left_rightTeam) {
	if (firstTeam.mGoal == left_rightTeam.mGoal)
	{
		return Checking4(firstTeam, left_rightTeam);
	}
	else if (firstTeam.mGoal < left_rightTeam.mGoal) {
		return false;
	}
	else return true;

}

bool Checking2(Team &firstTeam, Team& left_rightTeam) {
	//first�� ��ũ�� false
	if (firstTeam.winPlay == left_rightTeam.winPlay)
	{
		return Checking3(firstTeam,left_rightTeam);
	}
	else if (firstTeam.winPlay < left_rightTeam.winPlay) {
		return false;
	}
	else return true;
}

int Partition(int left, int right, Team* team) { //�������� �����Ѵ�.
	int first = left;
	int pivot = team[first].score;
	left++; 

	while (left <= right) {

		while (team[left].score >= pivot && left < right) {

			if (team[left].score == pivot) {
				if(!Checking2(team[first],team[left])){left++; continue;}
				else break;
			}//�ٸ� �������� �˻�

			else//ū���
				left++;
		}
		while (team[right].score <= pivot && left <= right) {

			if (team[right].score == pivot) {
				if(Checking2(team[first], team[right])){right--; continue;}
				else break;
			}//�ٸ� �������� �˻�

			else//�������
				right--;
		}

		if (left < right) {
			Team temp = team[left];
			team[left] = team[right];
			team[right] = temp;
		}
		else break;
	}

	Team temp = team[first];
	team[first] = team[right];
	team[right] = temp;


	return right;
}

void Quick(int left, int right, Team* team) {
	if (left < right) {
		int index = Partition(left, right, team);

		Quick(left, index-1, team);
		Quick(index+1, right, team);
	}
}


Team* teamInform;
int* T ;
int n = -1;

int FindIndex(string s) {
	for (int t = 0; t < T[n]; t++) {
		if (s.compare(teamInform[t].name) == 0)
			return t;
	}
}

void JudgeTonerment(string s) {
	int size = s.size();
	string leftTeam, rightTeam;
	string leftScore, rightScore;
	int leftScoreToint = 0, rightScoreToint = 0;
	int inc = 0;

	//��������
	while (s[inc] != '#') {
		leftTeam += s[inc++];
	}
	
	inc += 1;//���ʽ��ھ�
	while (s[inc] != '@') {
		leftScore += s[inc++];
	}
	leftScoreToint = stoi(leftScore);

	//�����ʽ��ھ�
	inc += 1;
	while (s[inc] != '#') {
		rightScore += s[inc++];
	}
	rightScoreToint = stoi(rightScore);

	//����������
	inc += 1;
	while (inc != size) {
		rightTeam += s[inc++];
	}

	int leftTeamIndex = FindIndex(leftTeam);
	int rightTeamIndex = FindIndex(rightTeam);

	teamInform[leftTeamIndex].playNum++;
	teamInform[rightTeamIndex].playNum++;

	teamInform[leftTeamIndex].putGoal += leftScoreToint;
	teamInform[leftTeamIndex].awayGoal += rightScoreToint;

	teamInform[rightTeamIndex].putGoal += rightScoreToint;
	teamInform[rightTeamIndex].awayGoal += leftScoreToint;

	if (rightScoreToint < leftScoreToint) {//�������� �̱���
		//����
		teamInform[leftTeamIndex].score += 3;
		teamInform[leftTeamIndex].winPlay++;

		//������
		teamInform[rightTeamIndex].losePlay++;
	}
	else if (rightScoreToint == leftScoreToint) {//�����
		teamInform[leftTeamIndex].score += 1;
		teamInform[leftTeamIndex].drawPlay+=1;

		teamInform[rightTeamIndex].score += 1;
		teamInform[rightTeamIndex].drawPlay+=1;
	}
	else {//���������� �̱���
		//����
		teamInform[leftTeamIndex].losePlay++;

		//������
		teamInform[rightTeamIndex].score += 3;
		teamInform[rightTeamIndex].winPlay++;

	}

}


int TNUM = 30;

int main()
{
	string tonumentName;
	string input;
	int N = 0;
	int G = 0;
	cin >> N;
	cin.ignore();
	string** output = new string*[N];
	T = new int[N];
	while (++n!=N) {
		getline(cin, tonumentName);
		cin >> T[n]; cin.ignore();
		teamInform = new Team[T[n]];

		output[n] = new string[T[n] + 1];
		output[n][0] = tonumentName;//��ʸ�Ʈ�� ����
		tonumentName.clear();

		//���� �Է�
		for (int t = 0; t < T[n]; t++) {
			getline(cin, teamInform[t].name);
		}
		cin >> G; cin.ignore();

		//����� ���ھ��Է�
		for (int g = 0; g < G; g++)
		{
			getline(cin, input);//��⽺�ھ�
			JudgeTonerment(input);
			input.clear();
		}
		//����� ���
		for (int t = 0; t < T[n]; t++) {
			teamInform[t].mGoal = teamInform[t].putGoal - teamInform[t].awayGoal;
		}

		//����
		Quick(0, T[n] - 1, teamInform);


		//output����
		for (int i = 1; i < T[n] + 1; i++) {
			ostringstream oss;
			oss << i << ") " << teamInform[i - 1].name << " " << teamInform[i - 1].score << "p, " << teamInform[i - 1].playNum << "g " << "(" << teamInform[i - 1].winPlay << "-" << teamInform[i - 1].drawPlay << "-" << teamInform[i - 1].losePlay << "), " << teamInform[i - 1].mGoal << "gd (" << teamInform[i - 1].putGoal << "-" << teamInform[i - 1].awayGoal << ")" ;
			output[n][i] = oss.str();
			
		}

	}

	//���
	for (int n = 0; n < N; n++) {
		for (int t = 0; t < T[n] + 1; t++) {
			cout << output[n][t] << endl;
		}
		cout << endl;
	}

	/*testcase*/
	/*
	1
	Group A
	4
	Brazil
	Norway
	Brazill
	Morocco
	2
	Brazil#3@1#Brazill
	Norway#2@2#Morocco
	*/

    return 0;
}

