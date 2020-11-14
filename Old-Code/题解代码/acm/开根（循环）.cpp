#include <stdio.h>
#include <math.h>
int main()
{
	double t,N;
	scanf("%lf",&N);
	t = N;
	while (t - N/t > 0.0001)
	{
		t = (N/t + t) / 2.0;
	}
	printf ("%.2f\n",t);
	printf ("%.2f\n",sqrt(N));
} 
