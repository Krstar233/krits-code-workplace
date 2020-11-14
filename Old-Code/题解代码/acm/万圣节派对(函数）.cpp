#include <stdio.h>
#define N 6

void apart(char num[], int n);
int check1(char num[]);
int check2(char num[]);
int check3(char num[]);
int Abs(int x);

int main()
{
	char num[10];
	int n;
	int num1, num2;
	
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d",&num1, &num2);
		for (int i = num1; i <= num2; i++)
		{ 
			if (i < 0)
				continue;
			if (i > 666666)
				break; 
			apart(num, i);
			if (check1(num) && check2(num) && check3(num))
				puts(num);
		}
		if (n != 0)	printf ("\n");
	}
}

void apart(char num[], int n)
{
	for (int i = N - 1; i >= 0; i--)
	{
		num[i] = n % 10 + '0';
		n /= 10;
	}
	num[N] = '\0';
}

int check1(char num[])
{
	for (int i = 0; i < N; i++)
	{
		if (i >= 2 && num[i] == num[i - 2])
			if (num[i] == num[i - 1])
				return 0;
	} 
	return 1;
}

int check2(char num[])
{
	for (int i = 1; i < N; i++)
	{
		if (Abs(num[i] - num[i - 1]) > 4)
			return 0;
	}
	return 1;
}

int check3(char num[])
{
	for (int i = 0; i < N; i++)
	{
		if (num[i] > '6')
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
