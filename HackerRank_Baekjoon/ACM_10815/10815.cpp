// 10815.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <list>
#include <algorithm>
#include <iostream>
//������ ������ 1
//�ƴϸ� 0
//1: ī�尹�� 2: �� ī���� �� 3: ī�尹�� 4: �� ī���� ��

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
			cardValue1.push_back(v1);//�ڿ� �� �߰�
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
			cardValue2.push_back(v2);//�ڿ� �� �߰�
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

			//cardvalue1������ Ž��
			//for (; iter != cardValue1.end(); iter++)
			//{
				//�߰��ϸ� �Ѵ� �˻� ����� �ƴϹǷ� �����ϰ�����
				//if ((*iter) == n) {
			list<int>::iterator it = find(iter, cardValue1.end(), n);
					if (it == cardValue1.end())
						cout <<zero<< " ";
					else
					{
						cout << one << " ";
						cardValue1.erase(it);
					}
					//cardValue2.pop_front();//�˻��������� ����.
					//cout << "1 " ;
			//	}
			

			//Ž�� ���ߴµ� �����Ƿ�
			cardValue2.pop_front();//�˻��������� ����.
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

