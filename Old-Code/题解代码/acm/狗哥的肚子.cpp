#include <stdio.h>
#define PI 3.14159
int main ()
{
	int t,n,i,a,b;
	double s, max_s;
	char trc;
	
	scanf ("%d", &t);
	while (t --)
	{
		max_s = 0;
		scanf ("%d", &n);
		getchar ();
		for (i = 0; i < n; i ++)
		{
			scanf ("%c",&trc);
			if (trc == 'T')
			{
				scanf ("%d%d",&a,&b);
				s = (a * b) / 2.0;
			}
			else if (trc == 'R')
			{
				scanf ("%d%d",&a,&b);
				s = a * b;	
			}
			else if (trc == 'C')
			{
				scanf ("%d",&a);
				s = a * a * PI;
			}
			if (max_s < s)	max_s = s;
			while (getchar () != '\n');
		}
		printf ("%.2f\n", max_s);
	}
}
