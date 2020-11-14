#include <stdio.h>

int main()
{
	int m,n,p,i,x,y,k,j,l,r[100],o,ms;
	
	scanf("%d%d%d",&n,&m,&p);
	if (n<1||m<1||p>100)	return 0;
	if (m%p==0||n%p==0)	{	printf ("Yes\n");	i=m*n/p;}
		else printf ("No\n");
	if (m%p==0)
	{
		x=m/p;ms=0;
		for (k=0;k<n;k++)
		{
			for (j=0;j<x;j++)
			{
				ms++;
				for (l=0;l<p;l++)
				{
					printf ("%d",ms);
					if (j!=x)	printf(" ");		//*important
				}
			}
			printf("\n");
		}
		return 0;
	}
	if (n%p==0)
	{
		y=n/p;ms=0;r[0]=0;
		for (k=0;k<y;k++)
		{
			
			for (l=0;l<p;l++)
			{
				ms=r[k];
				for (j=0;j<m;j++)
				{
					ms++;
					printf ("%d",ms);
					if (j!=m-1)	printf(" ");
				}
				r[k+1]=ms;
				printf("\n");
			}
		}
	}
}
