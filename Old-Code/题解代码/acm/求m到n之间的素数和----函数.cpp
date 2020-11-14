#include <stdio.h>

int isprime(int n);
int main()
{
	int m, n;
	int sum = 0;
	
	scanf("%d%d",&m, &n);
	
	for (int i = m; i <= n; i++)
	{
		if (isprime(i))
		{
			sum += i;
		}
	}
	printf ("%d",sum);
}
int isprime(int n)
{
	int i;
	if (n == 1 || n == 0)
		return 0;
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
