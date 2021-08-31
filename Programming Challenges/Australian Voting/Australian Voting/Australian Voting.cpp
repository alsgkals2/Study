// Australian Voting.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class voting {
public:
	int survivedN = 0;//������ ��
	int n = 0;//�ĺ� ��
	int voter = 0; //��ǥ�� ��
	char** name;//�ĺ����̸�
	int** love;//�� ��ǥ�ڵ��� ��ȣ��
	int* priority;//�� �ĺ��ڵ��� 1�� ����

	voting* nextStart;

	int Function();
	void input();
	void print(int);
};

void voting::input() {

	cin >> n;//�ĺ� ��
	name = new char*[n];

	for (int count = 0; count < n; count++)
	{
		name[count] = new char[20];
		cin>>name[count]; //�ĺ��̸�
	}

	//��ȣ�� �����Է¹�����
	//love�� ���
	//���� �����ԷµǸ�(���ٵ鿩����) ����
	love = new int*[1000];
	int j = -1, i = 0;
	int swit = 0;

	while (1) {

		if (i%n == 0) {
			j++;
			love[j] = new int[n];
		}
		cin >> love[j][i%n];
		if (love[j][0] == 0) { cout << endl; break; }

		i++;
	}
	voter = j;
	priority = new int[n];
	for (i = 0; i < n; i++)priority[i] = 0;
}

int voting::Function() {
	int compareSurveved = 1;
	int i, j;
	survivedN = n;
	bool same;
	const int half = voter / 2 + voter % 2;

	//1�� ���� ��
	for (i = 0; i < voter; i++) {
		for (j = 0; j < n; j++) {
			if (love[i][j] == 1) priority[j]++;
		}
	}

	while (1) {
		//��ǥ���� ��� ���� ���
		same = true;
		for (j = 0; j < n; j++)
		{
			if (priority[j] != -1 && priority[j] != -2)
				if (priority[j] != priority[compareSurveved])
				{ same = false; break; }
		}
		if (same == true) {/*��� �ĺ����̸� ���*/return -1; }

		//�ٸ� ���, 1�� ���� ���̻��̸�
		else if (same == false) {

			for (j = 0; j < n; j++)
			{
				if (priority[j] >= half) {
					/*j��° �ĺ����̸� ���*/return j;
				}
			}


			//�ƴ� ��� 1�� ���� ���� ���� �ĺ��� ��ǥ�� ����
			int mini = priority[compareSurveved];
			for (j = 0; j < n; j++)
			{
				if (priority[j] >= 0 && priority[j] <= mini) {
					mini = priority[j];
				}
			}

			//Ż���� �ĺ��ڿ� ���� ���� �ִ� �ĺ��ڰ� �ִٸ� �Բ�Ż��,
			for (j = 0; j < n; j++)
			{
				if (priority[j] == mini) {
					priority[j] = -1; //Ż�� ó��
					survivedN--;
				}
			}

			//priority���� 2����ǥ�� ������� ��ǥ �� ����. ���� 2�� ��ǥ�� ����� Ż���ߴٸ� 3����, 4�� ....
			int nextNum = 2;

			for (j = 0; j < n; j++)
			{
				if (priority[j] == -1) {
					for (i = 0; i < voter; i++) {
						if (love[i][j] == 1) {
							for (int second = 0; second < n; second++) {
								if (love[i%voter][second] == nextNum) {
									if (priority[second] == -1 || priority[second] == -2) {//���� �켱������ Ż�����̸�
										nextNum++; continue;
									}
									else {
										priority[second]++;//��ǥ�� �ű��
										compareSurveved = second;//������ �ĺ��ڹ�ȣ ����
										priority[j] = -2;//��ǥ�� �ű�� ó���� Ż���ڴ� -2���� ����
									
										break;
									}//������ Ž�������� ��������
								}
							}
						}
					}

				}

			}

			//�����ڰ� �Ѹ��̸� ������ ���
			if (survivedN == 1) {
				for (j = 0; j < n; j++)
				{
					if (priority[j] != -2 && priority[j] != -1) return j;
				}
			}

			//���ǰ��� �ݺ�
		}
	}
}
void voting:: print(int candi) {
	if (candi == -1)//��� �ĺ��� ���
	{
		for (int i = 0; i < n; i++) {
			cout << name[i] << endl;
		}
	}
	else {
		cout << name[candi] << endl;
	}
}
int main()
{
	voting *v = new voting();
	voting *start = new voting();
	start = v;
	voting *next = new voting();
	next = v;

	int num = 0;
	cin >> num;//�Է����̽�����
	int* save = new int[num];

	for (int i = 0; i < num; i++) {
		next->input();
		save[i] = next->Function();
		next->nextStart = new voting();
		next = next->nextStart;
	}

	for (int i = 0; i < num; i++) {
		start->print(save[i]);
		start = start->nextStart;
	}


	return 0;
}

