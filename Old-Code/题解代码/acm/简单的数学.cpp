#include <stdio.h>
#include <math.h>
int main()
{
	double a,num,i,tof;
	int n;
	
	while (scanf("%d",&n)!=EOF)
	{
		tof=0;
		for (i=0;i<n;i++)
		{
			scanf("%lf",&num);
			num=sqrt(num);
			a=(int)num;
			if (a!=num)	tof=1;
		}
		if (tof==1)	printf("No\n");
		else printf("Yes\n");
	}
}
