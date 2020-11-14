#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copy(char strs[][505], int n, int x, int l, char s[]);
void add(char s1[], char s2[], char s[]);
int find(char strs[][505], char s[], int n);
int rfind(char strs[][505], char s[], int n);
void insert(char strs[][505], char s[], int n, int x);
void reset(char strs[][505], char s[], int n);

int main()
{
	int N;
	int n, x, l;
	char s1[505], s2[505], s[505];
	char cmd[20];
	char strs[25][505];
	int i;

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
			copy(strs, n - 1, x, l, s);
			puts(s);
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
			printf("%d\n", find(strs, s, n - 1));
		}
		else if (strcmp(cmd, "rfind") == 0)
		{
			scanf("%s %d", s, &n);
			printf("%d\n", rfind(strs, s, n - 1));
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
			reset(strs, s, n - 1);
			puts(strs[n - 1]);
		}
		else if (strcmp(cmd, "over") == 0)
			exit(0);
	}
}

void copy(char strs[][505], int n, int x, int l, char s[])
{
	strncpy(s, strs[n] + x, l);
	s[l] = '\0';
}

void add(char s1[], char s2[], char s[])
{
	int flag = 1;
	int i;
	int n1 = 0, n2 = 0, n = 0;
	int t_str[505];

	for (i = 0; i < strlen(s1); i++)
	{
		if (!(s1[i] >= '0' && s1[i] <= '9'))
			break;
	}
	if (i < strlen(s1))
		flag = 0;
	for (i = 0; i < strlen(s2); i++)
	{
		if (!(s2[i] >= '0' && s2[i] <= '9'))
			break;
	}
	if (i < strlen(s2))
		flag = 0;
	if (flag)
	{
		for (i = 0; i < strlen(s1); i++)
		{
			n1 *= 10;
			n1 += s1[i] - '0';
		}
		for (i = 0; i < strlen(s2); i++)
		{
			n2 *= 10;
			n2 += s2[i] - '0';
		}
		if (n1 < 0 || n1 > 99999)
			flag = 0;
		else if (n2 < 0 || n2 > 99999)
			flag = 0;
	}
	if (flag)
	{
		n = n1 + n2;
		i = 0;
		if (n == 0)
		{
			s[0] = '0';
			s[1] = '\0';
			return;
		}
		while (n != 0)
		{
			t_str[i] = n % 10 + '0';
			n /= 10;
			i++;
		}
		for (int j = 0; j < i; j++)
		{
			s[j] = t_str[i - j - 1];
		}
		s[i] = '\0';
	}
	else
	{
		for (i = 0; i <= strlen(s1); i++)
		{
			s[i] = s1[i];
		}
		strcat(s, s2);
	}
}

int find(char strs[][505], char s[], int n)
{
	int s_length = strlen(s);
	char str[505];
	int str_length;
	int flag = 0;
	int i, j;

	strcpy(str, strs[n]);
	str_length = strlen(str);
	for (i = 0; i < str_length; i++)
	{
		if (str[i] == s[0])
		{
			for (j = 0; j < s_length; j++)
			{
				if (str[i + j] != s[j])
					break;
			}
			if (j == s_length)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag)
		return i;
	else
		return str_length;
}

int rfind(char strs[][505], char s[], int n)
{
	int s_length = strlen(s);
	char str[505];
	int str_length;
	int flag = 0;
	int i, j;

	strcpy(str, strs[n]);
	str_length = strlen(str);
	for (i = str_length - 1; i >= 0; i--)
	{
		if (str[i] == s[0])
		{
			for (j = 0; j < s_length; j++)
			{
				if (str[i + j] != s[j])
					break;
			}
			if (j == s_length)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag)
		return i;
	else
		return str_length;
}

void insert(char strs[][505], char s[], int n, int x)
{
	char str[505];
	int str_length, s_length = strlen(s);
	int i;

	strcpy(str, strs[n]);
	str_length = strlen(str);

	for (i = str_length + s_length; i >= x + s_length; i--)
	{
		str[i] = str[i - s_length];
	}
	for (i = 0; i < s_length; i++)
	{
		str[x + i] = s[i];
	}
	strcpy(strs[n], str);
}

void reset(char strs[][505], char s[], int n)
{
	strcpy(strs[n], s);
}
