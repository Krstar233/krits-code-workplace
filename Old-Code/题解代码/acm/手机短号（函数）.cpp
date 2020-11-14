#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int change(char longnum[], char shortnum[]);
int main()
{
	int t;
	char longnum[15], shortnum[10];
	int flag;

	scanf("%d", &t);
	getchar();
	while (t--)
	{
		gets(longnum);
		flag = change(longnum, shortnum);
		if (flag)
			puts(shortnum);
		else
			printf ("error\n");
	}
}

int change(char longnum[], char shortnum[])
{
	int head = 0;
	int flag = 0;

	if (strlen(longnum) == 11)
	{
		for (int i = 0; i < 3; i++)
		{
			head *= 10;
			head += longnum[i] - '0';
		}
		if (head == 133 || head == 153 || head == 180 || head == 181 || head == 189)
			flag = 1;
		else if (head == 130 || head == 131 || head == 132 || head == 155 || head == 156)
			flag = 1;
		else if (head == 134 || head == 135 || head == 136 || head == 137 || head == 138 || head == 182 || head == 183 || head == 184)
			flag = 1;
		if (flag == 1)
		{
			shortnum[0] = '6';
			for (int i = 1; i <= 5; i++)
			{
				shortnum[i] = longnum[5 + i];
			}
			shortnum[6] = '\0';
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}
