// Haltal.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <iostream>
using namespace std;

int main()
{
	int T = 0, N = 0, P = 0;
	cin >> T;//테스트갯수
	int count, i, inc;
	while (T-- > 0) {
		cin >> N;//기간
		cin >> P;//정당갯수
		int *h = new int[P];
		for (i = 0; i < P; i++) cin >> h[i];//각정당의 주기
		char* cycle = new char[N+1];

		for (i = 0; i < P; i++) {
			inc = 0;
			while (h[i] * ++inc <= N + 1) {
				if ((h[i] * inc) % 7 != 6 && (h[i] * inc) % 7 != 0) //금요일이나 토요일이 아니면
				{
					if (cycle[h[i] * inc] != 'x') {//x표시가 없으면
						cycle[h[i] * inc] = 'x';
					}
				}
			}
		}
		count = 0;
		for (i = 1; i < N + 1; i++) {
			if (cycle[i] == 'x') count++;
		}

		cout << count << endl;
	}
    return 0;
}

