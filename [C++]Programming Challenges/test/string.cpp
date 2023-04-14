#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

const int ARRAYMAXNUM = 21;
static bool checking[ARRAYMAXNUM] = { false };
static int lastFriend[ARRAYMAXNUM] = { 0 };//[��������] = ������ģ����ȣ
static int FriendOfUsers[ARRAYMAXNUM][ARRAYMAXNUM] = { 0 };
int numOfPeople = 0;

void InitChecking()
{
	for (int i = 0; i <= numOfPeople; i++)
	{
		checking[i] = false;
	}
}
//
//void ForTest()
//{
//	//[0][n]�� ģ�� �� ��
//
//	FriendOfUsers[1][0] = 2;
//	FriendOfUsers[2][0] = 2;
//	FriendOfUsers[3][0] = 1;
//	FriendOfUsers[4][0] = 2;
//	FriendOfUsers[5][0] = 3;
//
//	FriendOfUsers[1][1] = 4;
//	FriendOfUsers[1][2] = 5;
//
//	FriendOfUsers[2][1] = 3;
//	FriendOfUsers[2][2] = 5;
//
//	FriendOfUsers[3][1] = 2;
//
//	FriendOfUsers[4][1] = 1;
//	FriendOfUsers[4][2] = 5;
//
//	FriendOfUsers[5][1] = 1;
//	FriendOfUsers[5][2] = 2;
//	FriendOfUsers[5][3] = 4;
//}
//void ForTest2()
//{
//	FriendOfUsers[1][0] = 4;
//	FriendOfUsers[2][0] = 4;
//	FriendOfUsers[3][0] = 4;
//	FriendOfUsers[4][0] = 4;
//	FriendOfUsers[5][0] = 4;
//
//	FriendOfUsers[1][1] = 2;
//	FriendOfUsers[1][2] = 3;
//	FriendOfUsers[1][3] = 4;
//	FriendOfUsers[1][4] = 5;
//
//	FriendOfUsers[2][1] = 1;
//	FriendOfUsers[2][2] = 3;
//	FriendOfUsers[2][3] = 4;
//	FriendOfUsers[2][4] = 5;
//
//	FriendOfUsers[3][1] = 1;
//	FriendOfUsers[3][2] = 2;
//	FriendOfUsers[3][3] = 4;
//	FriendOfUsers[3][4] = 5;
//
//	FriendOfUsers[4][1] = 1;
//	FriendOfUsers[4][2] = 2;
//	FriendOfUsers[4][3] = 3;
//	FriendOfUsers[4][4] = 5;
//
//	FriendOfUsers[5][1] = 1;
//	FriendOfUsers[5][2] = 2;
//	FriendOfUsers[5][3] = 3;
//	FriendOfUsers[5][4] = 4;
//
//}
void Input()
{
	for (int i = 1; i <= numOfPeople; i++) {
		cin >> FriendOfUsers[i][0];

		for (int j = 1; j <= FriendOfUsers[i][0]; j++) {
			cin >> FriendOfUsers[i][j];
		}
	}
}

int SearchCheckingArr()
{
	for (int i = 1; i <= ARRAYMAXNUM; i++) {
		if (checking[i] == false) {
			return i;
		}
	}
	return 0;
}


int main() {
	//���� ª�� �Ÿ� Ž��
	//BFS �˰���
	
	int repeat;
	cin >> repeat;

	for (int re = 0; re < repeat; re++) {

		cin >> numOfPeople;
		Input();

		int calPeopleNum = 0;
		int output = 100;
		int localOutput = 0;
		int firstFriendNum = 0;
		int localCount = 0;
		InitChecking();
		bool firstFriendNumSwitch = false;

		for (int i = 1; i <= numOfPeople; i++) { //1���� n���� ȸ���鿡 ���� ��� Ž������
			InitChecking();
			queue<int> friendQ;
			calPeopleNum = 0;
			firstFriendNum = i;
			localOutput = 0;
			localCount = 1;
			firstFriendNumSwitch = false;
			checking[i] = true;
			bool sw = false;

			friendQ.push(i);
			int currentFriend = 0;
			//i�� ģ������ bfs������� Ž��
			while (localCount != numOfPeople)
			{
				if (friendQ.empty()) {
					currentFriend=SearchCheckingArr();
					sw = false;
					firstFriendNum = currentFriend;
					localCount++;
				}
				else {
					currentFriend = friendQ.front();
					friendQ.pop();
				}
				
				bool localOutPutSwitch = false;
				if (currentFriend == firstFriendNum) {
					localOutput++;
					firstFriendNumSwitch = false;
					if (localOutput >= output)
						break;
				}

				int friendNum = FriendOfUsers[currentFriend][0];

				int currentI = 1;
				for (currentI = 1; currentI <= friendNum; currentI++)
				{
					int index = FriendOfUsers[currentFriend][currentI];
					if (checking[index] == false) {
						checking[index] = true;
						localOutPutSwitch = true;
						
						if (firstFriendNumSwitch == false)
						{
							firstFriendNum = index;
							firstFriendNumSwitch = true;
							
						}
						friendQ.push(index);
						localCount++;
					}
				}

				//���̻� ���ο� ģ���� ���°��
				if (sw ==false && currentI == friendNum&& firstFriendNumSwitch == false)
				{
					sw = true;
					localOutput--;
				}

				if (localCount == numOfPeople)
				{
					if (localOutput < output) output = localOutput;
					break;
				}
			
			}


		}
		cout << output << endl;

	}
	return 0;
}