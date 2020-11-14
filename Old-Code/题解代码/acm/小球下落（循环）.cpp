#include <stdio.h>

int main()
{
	double m,sum=0.00;
	int n;
	
	scanf("%lf%d",&m,&n);
	while (n--)
	{
		sum+=m;
		m/=2.00;
		if (n!=0)	sum+=m;
	}
	printf("%.2f %.2f",m,sum);
}
