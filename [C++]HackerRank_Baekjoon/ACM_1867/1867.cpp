// 1867.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
//#include <vector>
//#include <map>
//#include <array>
using namespace std;

class STARTER{
public:
	//n : ���� n x n
	//num :������ ����
	int n, num;
	//vector<int> vMatrix;
	//multimap<int, int> mMatrix;
	//map<int, int> vMatrix;
	int arr[501][501];
	int nNum[501];
	//check[����Ŵ ���ϴ� �� ���] = ����Ű�� �� ���
	int check[501];
	int imaginaryCheck[501];
	int arrIncStartIndex[501];
	int arr_excludedIndex[591];
	int iSetNum;
	bool bExcutedIndex[501];
	int nNode;
	int startIndex[501];

	//������ check�� ����� ���� index�� Ž���Ͽ� pass�Ѵ�.
	//return index
	//check[����Ŵ ���ϴ� �� ���] = ����Ű�� �� ���
	int PassCheckedNode(int nNode)
	{
		for (int i = 1; i <= 501; i++)
		{
			if (check[i] == nNode)
				return i;

		}

		return -1;

	}

	//5�� 5�� ��Ī�ؾ��Ѵ�.
	bool CheckMachingAble(int m,int n,bool info) //m:����Ŵ ���ϴ� ��� n:����Ű�� ���
												 //bool info : nNode�� ���ο� ������ ���ŵǸ� info�� true
	{
		//if(bExcutedIndex)
		//bExcutedIndex[n] = true;


			//static int i = 1;


			//check[����Ŵ ���ϴ� �� ���] = ����Ű�� �� ���
			int nNode = imaginaryCheck[m];
			//bool info : nNode�� ���ο� ������ ���ŵǸ� info�� true
			if (nNode == -1)
			{
				imaginaryCheck[m] = n;
				this->nNode = nNode;
				//����� imageinaryCheck ������ check�� ������ return true;
				for (int i = 0; i < 501; i++)
				{
					if (imaginaryCheck[i] != -1)
						check[i] = imaginaryCheck[i];
				}

				return true;
			}

			//�̹� m,n������ ���İ������� return
			
			//nNode�� ���� ���ŵǸ�
			//bool copy_info = info;

			//nNode��-1�� �ƴ� �����̸�, ���� �ٸ� ���� ��Ī�Ȱ��
			if (nNode != this->nNode)//(info == true)// && n != check[m])
			{ 
				imaginaryCheck[m] = n;
				this->nNode = nNode;
				startIndex[nNode]= 1; //�ٽ� 1���� ��� ������ �������� üũ�ϱ� ���ؼ�
			info = true;
			}
			else {
				info = false; startIndex[nNode]++;
			}



			int exceptedIndex = PassCheckedNode(nNode);
			for (int i = startIndex[nNode]; i <= nNum[nNode];)
		{
			//startIndex[nNode]++;
			//������ nNode�� ����Ű�� �ֿ� ���ؼ��� pass
			//check[����Ŵ ���ϴ� �� ���] = ����Ű�� �� ���
			if (arr[nNode][i] == exceptedIndex)
			{
				i++;
				continue;
			}
			return this->CheckMachingAble(arr[nNode][i], nNode,info);
			}



			//return false
			for (int i = 0; i < 501; i++)
			{
				if (imaginaryCheck[i] != -1)
					imaginaryCheck[i] = check[i];
			}

			return false;

	}

