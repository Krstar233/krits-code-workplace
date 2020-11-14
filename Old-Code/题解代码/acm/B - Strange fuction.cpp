#include <stdio.h>

double F(double x,double y)
{
	double x2,x3,x6,x7,fx;
	
	x2=x*x;
	x3=x2*x;
	x6=x3*x3;
	x7=x6*x;
	fx=6.0*x7+8.0*x6+7.0*x3+5.0*x2-y*x;
	return fx;
}
int main()
{
	int t;
	double y,fx,min;
	double left,right,midl,midr;
	
	scanf("%d",&t);
	while (t--)
	{
		left=0;
		right=100;
		scanf("%lf",&y);
		
		while (right-left>1e-6)
		{
			midl=(right+left)/2;
			midr=(midl+right)/2;
			if (F(midl,y)>F(midr,y))	left=midl;
			else right=midr;
		}
		printf ("%.4f\n",F(left,y));
	}
}
