#include <stdio.h>

int main()
{
	int t;
	int n, x, y;
	int num;
	int k = 1;
	
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &x, &y, &n);
		
		k = 0;
		x++;
		y++;
		
		for (int i = 1; i <= n; i++)
		{
			if (i % x == 0 && i % y == 0)
			{
				k = i;
				break;
			}
		}
		if (k != 0)
			printf ("%d\n",n / k * 36);
		else
			printf ("0\n");
	}
}
