#include <stdio.h>

int main()
{
	int t;
	int num[500][500];
	
	scanf("%d",&t);
	while (t--)
	{
		int n;
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		int tmp;
		int flag = 0;
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d",&num[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			sum1 = 0;
			for (int j = 0; j < n; j++)
			{
				sum1 += num[i][j];
			}
			if (i == 0)	tmp = sum1;
			else if (tmp != sum1)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			printf ("NO\n");
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			sum2 = 0;
			for (int i = 0; i < n; i++)
			{
				sum2 += num[i][j];
			}
			if (j == 0)	tmp = sum2;
			else if (tmp != sum2)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			printf ("NO\n");
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			sum3 += num[i][i];
			sum4 += num[i][n - i - 1];
		}
		if (sum3 != sum4)	flag = 1;
		else if (!(sum1 == sum2 && sum1 == sum3))
			flag = 1;
		if (flag == 1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}
