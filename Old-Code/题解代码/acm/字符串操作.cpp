#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add(char s1[], char s2[], char s[]);
void insert(char strs[][505], char s[], int n, int x);

int main()
{
	int N;
	int n, x, l;
	char s1[505], s2[505], s[505];
	char cmd[20];
	char strs[25][505];
	int i;
	char *p, *np;

	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++)
	{
		gets(strs[i]);
	}
	while (1)
	{
		scanf("%s", cmd);

		if (strcmp(cmd, "copy") == 0)
		{
			scanf("%d %d %d", &n, &x, &l);
			strncpy(s, strs[n - 1] + x, l);
			s[l] = '\0';
			puts(s);
			strcpy(s, strs[n - 1] + x + l);
			strs[n-1][x] = '\0';
			strcat(strs[n-1], s);
		}
		else if (strcmp(cmd, "add") == 0)
		{
			scanf("%s %s", s1, s2);
			add(s1, s2, s);
			puts(s);
		}
		else if (strcmp(cmd, "find") == 0)
		{
			scanf("%s %d", s, &n);
			if (strstr(strs[n - 1], s) != NULL)
				printf("%d\n", strstr(strs[n - 1], s) - strs[n - 1]);
			else
				printf("%d\n", strlen(strs[n - 1]));
		}
		else if (strcmp(cmd, "rfind") == 0)
		{
			scanf("%s %d", s, &n);
			p = strs[n - 1] - 1;
			np = NULL;
			while ((p = strstr(p + 1, s)) != NULL)
				np = p;
			if (np != NULL)
				printf("%d\n", np - strs[n - 1]);
			else
				printf("%d\n", strlen(strs[n - 1]));
		}
		else if (strcmp(cmd, "insert") == 0)
		{
			scanf("%s %d %d", s, &n, &x);
			insert(strs, s, n - 1, x);
			puts(strs[n - 1]);
		}
		else if (strcmp(cmd, "reset") == 0)
		{
			scanf("%s %d", s, &n);
			strcpy(strs[n - 1], s);
			puts(strs[n - 1]);
		}
		else if (strcmp(cmd, "over") == 0)
			exit(0);
	}
}
 
void add(char s1[], char s2[], char s[])
{
	int flag = 1;
	int i;
	int n1 = 0, n2 = 0, n = 0;

	for (i = 0; i < strlen(s1); i++)
	{
		if (!(s1[i] >= '0' && s1[i] <= '9'))
		{
			flag = 0;
			break;
		}
	}
	for (i = 0; i < strlen(s2); i++)
	{
		if (!(s2[i] >= '0' && s2[i] <= '9'))
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		n1 = atoi(s1);
		n2 = atoi(s2);
		if (n1 < 0 || n1 > 99999)
			flag = 0;
		if (n2 < 0 || n2 > 99999)
			flag = 0;
	}
	if (flag)
	{
		n = n1 + n2;	
		sprintf(s, "%d", n);
	}
	else
	{
		strcpy(s, s1);
		strcat(s, s2);
	}
}

void insert(char strs[][505], char s[], int n, int x)
{
	char str[505];
	
	strncpy(str, strs[n], x);
	str[x] = '\0';
	strcat(str, s);
	strcat(str, strs[n] + x);
	strcpy(strs[n], str);
}

