#include <stdio.h>
int judtri(double a,double b,double c);
int main()
{
	int n,i,tof;
	double a,b,c;
	
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		tof=judtri(a,b,c);
		if (tof==0)	printf("NO\n");
		if (tof==1)	printf("YES\n");
	}
}
int judtri(double a,double b,double c)
{
	if (a<b+c&&b<a+c&&c<a+b)	return 1;
		else return 0;
}
