#include <stdio.h>
#include <math.h>

int main()
{
	int t,n,m,i,j,num;
	double x,y,r,dis;
	
	scanf("%d",&t);
	while (t--)
	{
		num=0;
		scanf("%d%d",&n,&m);
		scanf("%lf%lf%lf",&x,&y,&r);
		for (i=0;i<=m;i++)
		{
			for (j=0;j<=n;j++)
			{
				dis = sqrt((i-x)*(i-x)+(j-y)*(j-y));
				if (dis<r||fabs(dis-r)<1e-6)
					num++;
			}
		}
		printf ("%d\n",num);
	}
}
