#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	int n;
	double res;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		if (n == 0)
		{
			printf ("Impossble\n");
			continue;
		}
		res = (n * n) / (2.0 * acos(-1));
		printf ("%.8f\n",res);
	}
}
