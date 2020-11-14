#include <stdio.h>

int main ()
{
	int num [10];
	int i,t,sum;
	
	scanf ("%d", &t);
	while (t --)
	{
		sum = 0;
		for (i = 0; i < 10; i ++)
		{
			scanf ("%d", &num[i]);
			if (num[i] < 0) sum ++;
		}	
		printf ("%d\n", sum);
	}
	
}
