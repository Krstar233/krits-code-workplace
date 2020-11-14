#include <stdio.h>
#include <math.h>
int main()
{
	int score[500][500],m,n,i,j,k,a,t_max,max[100],x[100],y[100];
	
	while (scanf("%d%d",&m,&n)!=EOF)
	{
		if (m==0&&n==0)	continue;
		for (t_max=0,j=0;j<m;j++)
		{
			for (i=0;i<n;i++)
			{
				scanf("%d",&score[j][i]);
				if (t_max<abs (score[j][i]))	t_max=abs(score[j][i]);	
			}
		}
		k=0;
		for (j=0;j<m;j++)
		{
			for (i=0;i<n;i++)
			{
				if (t_max==abs (score[j][i]))
				{
					max[k]=score[j][i];
					x[k]=i+1;
					y[k]=j+1;
					k++;
				}
			}
		}
			printf("%d %d %d\n",y[0],x[0],max[0]);
	}
	return 0;
}
