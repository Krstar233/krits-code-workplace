#include <stdio.h>
#include <math.h>

int main()
{
	int n[100]={0},m,i;
	double sum[100]={0.00},k;
	
	scanf("%d",&m);
	if (m<100)
	{
	for (i=0;i<m;i++)
	{
		scanf("%d",&n[i]);
		for (k=0;k<n[i];k++)
		{
			sum[i]+=(1.0/(k+1.0))*pow(-1,k);
	    }
	}
	for (i=0;i<m;i++)	printf("%.2lf\n",sum[i]);
	}
	return 0;
}
