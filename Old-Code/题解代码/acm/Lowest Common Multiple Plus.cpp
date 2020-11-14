#include <stdio.h>

int main()
{
	int n,num[100],i,t,sum,k,ok;
	
	while (scanf("%d",&n)!=EOF)
	{
		for (i=0;i<n;i++)	scanf("%d",&num[i]);
		t=0;k=1;ok=0;
		while(ok==0)
		{
			sum=num[0]*k;
			ok=1;
			for (i=0;i<n;i++)
			{
				if (sum%num[i]!=0)
				{
					ok=0;
					break;
				}
			}
			k++;
		}
		printf ("%d\n",sum);
	}
	return 0;
}

