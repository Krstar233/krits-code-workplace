#include <stdio.h>

int main()
{
	int m,n;
	int a[10][10];
	
	scanf ("%d%d",&n,&m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d",&a[i][j]);	
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf ("%d",a[j][i]);
			if (j != n - 1)
				printf (" ");
		}
		printf ("\n");
	}
} 
