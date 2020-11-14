#include <stdio.h>
int main()
{
	int t, n, res;
	scanf("%d",&t);
	
	while (t--)
	{
		scanf("%d",&n);
		while (n != 1)
		{
			if (n % 2 == 0)
			{
				res = n / 2;
				printf ("%d/2=%d\n",n, res);
				n = res;
			}
			else
			{
				res = n * 3 + 1;
				printf ("%d*3+1=%d\n",n, res);
				n = res;
			}
		}
		if (t != 0)	printf ("\n");
	}
}
