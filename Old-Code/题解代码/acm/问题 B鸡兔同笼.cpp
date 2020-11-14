#include <stdio.h>

int main()
{
	int t,a;
	double rabbit,chook,min_result,max_result,sum;
	
	scanf ("%d",&t);
	while (t--)
	{
		min_result = 50000;
		max_result = 0;
		scanf ("%d",&a);
		for (rabbit = 0;rabbit <= a / 4.0;rabbit ++)
		{
			chook = (a - 4.0 * rabbit) / 2.0;
			sum = rabbit + chook;
			if (sum == (int)sum)
			{
				if (sum > max_result)
				{
					max_result = sum;
				}
				if (sum < min_result)
				{
					min_result = sum;
				}
			}
		}
		if (min_result == 50000 && max_result == 0) printf ("0 0\n");
		else printf ("%d %d\n",(int)min_result,(int)max_result);
	}
}
/* test data:
input: 	4
		0
		3
		9999
		10
		6666
		10000
output: 1 2
		0 0
		0 0
		0 0
		3 5
		1667 3333
		2500 5000
*/	
