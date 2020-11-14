#include <stdio.h>
#include <string.h>
#include <math.h>
long change(char s[]);
int change2(char ch);
int main()
{
	int n;
	long changed_num;
	char s[100];
	
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		gets(s);
		changed_num = change(s);
		printf ("%ld\n", changed_num);
	}
}

long change(char s[])
{
	int x;
	int s_length = strlen(s);
	long sum = 0;
	
	for (int i = 0; i < s_length; i++)
	{
		x = change2(s[s_length - i - 1]);
		if (x != -1)
			sum += x * pow(16, i);
		else
			sum *= -1;
	}
	return sum;
}

int change2(char ch)
{
	int n;
	if (ch >= '0' && ch <= '9')
	{
		n = ch - '0';
		return n;
	}
	else if (ch >= 'A' && ch <= 'F')
	{
		n = ch - 'A' + 10;
		return n;
	}
	else 
		return -1;
}
