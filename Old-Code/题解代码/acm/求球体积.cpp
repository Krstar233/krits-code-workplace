#include <stdio.h>
#define PI 3.1415927

int main()
{
	double r,v;
	
	while (scanf("%lf",&r)==1)
	{
		v=4.0/3.0*PI*r*r*r;
		printf("%.3lf\n",v);
		while (getchar()!='\n');
	}	
	return 0;		
} 
