#include <stdio.h>

void main() {

	while (!feof(stdin))
	{
		char temp[100];
		int pencake_num = 0;
		int diameter[30];
		int i, j;
		int code;
		char* pt;

		if (!gets(temp))break;

		printf("%s\n", temp);
	
		pt = temp;
		code = 0;
		while(pt[0])
		{
			if (pt[0] >= '0' && pt[0] <= '9')
				code = code * 10 + (pt[0] - '0');
			else {
				if (code > 0) {
					diameter[pencake_num] = code;
					pencake_num++;
					code = 0;
				}
			}
			pt++;
		}
		if (code > 0) {
			diameter[pencake_num] = code;
			pencake_num++;
		}

		for (i = pencake_num - 1; i >= 1; i--) {
			int now = i;
			for (j = 0; j < i; j++)
				if (diameter[now] < diameter[j]) now = j;

			if (now < i)
			{
				if (now > 0) {
					printf("%d ", pencake_num - now);
					for (j = 0; j <= now / 2; j++) {
						int temp = diameter[j];
						diameter[j] = diameter[now - j];
						diameter[now - j] = temp;
					}
				}
				printf("%d ", pencake_num - i);
				for (j = 0; j <= i / 2; j++) {
					int temp = diameter[j];
					diameter[j] = diameter[i - j];
					diameter[i - j] = temp;
				}
			
			}
		}

			printf("0\n");
	}
}