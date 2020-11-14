#include <stdio.h>
#include <math.h>

int main()
{
	int i,j,n,t,num[100];
	
	while (scanf("%d",&n)!=EOF)
	{
		if (n<=0||n>100)	continue;
		for (i=0;i<n;i++)
			scanf("%d",&num[i]);	
		for (i=0;i<n;i++)
		{
			for (j=0;j<n-1;j++)
			{
				if ( abs (num[j]) < abs (num[j+1]) )	t=num[j],num[j]=num[j+1],num[j+1]=t;
			}
		}
		for (i=0;i<n-1;i++)		printf("%d ",num[i]);	printf("%d\n",num[n-1]);	
	}	
	return 0;
} 
