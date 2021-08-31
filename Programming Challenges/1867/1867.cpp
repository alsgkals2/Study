// 1867.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
//#include <vector>
//#include <map>
//#include <array>
using namespace std;

class STARTER{
public:
	//n : 격자 n x n
	//num :돌맹이 갯수
	int n, num;
	//vector<int> vMatrix;
	//multimap<int, int> mMatrix;
	//map<int, int> vMatrix;
	int arr[501][501];
	int nNum[501];
	//check[가리킴 당하는 행 노드] = 가리키는 열 노드
	int check[501];
	int imaginaryCheck[501];
	int arrIncStartIndex[501];
	int arr_excludedIndex[591];
	int iSetNum;
	bool bExcutedIndex[501];
	int nNode;
	int startIndex[501];

	//기존의 check에 저장된 노드는 index를 탐색하여 pass한다.
	//return index
	//check[가리킴 당하는 행 노드] = 가리키는 열 노드
	int PassCheckedNode(int nNode)
	{
		for (int i = 1; i <= 501; i++)
		{
			if (check[i] == nNode)
				return i;

		}

		return -1;

	}

	//5가 5와 매칭해야한다.
	bool CheckMachingAble(int m,int n,bool info) //m:가리킴 당하는 노드 n:가리키는 노드
												 //bool info : nNode가 새로운 정보로 갱신되면 info가 true
	{
		//if(bExcutedIndex)
		//bExcutedIndex[n] = true;


			//static int i = 1;


			//check[가리킴 당하는 행 노드] = 가리키는 열 노드
			int nNode = imaginaryCheck[m];
			//bool info : nNode가 새로운 정보로 갱신되면 info가 true
			if (nNode == -1)
			{
				imaginaryCheck[m] = n;
				this->nNode = nNode;
				//변경된 imageinaryCheck 정보만 check로 복사후 return true;
				for (int i = 0; i < 501; i++)
				{
					if (imaginaryCheck[i] != -1)
						check[i] = imaginaryCheck[i];
				}

				return true;
			}

			//이미 m,n정보를 거쳐갔었으면 return
			
			//nNode가 새로 갱신되면
			//bool copy_info = info;

			//nNode가-1은 아닌 상태이며, 새로 다른 노드와 매칭된경우
			if (nNode != this->nNode)//(info == true)// && n != check[m])
			{ 
				imaginaryCheck[m] = n;
				this->nNode = nNode;
				startIndex[nNode]= 1; //다시 1부터 노드 갱신이 가능한지 체크하기 위해서
			info = true;
			}
			else {
				info = false; startIndex[nNode]++;
			}



			int exceptedIndex = PassCheckedNode(nNode);
			for (int i = startIndex[nNode]; i <= nNum[nNode];)
		{
			//startIndex[nNode]++;
			//기존에 nNode가 가리키는 애에 대해서는 pass
			//check[가리킴 당하는 행 노드] = 가리키는 열 노드
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
		
		//격자 갯수
		//cin >> n;
		//돌맹이 갯수
		//cin >> num;


		//vMatrix.emplace_hint
	}
	void input()
	{
		
		//격자 갯수
		//cin >> n;
		//돌맹이 갯수
		//cin >> num;


		//vMatrix.emplace_hint
	}
	void start()
	{
		
			//arr[노드 넘버(행)][그냥 오름차순으로] = 노드 넘버(행)이 가리키는 노드 넘버(열) 
			/*
			arr[1][1] = 1;
			arr[1][2] = 3;
			arr[2][1] = 2;
			arr[3][1] = 2;
			*/

		input_test();//test 코드

		//int count = 0;
		int inc = 1;
		for (int i = 1; i <= n; i++)
		{
		//	while (arr[i][inc] != 0)
			{
				//
				//inc = arrIncStartIndex[i];
				////arr[노드 넘버(행)][그냥 오름차순으로] = 노드 넘버(행)이 가리키는 노드 넘버(열) 
				////if (arr[i][inc]) {
				//	if (check[arr[i][inc]] != -1 && check[arr[i][inc]] != i)
				//	{
				//		//prenodenum = 기존 arr[i][inc] 노드를 가리키고 있던 행 노드
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
				//	else if(check[arr[i][inc]] == -1){ // -1인경우
				//		check[arr[i][inc]] = i; // 노드넘버(열) 갯수 기준으로 check하기로 함.
				//		nNum[i]--;
				//		arrIncStartIndex[i] = inc + 1;
				//		continue;
				//	}
				//	else if (check[arr[i][inc]] == i) {
				//		nNum[i]--;
				//		continue;
				//	}


				inc = arrIncStartIndex[i];
				//arr[노드 넘버(행)][그냥 오름차순으로] = 노드 넘버(행)이 가리키는 노드 넘버(열) 
				//if (arr[i][inc]) {
					//if (check[arr[i][inc]] != -1 && check[arr[i][inc]] != i)
					//{
						//추가 매칭이 되는 경우 갱신, 다음 노드에 대해서 다시 이분매칭
						if (CheckMachingAble(arr[i][inc], i,true))
						{
							//break;
						}
						//되지 않으면 다음 연결된 노드에 대해 탐색
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

	//연결되지 않은 노드를 제외한 연결된 노드의 갯수 리턴(최소 직진 횟수, 최종 output)
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

