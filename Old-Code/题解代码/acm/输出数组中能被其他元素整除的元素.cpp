#include <stdio.h>

int main ()
{
	int num [20];
	int i, j;
	
	for (i = 0; i < 20; i ++)
	{
		scanf ("%d", &num[i]);
	}
	for (i = 0; i < 20; i ++)
	{
		for (j = 0; j < 20; j ++)
		{
			if (i != j)	
			{
				if (num [i] % num [j] == 0)
				{
					printf ("%d\n", num [i]);
					break;
				}
			}
		}
	}
}
