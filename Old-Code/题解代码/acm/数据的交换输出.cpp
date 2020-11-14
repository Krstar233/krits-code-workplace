#include <stdio.h>
#include <limits.h>

int main()
{
	int n,num[100],i,t_min,t_i,temp;//t_i save temp min's i;
	
	while (scanf("%d",&n)!=EOF)
	{
		if (n>=100||n==0)	continue;
		t_min=INT_MAX;i=t_i=temp=0;
		for (i=0;i<n;i++)	
		{
			scanf("%d",&num[i]);
			if (num[i]<t_min)
			{
				t_min=num[i];
				t_i=i;
			}
		}
		temp=num[0];
		num[0]=num[t_i];
		num[t_i]=temp;
		for (i=0;i<n-1;i++)	printf("%d ",num[i]);	
		printf("%d\n",num[n-1]);
	}
	return 0;
}
