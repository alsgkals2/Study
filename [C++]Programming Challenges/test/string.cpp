#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

const int ARRAYMAXNUM = 21;
static bool checking[ARRAYMAXNUM] = { false };
static int lastFriend[ARRAYMAXNUM] = { 0 };//[현재유저] = 마지막친구번호
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
//	//[0][n]은 친구 명 수
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
	//가장 짧은 거리 탐색
	//BFS 알고리즘
	
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

		for (int i = 1; i <= numOfPeople; i++) { //1에서 n까지 회원들에 대해 모두 탐색시작
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
			//i의 친구들을 bfs방식으로 탐색
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

				//더이상 새로운 친구가 없는경우
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