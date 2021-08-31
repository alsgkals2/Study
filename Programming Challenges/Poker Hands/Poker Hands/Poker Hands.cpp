// Poker Hands.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	if (a == 0)//화이트
	{
		cout << "White wins.";
	}
	else if (a == 1)//블랙
	{
		cout << "Black wins.";
	}
	else if (a == 2)//비김
	{
		cout << "Tie.";
	}
}
int inter(char c) {//A,K등의 영어값들은 숫자로변환
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
	//스트레이트플러시

	if (StPlush(black) != 0 || StPlush(white) != 0) {
		blackValue = StPlush(black);
		whiteValue = StPlush(white);
		if (blackValue != 0 && whiteValue != 0) {//둘다 스트레이트플러시인경우
			if (blackValue > whiteValue) //검정승리
			{
				return 1;
			}

			else if (whiteValue > blackValue)//화이트승리
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //검정색이 스트레이트플러시가 아닌데 화이트는 스트레이트 플러시인경우
		{
			//화이트 승리
			return 0;
		}
		else if (blackValue != 0) {
			//검정승리
			return 1;
		}
	}

	//포카드
	else if (PCard(black) != 0 || PCard(white) != 0) 
	{
		blackValue = PCard(black);
		whiteValue = PCard(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //검정승리
			{
				return 1;
			}

			else if (whiteValue > blackValue)//화이트승리
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //검정색이 스트레이트플러시가 아닌데 화이트는 스트레이트 플러시인경우
		{
			//화이트 승리
			return 0;
		}
		else if (blackValue != 0) {
			//검정승리
			return 1;
		}
	}

	//풀하우스
	else if (Full(black) != 0 || Full(white) != 0) //둘다 스트레이트플러시가 아닌경우
	{
		blackValue = Full(black);
		whiteValue = Full(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //검정승리
			{
				return 1;
			}

			else if (whiteValue > blackValue)//화이트승리
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //검정색이 스트레이트플러시가 아닌데 화이트는 스트레이트 플러시인경우
		{
			//화이트 승리
			return 0;
		}
		else if (blackValue != 0) {
			//검정승리
			return 1;
		}
	}
	//플러시
	else if (Plush(black) != 0 || Plush(white) != 0) //둘다 스트레이트플러시가 아닌경우
	{
		blackValue = Plush(black);
		whiteValue = Plush(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //검정승리
			{
				return 1;
			}

			else if (whiteValue > blackValue)//화이트승리
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //검정색이 스트레이트플러시가 아닌데 화이트는 스트레이트 플러시인경우
		{
			//화이트 승리
			return 0;
		}
		else if (blackValue != ',') {
			//검정승리
			return 1;
		}
	}
	//스트레이트
	else if (St(black) != 0 || St(white) != 0) //둘다 스트레이트플러시가 아닌경우
	{
		blackValue = St(black);
		whiteValue = St(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //검정승리
			{
				return 1;
			}

			else if (whiteValue > blackValue)//화이트승리
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //검정색이 스트레이트플러시가 아닌데 화이트는 스트레이트 플러시인경우
		{
			//화이트 승리
			return 0;
		}
		else if (blackValue != ',') {
			//검정승리
			return 1;
		}
	}
	//쓰리카드
	else if (Three(black) != 0 || Three(white) != 0) //둘다 스트레이트플러시가 아닌경우
	{
		blackValue = Three(black);
		whiteValue = Three(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //검정승리
			{
				return 1;
			}

			else if (whiteValue > blackValue)//화이트승리
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //검정색이 스트레이트플러시가 아닌데 화이트는 스트레이트 플러시인경우
		{
			//화이트 승리
			return 0;
		}
		else if (blackValue != 0) {
			//검정승리
			return 1;
		}
	}
	//투페어
	else if (Two(black) != 0 || Two(white) != 0) //둘다 스트레이트플러시가 아닌경우
	{
		blackValue = Two(black);
		whiteValue = Two(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //검정승리
			{
				return 1;
			}

			else if (whiteValue > blackValue)//화이트승리
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //검정색이 스트레이트플러시가 아닌데 화이트는 스트레이트 플러시인경우
		{
			//화이트 승리
			return 0;
		}
		else if (blackValue != 0) {
			//검정승리
			return 1;
		}
	}
	//원페어
	else if (One(black) != 0 || One(white) != 0) //둘다 스트레이트플러시가 아닌경우
	{
		blackValue = One(black);
		whiteValue = One(white);

		if (blackValue != 0 && whiteValue != 0) {
			if (blackValue > whiteValue) //검정승리
			{
				return 1;
			}

			else if (whiteValue > blackValue)//화이트승리
			{
				return 0;
			}
		}
		else if (whiteValue != 0) //검정색이 스트레이트플러시가 아닌데 화이트는 스트레이트 플러시인경우
		{
			//화이트 승리
			return 0;
		}
		else if (blackValue != 0) {
			//검정승리
			return 1;
		}
	}
	//하이카드
	else if (High(black, white) == 1) { return 1; }
	else if (High(black, white) == 0) { return 0; }
	else {
		return 2;//"tie"
	}
}
//모든함수에 대해서 리턴값이 0이면 존재x, 존재하면 그중 비교할 값 반환
int StPlush(char** object) {
	//다섯장의 카드가 무늬가 같으면서 모두 연속적인 값을 가지는 경우

	int i = 0;

	//무늬가 다르면 리턴
	for (i = 0; i < 4; i++) {
		if (object[i][1] != object[i + 1][1]) {
			return 0;
		}
	}

	//연속적인 값이 아니면 리턴
	int sub = object[0][0] - object[1][0];
	if (abs(sub) != 1) return 0;

	for (i = 1; i < 4; i++) {
		if (object[i][0] - object[i + 1][0] != sub) {
			return 0;
		}
	}
	//문자일경우 숫자로 바꿈
	return inter(object[4][0]);

}
int PCard(char** object) {
	//네장의 카드가 같은 값을 가지는 경우
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
		//문자일경우 숫자로 바꿈
		return inter(high);
	}
	else return 0;
}
int Full(char** object) {
	//세장의카드가 같은 값을가지고 나머지 두장의 카드가 같은 값을 가지는 경우
	int count = 0;
	int count2 = 0;
	int high = 0;
	if (object[0][0] != object[1][0]) return 0;

	//세장이 같다면
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
	//두장이 같다면
	if (object[2][0] == object[3][0] == object[4][0]) {
		for (int i = 2; i < 4; i++)//가장 높은것 비교
			if (high < inter(object[i + 1][0])) high = inter(object[i + 1][0]);
			else high = inter(object[2][0]);
		return high;
	}
	else return 0;
}
int Plush(char** object) {
	int i = 0;

	//무늬가 다르면 리턴
	for (i = 0; i < 4; i++) {
		if (object[i][1] != object[i + 1][1]) {
			return 0;
		}
	}

	return inter(object[4][0]);
}
int St(char** object) {
	//다섯장의 카드가 연속적인 경우
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
//다 아닌경우 "tie"출력
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


	//연속적인 값 검사하기위해 정렬
	bool swit = false;
	blackmini = 0;//요소 저장
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

