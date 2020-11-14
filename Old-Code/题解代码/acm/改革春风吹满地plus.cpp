#include <stdio.h>
struct FUN
{
	int x,y;
}c[105];
int main()
{
	int n,i;
	double sum;
	while (scanf("%d",&n)!=EOF)
	{
		if(!n)	break;
		for (i=0;i<n;i++)
			scanf("%d%d",&c[i].x ,&c[i].y );
		c[n].x=c[0].x;c[n].y=c[0].y;
		
		sum=0;
		for (i=0;i<n;i++)
			sum+=0.5*(c[i].x*c[i+1].y-c[i+1].x*c[i].y);
		printf("%.1f\n",sum);
	}
	return 0;
}
