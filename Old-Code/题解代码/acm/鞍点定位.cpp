#include <stdio.h>

int check(int num[500][500], int i, int j, int n)
{
	int min = a[i][j];
	int k; 
	for (k = 0; k < n; k++)
		if (min > a[k][j])
			break;
	if (k == n)	return 1;
	else return 0;
}
int main()
{
	int t;
	int num[500][500];
	int n,m;
	
	scanf("%d",&t);
	while (t--)
	{
		int flag = 0;
		scanf("%d%d",&n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d",&num[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			int max = num[i][0];
			int max_j = 0;
			for (int j = 0; j < m; j++)
			{
				if (max < num[i][j])
				{
					max = num[i][j];
					max_j = j;
				}
			}
			if (check(num, i, max_j, n) == 1)
			{
				printf("%d %d\n",i, max_j);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf ("-1\n");
	}
}
