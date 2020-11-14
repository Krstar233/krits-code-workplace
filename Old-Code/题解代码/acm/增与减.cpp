#include <stdio.h>

int main()
{
	int n,aver,sum,i,temp;
	
	while (scanf("%d",&n)!=EOF)
	{
		aver=sum=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		if (n<=2)	printf("1\n");
		else if (sum%n==0)
		{
			printf("%d\n",n);
		}
		else printf("%d\n",n-1);
	}
}

