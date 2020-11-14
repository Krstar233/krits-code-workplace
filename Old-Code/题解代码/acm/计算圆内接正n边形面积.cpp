#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main()
{
	double r,s;
	int n;
	
	scanf("%lf,%d",&r,&n);
	s=n*r*r*sin(2*PI/n)/2.0;
	printf("Area=%.2f",s);
} 
