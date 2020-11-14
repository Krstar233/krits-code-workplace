#include <stdio.h>

int main()
{
	int n,m,num[101],i,temp;
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		if ((n==0&&m==0)||n>100||n<0)	continue;
		for (i=0;i<n;i++)	scanf("%d",&num[i]);
		for (i=n,num[n]=m;i>0;i--)
		{
			if (num[i]<num[i-1])	temp=num[i],num[i]=num[i-1],num[i-1]=temp;
		}
		for (i=0;i<n;i++)	printf("%d ",num[i]);
		printf("%d\n",num[n]);
	}
	return 0;
}
