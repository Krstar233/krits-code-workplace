#include <stdio.h>

int main()
{
	double a;
	
	scanf("%lf",&a);
	if (a<0)	a=-a;
	printf("%.2f",a);
}
