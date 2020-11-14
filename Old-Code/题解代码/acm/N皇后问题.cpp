#include <stdio.h>

int Queen(int n);
int check(int x[], int i, int n);
int putQueen(int x[], int i, int n, int &sum);
int check(int x[], int i, int n);
int Abs(int x);

int main()
{
	int n;
	
	while(1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		else if (n == 1)
			printf ("1\n");
		else 
			printf ("%d\n", Queen(n));
	}
}

int Queen(int n)
{
	int sum = 0;
	int x[15];
	
	putQueen(x, 0, n, sum);
	return sum;
}

int putQueen(int x[], int i, int n, int &sum)
{
	for (int k = 0; k < n; k++)
	{
		if (check(x, i, k))
		{
			x[i] = k;
			if (i + 1 < n)
				putQueen(x, i + 1, n, sum);
			else
				sum++;
		}
	}
}

int check(int x[], int i, int n)
{
	for (int k = 0; k < i; k++)
	{
		if (n == x[k])
			return 0;
		if (Abs(n - x[k]) == Abs(i - k))
			return 0;
	}
	return 1;
}

int Abs(int x)
{
	if (x >= 0)
		return x;
	else
		return -x;	
} 

