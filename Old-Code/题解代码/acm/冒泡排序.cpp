#include <stdio.h>

int main()
{
	int t,n,i,j,k,tmp;
	int num[1000];
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<n-i-1;j++)
			{
				if (num[j]>num[j+1])
				{
					tmp=num[j];
					num[j]=num[j+1];
					num[j+1]=tmp;
				}
			}
			if (i==0)
			{
				for (k=0;k<n;k++)
				{
					printf ("%d",num[k]);
					if (k!=n-1) printf (" ");
				}
				printf ("\n");
			}
		}
		for (i=0;i<n;i++)
		{
			printf ("%d",num[i]);
			if (i!=n-1) printf (" ");
		}
		printf ("\n");
	}
}
