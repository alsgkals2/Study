// Poker Hands.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//


#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int StPlush(char**);
int PCard(char**);
int Full(char**);
int Plush(char**);
int St(char**);
int Three(char**);
int Two(char**);
int One(char**);
int High(char**,char**);
int inter(char);
int Function(char**, char**);
void print(int);

void print(int a) {
	if (a == 0)//ȭ��Ʈ
	{
		cout << "White wins.";
	}
	else if (a == 1)//��
	{
		cout << "Black wins.";
	}
	else if (a == 2)//���
	{
		cout << "Tie.";
	}
}
int inter(char c) {//A,K���� ������� ���ڷκ�ȯ
	int ret = atoi(&c);
	if (ret > 9 || ret <= 0) {
		if (c == 'T') return 10;
		else if (c == 'J') return 11;
		else if (c == 'Q') return 12;
		else if (c == 'K') return 13;
		else if (c == 'A') return 14;
	}
	else return ret;
}
int Function(char** black, char** white) {
	int blackValue = 0, whiteValue = 0;
	//��Ʈ����Ʈ�÷���

	if (StPlush(black) != 0 || StPlush(white) != 0) {
		blackValue = StPlush(black);
		whiteValue = StPlush(white);
		if (blackValue != 0 && whiteValue != 0) {//�Ѵ� ��Ʈ����Ʈ�÷����ΰ��
			if (blackValue > whiteValue) //�����¸�
			{
				return 1;
			}

			else if (whiteValue > blackValue)//ȭ��Ʈ�¸�
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //�������� ��Ʈ����Ʈ�÷��ð� �ƴѵ� ȭ��Ʈ�� ��Ʈ����Ʈ �÷����ΰ��
		{
			//ȭ��Ʈ �¸�
			return 0;
		}
		else if (blackValue != 0) {
			//�����¸�
			return 1;
		}
	}

	//��ī��
	else if (PCard(black) != 0 || PCard(white) != 0) 
	{
		blackValue = PCard(black);
		whiteValue = PCard(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //�����¸�
			{
				return 1;
			}

			else if (whiteValue > blackValue)//ȭ��Ʈ�¸�
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //�������� ��Ʈ����Ʈ�÷��ð� �ƴѵ� ȭ��Ʈ�� ��Ʈ����Ʈ �÷����ΰ��
		{
			//ȭ��Ʈ �¸�
			return 0;
		}
		else if (blackValue != 0) {
			//�����¸�
			return 1;
		}
	}

	//Ǯ�Ͽ콺
	else if (Full(black) != 0 || Full(white) != 0) //�Ѵ� ��Ʈ����Ʈ�÷��ð� �ƴѰ��
	{
		blackValue = Full(black);
		whiteValue = Full(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //�����¸�
			{
				return 1;
			}

			else if (whiteValue > blackValue)//ȭ��Ʈ�¸�
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //�������� ��Ʈ����Ʈ�÷��ð� �ƴѵ� ȭ��Ʈ�� ��Ʈ����Ʈ �÷����ΰ��
		{
			//ȭ��Ʈ �¸�
			return 0;
		}
		else if (blackValue != 0) {
			//�����¸�
			return 1;
		}
	}
	//�÷���
	else if (Plush(black) != 0 || Plush(white) != 0) //�Ѵ� ��Ʈ����Ʈ�÷��ð� �ƴѰ��
	{
		blackValue = Plush(black);
		whiteValue = Plush(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //�����¸�
			{
				return 1;
			}

			else if (whiteValue > blackValue)//ȭ��Ʈ�¸�
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //�������� ��Ʈ����Ʈ�÷��ð� �ƴѵ� ȭ��Ʈ�� ��Ʈ����Ʈ �÷����ΰ��
		{
			//ȭ��Ʈ �¸�
			return 0;
		}
		else if (blackValue != ',') {
			//�����¸�
			return 1;
		}
	}
	//��Ʈ����Ʈ
	else if (St(black) != 0 || St(white) != 0) //�Ѵ� ��Ʈ����Ʈ�÷��ð� �ƴѰ��
	{
		blackValue = St(black);
		whiteValue = St(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //�����¸�
			{
				return 1;
			}

			else if (whiteValue > blackValue)//ȭ��Ʈ�¸�
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //�������� ��Ʈ����Ʈ�÷��ð� �ƴѵ� ȭ��Ʈ�� ��Ʈ����Ʈ �÷����ΰ��
		{
			//ȭ��Ʈ �¸�
			return 0;
		}
		else if (blackValue != ',') {
			//�����¸�
			return 1;
		}
	}
	//����ī��
	else if (Three(black) != 0 || Three(white) != 0) //�Ѵ� ��Ʈ����Ʈ�÷��ð� �ƴѰ��
	{
		blackValue = Three(black);
		whiteValue = Three(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //�����¸�
			{
				return 1;
			}

			else if (whiteValue > blackValue)//ȭ��Ʈ�¸�
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //�������� ��Ʈ����Ʈ�÷��ð� �ƴѵ� ȭ��Ʈ�� ��Ʈ����Ʈ �÷����ΰ��
		{
			//ȭ��Ʈ �¸�
			return 0;
		}
		else if (blackValue != 0) {
			//�����¸�
			return 1;
		}
	}
	//�����
	else if (Two(black) != 0 || Two(white) != 0) //�Ѵ� ��Ʈ����Ʈ�÷��ð� �ƴѰ��
	{
		blackValue = Two(black);
		whiteValue = Two(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //�����¸�
			{
				return 1;
			}

			else if (whiteValue > blackValue)//ȭ��Ʈ�¸�
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //�������� ��Ʈ����Ʈ�÷��ð� �ƴѵ� ȭ��Ʈ�� ��Ʈ����Ʈ �÷����ΰ��
		{
			//ȭ��Ʈ �¸�
			return 0;
		}
		else if (blackValue != 0) {
			//�����¸�
			return 1;
		}
	}
	//�����
	else if (One(black) != 0 || One(white) != 0) //�Ѵ� ��Ʈ����Ʈ�÷��ð� �ƴѰ��
	{
		blackValue = One(black);
		whiteValue = One(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //�����¸�
			{
				return 1;
			}

			else if (whiteValue > blackValue)//ȭ��Ʈ�¸�
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //�������� ��Ʈ����Ʈ�÷��ð� �ƴѵ� ȭ��Ʈ�� ��Ʈ����Ʈ �÷����ΰ��
		{
			//ȭ��Ʈ �¸�
			return 0;
		}
		else if (blackValue != 0) {
			//�����¸�
			return 1;
		}
	}
	//����ī��
	else if (High(black, white) == 1) { return 1; }
	else if (High(black, white) == 0) { return 0; }
	else {
		return 2;//"tie"
	}
}
//����Լ��� ���ؼ� ���ϰ��� 0�̸� ����x, �����ϸ� ���� ���� �� ��ȯ
int StPlush(char** object) {
	//�ټ����� ī�尡 ���̰� �����鼭 ��� �������� ���� ������ ���

	int i = 0;

	//���̰� �ٸ��� ����
	for (i = 0; i < 4; i++) {
		if (object[i][1] != object[i + 1][1]) {
			return 0;
		}
	}

	//�������� ���� �ƴϸ� ����
	int sub = object[0][0] - object[1][0];
	if (abs(sub) != 1) return 0;

	for (i = 1; i < 4; i++) {
		if (object[i][0] - object[i + 1][0] != sub) {
			return 0;
		}
	}
	//�����ϰ�� ���ڷ� �ٲ�
	return inter(object[4][0]);

}
int PCard(char** object) {
	//������ ī�尡 ���� ���� ������ ���
	int count = 0;
	char high = object[1][0];
	bool swit = false;
	for (int i = 0; i < 4; i++) {
		if (swit == false&&object[i][0] == object[i + 1][0]) {
			high = object[i][0];
			count++;
			swit = true;
			if (count == 3) break;
		}
		else if (swit == true && high == object[i + 1][0]) {
			count++;
		if (count == 3) break;
		}
		else { count = 0; }
	}
	if (count == 3) {
		//�����ϰ�� ���ڷ� �ٲ�
		return inter(high);
	}
	else return 0;
}
int Full(char** object) {
	//������ī�尡 ���� ���������� ������ ������ ī�尡 ���� ���� ������ ���
	int count = 0;
	int count2 = 0;
	int high = 0;
	if (object[0][0] != object[1][0]) return 0;

	//������ ���ٸ�
	if (object[1][0] == object[2][0])
	{
		if (object[3][0] != object[4][0]) return 0;
		else {
			high = inter(object[0][0]);
			for (int i = 0; i < 2; i++)
			{
				if (high < inter(object[i + 1][0])) high = inter(object[i + 1][0]);
			}
			return high;
		}
	}
	//������ ���ٸ�
	if (object[2][0] == object[3][0] == object[4][0]) {
		for (int i = 2; i < 4; i++)//���� ������ ��
			if (high < inter(object[i + 1][0])) high = inter(object[i + 1][0]);
			else high = inter(object[2][0]);
		return high;
	}
	else return 0;
}
int Plush(char** object) {
	int i = 0;

	//���̰� �ٸ��� ����
	for (i = 0; i < 4; i++) {
		if (object[i][1] != object[i + 1][1]) {
			return 0;
		}
	}

	return inter(object[4][0]);
}
int St(char** object) {
	//�ټ����� ī�尡 �������� ���
	int i = 0;
	int sub = object[0][0] - object[1][0];
	if (abs(sub) != 1) return 0;

	for (i = 1; i < 4; i++) {
		if (object[i][0] - object[i + 1][0] != sub) {
			return 0;
		}
	}

	return inter(object[4][0]);

}
int Three(char** object) {
	int count = 0;

	for (int i = 0; i < 4; i++) {
		if (object[i][0] == object[i + 1][0])
			count++;
		if (count == 2) return inter(object[i + 1][0]);
	}
	return 0;
}
int Two(char** object) {
	char high = NULL;
	int swit1 = -1, swit2 = -1;

	for (int i = 0; i < 4; i++) {
		if (object[i][0] == object[i + 1][0])
			if (swit1 == -1) {
				swit1 = i;
			}
			else { swit2 = i; }
	}
	if (swit1 != -1 && swit2 != -1) return inter(object[swit2 + 1][0]);
	else return 0;
}

int One(char** object) {
	int count = 0;

	for (int i = 0; i < 4; i++) {
		if (object[i][0] == object[i + 1][0])
		{
			return inter(object[i][0]);
		}
	}
	return 0;
}
int High(char** object1, char** object2) {

	for (int i = 4; i>=0; i--) {
		if (object1[i][0] == object2[i][0]) continue;
		else if (object1[i][0] > object2[i][0]) return 1;
		else if (object1[i][0] < object2[i][0]) return 0;

	}
	return -1;
}
//�� �ƴѰ�� "tie"���
int main()
{
	char **black = new char*[5];
	char **white = new char*[5];
	int blackmini, whitemini;
	int i;
	for (i = 0; i < 5; i++)
	{
		black[i] = new char[2];
		cin >> black[i];
	}


	//�������� �� �˻��ϱ����� ����
	bool swit = false;
	blackmini = 0;//��� ����
	char* buff = new char[2];

	for (int j = 0; j < 5; j++) {
		for (i = j + 1; i < 5; i++) {
			if (inter(black[j][0]) > inter(black[i][0])) {
				blackmini = i;
				swit = true;
			}
		}
		if (swit == true)
		{
			buff[0] = black[j][0];
			buff[1] = black[j][1];
			black[j] = black[blackmini];
			black[blackmini][0] = buff[0];
			black[blackmini][1] = buff[1];
			swit = false;
		}

	}

	for (i = 0; i < 5; i++)
	{
		white[i] = new char[2];
		cin >> white[i];
	}

	whitemini = 0;
	swit = false;
	for (int j = 0; j < 5; j++) {
		for (i = j+1; i < 5; i++) {
			if (inter(white[j][0]) > inter(white[i][0])) {
				whitemini = i;
				swit = true;
			}
		}
		if (swit == true)
		{
			buff[0] = white[j][0];
			buff[1] = white[j][1];
			white[j] = white[whitemini];
			white[whitemini][0] = buff[0];
			white[whitemini][1] = buff[1];
			swit = false;
		}
	}
	print(Function(black, white));
	return 0;
}

