// Haltal.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include <iostream>
using namespace std;

int main()
{
	int T = 0, N = 0, P = 0;
	cin >> T;//�׽�Ʈ����
	int count, i, inc;
	while (T-- > 0) {
		cin >> N;//�Ⱓ
		cin >> P;//���簹��
		int *h = new int[P];
		for (i = 0; i < P; i++) cin >> h[i];//�������� �ֱ�
		char* cycle = new char[N+1];

		for (i = 0; i < P; i++) {
			inc = 0;
			while (h[i] * ++inc <= N + 1) {
				if ((h[i] * inc) % 7 != 6 && (h[i] * inc) % 7 != 0) //�ݿ����̳� ������� �ƴϸ�
				{
					if (cycle[h[i] * inc] != 'x') {//xǥ�ð� ������
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

