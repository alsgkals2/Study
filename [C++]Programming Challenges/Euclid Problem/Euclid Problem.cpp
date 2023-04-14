// Euclid Problem.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

long gcd(long p, long q, long *x, long *y)
{
	long x1, y1;
	long g;

	if (q > p) return (gcd(q, p, y, x));

	if (q == 0) {
		*x = 1;
		*y = 0;
		return p;
	}

	//int test = p%q;
	g = gcd(q, p%q, &x1, &y1);

	*x = y1;
	*y = (x1 - floor(p / q)*y1);

	return g;
}

int main()
{
	long a, b;
	long x, y;
	long D;
	long temp;

	while (scanf_s("%ld %ld",&a,&b) != EOF) {
		//cin >> a >> b;
		if (a == 0 && b == 0) {
			x = 0;
			y = 0;
			D = 0;
		}
		else {
			D = gcd(a, b, &x, &y);
			while (x > y) {
				--x;
				while ((D - (a*x)) % b != 0) {
					--x;
				}
				y = (D - (a*x)) / b;
			}
		}
		cout << x <<" "<< y <<" "<< D << '\n';
	}

    return 0;
}

/*
static long a, b, x, y, d;
static long r[100], k[100], xy[100][2];
static int check;

void solve(void) {

	long i;
	long x0, y0, dx, dy;

	if (a < b)
	{
		r[0] = b;
		r[1] = a;
	}
	else
	{
		r[0] = a;
		r[1] = b;
	}
	xy[0][0] = 1;
	xy[0][1] = 0;
	xy[1][0] = 0;
	xy[1][1] = 1;

	for (i = 0; r[i + 1] != 0; i++)
	{
		k[i] = r[i] / r[i + 1];
		k[i+2] = r[i] % r[i + 1];

		xy[i + 2][0] = xy[i][0] - k[i] * xy[i + 1][0];
		xy[i + 2][1] = xy[i][1] - k[i] * xy[i + 1][1];
	}

	d = r[i];
	if (a < b)
	{
		x = x0 = xy[i][1];
		y = y0 = xy[i][0];
	}
	else {
		x = x0 = xy[i][0];
		y = y0 = xy[i][1];
	}
	dx=b / d;
	dy = -a/d;

	if ((abs(x) - abs(x0 + dx)) + (abs(y) - abs(y0 + dy)) > 0 ||
		(abs(x) + abs(y) == abs(x0 + dx) + abs(y0 + dy) && x0 + dx <= y0 + dy))
	{
		x = x0 + dx;
		y = y0 + dy;
	}
	else if ((abs(x) - abs(x0 - dx)) + (abs(y) - abs(y0 - dy)) > 0 ||
		(abs(x) + abs(y) == abs(x0 - dx) + abs(y0 - dy) && x0 - dx<= y0 - dy))
	{
		x = x0 - dx;
		y = y0 - dy;
	}



}

int main(void) {

	while (scanf_s("%ld %ld", &a, &b) != EOF) {
		solve();

		printf("%ld %ld %ld\n", x, y, d);
	}


	return 0;

}*/