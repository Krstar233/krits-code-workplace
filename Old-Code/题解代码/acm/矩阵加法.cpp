#include <stdio.h>

int main()
{
	int n,m;
	int i,j;
	int a[15][15],b[15][15],c[15][15];
	
	scanf ("%d%d",&n,&m);
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			scanf ("%d",&a[i][j]);
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			scanf ("%d",&b[i][j]);
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
			printf ("%d",c[i][j]);
			if (j!=m-1)	printf (" ");
		}
		printf ("\n");
	}
	
}
