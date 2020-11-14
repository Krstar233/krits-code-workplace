#include <stdio.h>
#include <math.h>
int jud1 (double a,double b,double c);
int jud2 (double a,double b,double c);
int main()
{
	int n;
	double a,b,c,p,area;
	
	scanf("%d",&n);
	while (n--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		if (a<b+c&&b<a+c&&c<a+b)
		{
			p=(a+b+c)/2;
			area=sqrt(p*(p-a)*(p-b)*(p-c));
			if (jud1(a,b,c)>0)
			{
				if (jud1(a,b,c)==3)	
				{
					printf ("equilateral triangle");
				}
				else if (jud2(a,b,c)==1)	printf ("isosceles right triangle");
				else printf("isosceles triangle");
			}
			else
			{
				if (jud2(a,b,c)==1)	printf ("right triangle");
				else printf ("general triangle");
			}
			printf (", %.1lf\n",area);
		}
		else printf("no triangle\n");
	}
}
int jud1 (double a,double b,double c)
{
	int num=0;
	
	if (fabs(a-b)<0.001)	num++;
	if (fabs(c-b)<0.001)	num++;
	if (fabs(a-c)<0.001)	num++;
	
	return num;
}
int jud2 (double a,double b,double c)
{
	int tof=0;
	
	if (fabs(a*a+b*b-c*c)<0.001)	tof=1;
	if (fabs(c*c+b*b-a*a)<0.001)	tof=1;
	if (fabs(a*a+c*c-b*b)<0.001)	tof=1;
	return tof;
}
