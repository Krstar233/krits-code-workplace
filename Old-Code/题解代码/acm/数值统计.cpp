#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,up_n,down_n,zero;
	float num[100];
	
	while (scanf("%d",&n)!=EOF)
	{
		up_n=down_n=zero=0;
		if (n>0&&n<=100)
		{
		for (i=0;i<n;i++)
		{
			scanf("%f",&num[i]);
			if (num[i]>0)
				up_n++;
			else if (num[i]<0)
				down_n++;
			else zero++;
		}
		printf("%d %d %d\n",down_n,zero,up_n);
		}
		else if (n==0);
	}
	return 0;
}
