#include <stdio.h>

float fact(int n);
int main()
{
	int m, n;
	
	scanf("%d%d",&m,&n);
	printf ("%d", (int)(fact(m) / (fact(n) * fact(m - n))));
}
float fact(int n)
{
	int result = 1;
	
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
