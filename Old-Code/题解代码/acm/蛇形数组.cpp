#include <stdio.h>
#define X 15	//X是 行数 
#define Y 20	//Y是 列数 
int main()
{
	int num[X][Y]={0};
	int i,j,n,space;
	
	space=X*Y;
	i=0;
	j=Y-1;
	n=1;
	while (space!=0)
	{
		while (i<X&&num[i][j]==0)
		{
			num[i][j]=n;
			space--;
			n++;
			i++;
		}
		j--;
		i--;
		while (j>=0&&num[i][j]==0)
		{
			num[i][j]=n;
			space--;
			n++;
			j--;	
		}
		j++;
		i--;
		while (i>=0&&num[i][j]==0)
		{
			num[i][j]=n;
			space--;
			n++;
			i--;
		}
		i++;
		j++;
		while (j<Y&&num[i][j]==0)
		{
			num[i][j]=n;
			space--;
			n++;
			j++;
		}
		j--;
		i++;
	}
	for (i=0;i<X;i++)
	{
		for (j=0;j<Y;j++)
		{
			printf ("%5d",num[i][j]);	
		}
		printf ("\n\n");	
	}
}
