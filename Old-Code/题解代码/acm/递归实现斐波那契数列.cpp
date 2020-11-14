#include <stdio.h>

int F(int n);
int main()
{
	int t;
	int n;
	
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", F(n));
	}
}
int F(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return F(n - 1) + F(n -  2);
}

