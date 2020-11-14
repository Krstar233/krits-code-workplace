#include <stdio.h>
#include <math.h>

int main()
{
	int m,n,i;
	double sum,n1;
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		sum=0,n1=n;
		if (n<10000&&m<1000)
		{
			for (i=0;i<m;i++)
			{
				sum+=n1;
				n1=sqrt(n1);
			}
			printf("%.2lf\n",sum);
		}
	}
	return 0;
}
