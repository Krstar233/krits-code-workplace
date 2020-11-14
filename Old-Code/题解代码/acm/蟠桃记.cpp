#include <stdio.h>

int main()
{
	int n,sum;
	
	while (scanf("%d",&n)!=EOF)
	{
		if (n>1&&n<30)
		{
			sum=1;
			for(n--;n>0;n--)
			{
				sum=(sum+1)*2;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
