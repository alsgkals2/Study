// 10815.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <list>
#include <algorithm>
#include <iostream>
//가지고 있으면 1
//아니면 0
//1: 카드갯수 2: 각 카드의 값 3: 카드갯수 4: 각 카드의 값

using namespace std;
class start
{
private:
	int cardNum1;
	int cardNum2;
	list<int> cardValue1;
	list<int> cardValue2;
public:
	void input_1()
	{
		cin>> cardNum1;
		cardValue1.resize(cardNum1);

		int v1;

		for (int i = 0; i < cardNum1; i++)
		{
			cin >> v1;
			cardValue1.push_back(v1);//뒤에 값 추가
		}

		//cardNum1 = 5;
		//cardValue1.push_back(6);
		//cardValue1.push_back(3);
		//cardValue1.push_back(2);
		//cardValue1.push_back(10);
		//cardValue1.push_back(-10);

	}
	void input_2()
	{
		cin >> cardNum2;
		cardValue1.resize(cardNum2);

		int v2;

		for (int i = 0; i < cardNum1; i++)
		{
			cin >> v2;
			cardValue2.push_back(v2);//뒤에 값 추가
		}
		//cardNum2 = 8;
		//cardValue2.push_back(10);
		//cardValue2.push_back(9);
		//cardValue2.push_back(-5);
		//cardValue2.push_back(2);
		//cardValue2.push_back(3);
		//cardValue2.push_back(4);
		//cardValue2.push_back(5);
		//cardValue2.push_back(-10);

	}
	void StartSearch()
	{
		const int zero = 0;
		const int one = 1;
		while (cardValue2.size() != 0) {

			int n = cardValue2.front();

			list<int>::iterator iter = cardValue1.begin();

			//cardvalue1끝까지 탐색
			//for (; iter != cardValue1.end(); iter++)
			//{
				//발견하면 둘다 검색 대상이 아니므로 삭제하고종료
				//if ((*iter) == n) {
			list<int>::iterator it = find(iter, cardValue1.end(), n);
					if (it == cardValue1.end())
						cout <<zero<< " ";
					else
					{
						cout << one << " ";
						cardValue1.erase(it);
					}
					//cardValue2.pop_front();//검색끝났으니 뺀다.
					//cout << "1 " ;
			//	}
			

			//탐색 다했는데 없으므로
			cardValue2.pop_front();//검색끝났으니 뺀다.
			//cout << "0 ";
			//return 0;
		}
	}
};

int main()
{
	start start;
	start.input_1();
	start.input_2();

	start.StartSearch();

    return 0;
}

