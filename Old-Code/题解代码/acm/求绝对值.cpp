#include <stdio.h>

int main()
{
	double i;
	
	while (scanf("%lf",&i)!=EOF)
	{
		while (getchar()!='\n');
		if (i<0)
		{
			i=-i;
		}
		printf("%.2lf\n",i);
	}
	return 0;
}
