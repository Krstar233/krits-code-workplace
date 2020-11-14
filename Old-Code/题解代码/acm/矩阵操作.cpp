#include <stdio.h>
#include <string.h>

void show(int a[][5], int n);
void Translate(int a[][5], int n);
void Add(int a[][5], int b[][5], int n);
void Multiply(int a[][5], int b[][5], int n);
int Sum(int a[][5], int n);
int main()
{
	int n;
	int a[5][5], b[5][5];
	char cmd[40];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	while (1)
	{
		scanf("%s", cmd);
		if (strcmp(cmd, "OVER") == 0)
			break;
		if (strcmp(cmd, "TRANSLATE") == 0)
		{
			Translate(a, n);
			show(a, n);
		}
		else if (strcmp(cmd, "ADD") == 0)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					scanf("%d", &b[i][j]);
			}
			Add(a, b, n);
			show(a, n);
		}
		else if (strcmp(cmd, "MULTIPLY") == 0)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					scanf("%d", &b[i][j]);
			}
			Multiply(a, b, n);
			show(a, n);
		}
		else if (strcmp(cmd, "SUM") == 0)
		{
			printf ("%d\n", Sum(a, n));
		}
	}
}
void show(int a[][5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf ("%d", a[i][j]);
			if (j != n - 1)
				printf (" ");
		}
		printf ("\n");
	}
}
void Translate(int a[][5], int n)
{
	int b[5][5];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = a[j][i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
void Add(int a[][5], int b[][5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] += b[i][j];
		}
	}
}
void Multiply(int a[][5], int b[][5], int n)
{
	int c[5][5] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int r = 0; r < n; r++)
			{
				c[i][j] += a[i][r] * b[r][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = c[i][j];
		}
	}
}
int Sum(int a[][5], int n)
{
	int sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || i == n - j - 1)
				sum += a[i][j];
		}
	}
	return sum;
}
