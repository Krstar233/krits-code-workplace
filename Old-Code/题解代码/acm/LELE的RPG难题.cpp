#include <stdio.h>
#include <math.h>
int main()
{
	int n,i;
	long long sum;
	
	while (scanf("%d",&n)!=EOF)
	{
		if (n<=0||n>50)	continue;
		sum=3;
		if (n<3)
		{
			switch (n)
			{
				case 1:
				{
					printf("%d\n",3);
					break;
				}
				case 2:
				{
					printf("%d\n",6);
					break;
				}
			}
		}
		else
		{
			for (i=0;i<n-2;i++)
			{
				sum*=2;
			}
			printf("%lld\n",sum);
		}
	}
}
