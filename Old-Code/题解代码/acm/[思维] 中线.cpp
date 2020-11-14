#include <stdio.h>
#include <math.h>
int main()
{
	double A,B,C,a,b,c,p,S;
	
	while (scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
	A=sqrt(8.0*b*b/9.0+8*c*c/9.0-4.0*a*a/9.0);
	B=sqrt(8.0*a*a/9.0+8*c*c/9.0-4.0*b*b/9.0);
	C=sqrt(8.0*b*b/9.0+8*a*a/9.0-4.0*c*c/9.0);
	p=(A+B+C)/2.0;
	S=sqrt(p*(p-A)*(p-B)*(p-C));
	if (S>0&&fabs(S-0)>1e-6)	printf("%.3lf\n",S);
		else printf("%d\n",-1);
	}
}