	void input_test()
	{
		//n = 3;
		//num = 4;
		//arr[1][1] = 1;
		//arr[1][2] = 3;
		//arr[2][1] = 2;
		//arr[3][1] = 2;

		//nNum[1] = 2;
		//nNum[2] = 1;
		//nNum[3] = 1;

		//n = 3;
		//num = 4;
		//arr[1][1] = 1;
		//arr[1][2] = 3;
		//arr[2][1] = 1;
		//arr[3][1] = 1;
		//nNum[1] = 2;
		//nNum[2] = 1;
		//nNum[3] = 1;
		//arrIncStartIndex[1] = 1;
		//arrIncStartIndex[2] = 1;
		//arrIncStartIndex[3] = 1;


		//n = 3;
		//num = 3;
		//arr[1][1] = 1;
		//arr[2][1] = 1;
		//arr[3][1] = 1;
		//nNum[1] = 1;
		//nNum[2] = 1;
		//nNum[3] = 1;
		//arrIncStartIndex[1] = 1;
		//arrIncStartIndex[2] = 1;
		//arrIncStartIndex[3] = 1;

		for (int i = 0; i < 501; i++)
			for (int j = 0; j < 501; j++)
			{
				arr[i][j] = 0;
			}

		n = 5;
		num = 9;
		arr[1][1] = 1;
		arr[1][2] = 2;
		arr[2][1] = 1;
		arr[3][1] = 2;
		arr[4][1] = 3;
		arr[4][2] = 4;
		arr[4][3] = 5;
		arr[5][1] = 1;
		arr[5][2] = 5;
		nNum[1] = 2;
		nNum[2] = 1;
		nNum[3] = 1;
		nNum[4] = 3;
		nNum[5] = 2;
		arrIncStartIndex[1] = 1;
		arrIncStartIndex[2] = 1;
		arrIncStartIndex[3] = 1;
		arrIncStartIndex[4] = 1;
		arrIncStartIndex[5] = 1;


		for (int i = 0; i < 501; i++)
		{
			check[i] = -1;
			imaginaryCheck[i] = -1;
			startIndex[i] = 1;
		}



		//check[1] = check[2] = check[3] = true;
		
		//���� ����
		//cin >> n;
		//������ ����
		//cin >> num;


		//vMatrix.emplace_hint
	}
	void input()
	{
		
		//���� ����
		//cin >> n;
		//������ ����
		//cin >> num;


		//vMatrix.emplace_hint
	}
	void start()
	{
		
			//arr[��� �ѹ�(��)][�׳� ������������] = ��� �ѹ�(��)�� ����Ű�� ��� �ѹ�(��) 
			/*
			arr[1][1] = 1;
			arr[1][2] = 3;
			arr[2][1] = 2;
			arr[3][1] = 2;
			*/

		input_test();//test �ڵ�

		//int count = 0;
		int inc = 1;
		for (int i = 1; i <= n; i++)
		{
		//	while (arr[i][inc] != 0)
			{
				//
				//inc = arrIncStartIndex[i];
				////arr[��� �ѹ�(��)][�׳� ������������] = ��� �ѹ�(��)�� ����Ű�� ��� �ѹ�(��) 
				////if (arr[i][inc]) {
				//	if (check[arr[i][inc]] != -1 && check[arr[i][inc]] != i)
				//	{
				//		//prenodenum = ���� arr[i][inc] ��带 ����Ű�� �ִ� �� ���
				//		int preNodeNum = arr[i][inc];
				//		check[arr[i][inc]] = i;
				//		nNum[i]--;

				//		if (nNum[preNodeNum] != 0)
				//		{
				//			i = preNodeNum;
				//			//preIndexNextStart = 
				//		}
				//		//inc++;
				//	}
				//	else if(check[arr[i][inc]] == -1){ // -1�ΰ��
				//		check[arr[i][inc]] = i; // ���ѹ�(��) ���� �������� check�ϱ�� ��.
				//		nNum[i]--;
				//		arrIncStartIndex[i] = inc + 1;
				//		continue;
				//	}
				//	else if (check[arr[i][inc]] == i) {
				//		nNum[i]--;
				//		continue;
				//	}


				inc = arrIncStartIndex[i];
				//arr[��� �ѹ�(��)][�׳� ������������] = ��� �ѹ�(��)�� ����Ű�� ��� �ѹ�(��) 
				//if (arr[i][inc]) {
					//if (check[arr[i][inc]] != -1 && check[arr[i][inc]] != i)
					//{
						//�߰� ��Ī�� �Ǵ� ��� ����, ���� ��忡 ���ؼ� �ٽ� �̺и�Ī
						if (CheckMachingAble(arr[i][inc], i,true))
						{
							//break;
						}
						//���� ������ ���� ����� ��忡 ���� Ž��
						else
						{
							inc ++;
							continue;
						}

					
					//}
				
			
			}

		}
		cout << CheckedNodeCount();
	}

	//������� ���� ��带 ������ ����� ����� ���� ����(�ּ� ���� Ƚ��, ���� output)
	int CheckedNodeCount()
	{
		static int nCount = 0;
		for (int i = 1; i <= n; i++)
			if (check[i] != -1) nCount++;
		return nCount;
	}

};

int main()
{
	cout << "test" << endl;
	STARTER STARTER;
	//STARTER.input();
	STARTER.start();
	//cout << STARTER.CheckedNodeCount() << endl;
	

    return 0;
}

