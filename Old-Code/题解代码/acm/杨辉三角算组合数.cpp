#include <stdio.h>

int Cmn(int m,int n)
{
	int yanghui[100][100],i,j;
	
		for (i=0;i<n+1;i++)
		{
			for (j=0;j<=i;j++)
			{
				if (j==0||j==i)	{yanghui[i][j]=1;}
					else {yanghui[i][j]=yanghui[i-1][j]+yanghui[i-1][j-1];}
			}
		}
		return yanghui[n][m];
}
