// Packaging.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#define MAX_N 1000
#define _int64 long long

using namespace std;

int main()
{
	while (1) {
		int n;
		int i;
		int present_down = 0, present_up = 0;
		int num[MAX_N][3];
		int up_candidate_1 = -1, up_candidate_2 = -1,
			down_candidate_1 = -1, down_candidate_2 = -1;

		scanf_s("%d", &n);

		if (n == 0) break;

		for (i = 0; i < n; i++)
			scanf_s("%d %d %d", &num[i][0], &num[i][1], &num[i][2]);

		for (i = 0; i < n; i++)
		{
			if (num[i][0] == num[i][1])
				if (num[i][2] > num[i][0])
					present_up = 1;
				else
					present_down = 1;
		}

		for (i = 0; i < n; i++)
		{
			int diff_2 = num[i][1] - num[i][0];
			int diff_3 = num[i][2] - num[i][0];
			if (diff_2 > 0)
			{
				int comp_diff_2, comp_diff_3;

				if (up_candidate_1 == -1)
					up_candidate_1 = i;
				else
				{
					comp_diff_2 = num[up_candidate_1][1] - num[up_candidate_1][0];
					comp_diff_3 = num[up_candidate_1][2] - num[up_candidate_1][0];
				
					if (diff_3 * (_int64)comp_diff_2 > (_int64)diff_2 * comp_diff_3) up_candidate_1 = i;
				}

				if (up_candidate_2 == -1)
					up_candidate_2 = i;
				else
				{
					comp_diff_2 = num[up_candidate_2][1] - num[up_candidate_2][0];
					comp_diff_3 = num[up_candidate_2][2] - num[up_candidate_2][0];

					if (diff_3 * (_int64)comp_diff_2 < (_int64)diff_2 * comp_diff_3) up_candidate_2 = i;
				}
			}

			else if (diff_2 < 0) {
				int comp_diff_2, comp_diff_3;

				if (down_candidate_1 == -1) down_candidate_1 = i;
				else
				{
					comp_diff_2 = num[down_candidate_1][1] - num[down_candidate_1][0];
					comp_diff_3 = num[down_candidate_1][2] - num[down_candidate_1][0];

					if (diff_3 * (_int64)(-comp_diff_2) > (_int64)(-diff_2) * comp_diff_3) down_candidate_1 = i;
				}

				if (down_candidate_2 == -1) down_candidate_2 = i;
				else
				{
					comp_diff_2 = num[down_candidate_1][1] - num[down_candidate_1][0];
					comp_diff_3 = num[down_candidate_1][2] - num[down_candidate_1][0];

					if (diff_3 * (_int64)(-comp_diff_2) < (_int64)(-diff_2) * comp_diff_3) down_candidate_2 = i;
				}
			}
		}

		if (up_candidate_1 >= 0 && down_candidate_1 >= 0) {
			int diff_1_2, diff_1_3, diff_2_2, diff_2_3;
			_int64 temp1, temp2;

			diff_1_2 = num[up_candidate_1][1] - num[up_candidate_1][0];
			diff_1_3 = num[up_candidate_1][2] - num[up_candidate_1][0];
			diff_2_2 = num[down_candidate_1][1] - num[down_candidate_1][0];
			diff_2_3 = num[down_candidate_1][2] - num[down_candidate_1][0];

			temp1 = (_int64)diff_1_3 * (-diff_2_2);
			temp2 = (_int64)(-diff_1_2) * diff_2_3;

			if (temp1 >= temp2)
				present_up = 1;
			if (temp1 <= temp2)
				present_down = 1;

			diff_1_2 = num[up_candidate_2][1] - num[up_candidate_2][0];
			diff_1_3 = num[up_candidate_2][2] - num[up_candidate_2][0];
			diff_2_2 = num[down_candidate_2][1] - num[down_candidate_2][0];
			diff_2_3 = num[down_candidate_2][2] - num[down_candidate_2][0];

			temp1 = (_int64)diff_1_3 * (-diff_2_2);
			temp2 = (_int64)(-diff_1_2) * diff_2_3;

			if (temp1 >= temp2)
				present_up = 1;
			if (temp1 <= temp2)
				present_down = 1;
		}

		if (present_up && present_down) printf("Yes\n");
		else printf("No\n");

	}
    return 0;
}