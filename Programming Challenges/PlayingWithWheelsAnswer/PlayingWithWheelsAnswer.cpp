// PlayingWithWheelsAnswer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

using namespace std;
static int n;
static int s1, s2, s3, s4;
static int f1, f2, f3, f4;
static int ck[10][10][10][10];
static int sol;

void init(void)
{
	int i1, i2, i3, i4;
	for (i1 = 0; i1 < 10; i1++)
		for (i2 = 0; i2 < 10; i2++)
			for (i3 = 0; i3 < 10; i3++)
				for (i4 = 0; i4 < 10; i4++)
					ck[i1][i2][i3][i4] = 0;
}

void input(void)
{
	int i;
	int t1, t2, t3, t4;

	scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
	scanf("%d %d %d %d", &f1, &f2, &f3, &f4);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		ck[t1][t2][t3][t4] = -1;
	}
}

void bfs(void)
{
	int f, r;
	int q1[10001], q2[10001], q3[10001], q4[10001];
	int p1, p2, p3, p4;
	int p1l, p1r, p2l, p2r, p3l, p3r, p4l, p4r;
	int sck;

	f = 1;
	r = 0;
	q1[0] = s1;
	q2[0] = s2;
	q3[0] = s3;
	q4[0] = s4;

	ck[s1][s2][s3][s4] = 1;

	while (f > r && ck[f1][f2][f3][f4] == 0)
	{
		p1 = q1[r];
		p2 = q2[r];
		p3 = q3[r];
		p4 = q4[r];
		sck = ck[p1][p2][p3][p4];
		r++;

		if (p1 == 0) p1l = 9;
		else p1l = p1 - 1;
		p1r = (p1 + 1) % 10;
		if (p2 == 0) p2l = 9;
		else p2l = p2 - 1;
		p2r = (p2 + 1) % 10;
		if (p3 == 0) p3l = 9;
		else p3l = p3 - 1;
		p3r = (p3 + 1) % 10;
		if (p4 == 0) p4l = 9;
		else p4l = p4 - 1;
		p4r = (p4 + 1) % 10;

		if (ck[p1l][p2][p3][p4] == 0)
		{
			ck[p1l][p2][p3][p4] = sck + 1;
			q1[f] = p1l;
			q2[f] = p2;
			q3[f] = p3;
			q4[f] = p4;
			f++;
		}

		if (ck[p1r][p2][p3][p4] == 0)
		{
			ck[p1r][p2][p3][p4] = sck + 1;
			q1[f] = p1r;
			q2[f] = p2;
			q3[f] = p3;
			q4[f] = p4;
			f++;
		}

		if (ck[p1][p2l][p3][p4] == 0)
		{
			ck[p1][p2l][p3][p4] = sck + 1;
			q1[f] = p1;
			q2[f] = p2l;
			q3[f] = p3;
			q4[f] = p4;
			f++;
		}
		if (ck[p1][p2r][p3][p4] == 0)
		{
			ck[p1][p2r][p3][p4] = sck + 1;
			q1[f] = p1;
			q2[f] = p2r;
			q3[f] = p3;
			q4[f] = p4;
			f++;
		}
		if (ck[p1][p2][p3l][p4] == 0)
		{
			ck[p1][p2][p3l][p4] = sck + 1;
			q1[f] = p1;
			q2[f] = p2;
			q3[f] = p3l;
			q4[f] = p4;
			f++;
		}
		if (ck[p1][p2][p3r][p4] == 0)
		{
			ck[p1][p2][p3r][p4] = sck + 1;
			q1[f] = p1;
			q2[f] = p2;
			q3[f] = p3r;
			q4[f] = p4;
			f++;
		}
		if (ck[p1][p2][p3][p4l] == 0)
		{
			ck[p1][p2][p3][p4l] = sck + 1;
			q1[f] = p1;
			q2[f] = p2;
			q3[f] = p3;
			q4[f] = p4l;
			f++;
		}
		if (ck[p1][p2][p3][p4r] == 0)
		{
			ck[p1][p2][p3][p4r] = sck + 1;
			q1[f] = p1;
			q2[f] = p2;
			q3[f] = p3;
			q4[f] = p4r;
			f++;
		}

		sol = ck[f1][f2][f3][f4];
	}



}

int main()
{
	int i, t;

	scanf("%d",&t);
	for (i = 0; i < t; i++) {
		init();
		input();
		bfs();
		printf("%d\n", sol - 1);
	}


    return 0;
}

