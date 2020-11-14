#include <stdio.h>

int main()
{
	int an[100];
	int n,m,i,k,j,t_sum;
	
	for (i=0;i<100;i++)	an[i]=2*(i+1);
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		if (m>n)	continue;
		k=0;j=0;t_sum=0;
		for (i=n/m;i>0;i--)
		{
			for (k=0;k<m;k++)
			{
				t_sum+=an[j];
				j++;
			}
			if (i==1&&n%m==0) printf("%d",t_sum/m);
			else printf("%d ",t_sum/m);
			t_sum=0;
		}
		if (n%m==0) printf("\n");
		else
		{
		for (i=n-(n/m)*m;i>0;i--)
		{
			t_sum+=an[j];
			j++;
		}
			printf("%d\n",t_sum/(n-(n/m)*m));
		}
	}
	return 0;	
} 
