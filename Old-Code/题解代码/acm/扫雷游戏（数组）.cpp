#include <stdio.h>

int main()
{
	int n,m;
	char a[105][105];
	
	while (scanf("%d%d",&n, &m) != EOF)
	{
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = getchar();
			}
			getchar();
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != '*')
				{
					a[i][j] = '0';
					if (i - 1 >= 0 && a[i - 1][j] == '*')
						a[i][j]++;
					if (i + 1 < n && a[i + 1][j] == '*')
						a[i][j]++;
					if (j - 1 >= 0 && a[i][j - 1] == '*')
						a[i][j]++;
					if (j + 1 < m && a[i][j + 1] == '*')
						a[i][j]++;
					if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == '*')
						a[i][j]++;
					if (i - 1 >= 0 && j + 1 < m && a[i - 1][j + 1] == '*')
						a[i][j]++;
					if (i + 1 < n && j - 1 >= 0 && a[i + 1][j - 1] == '*')
						a[i][j]++;
					if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '*')
						a[i][j]++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf ("%c",a[i][j]);
			}
			printf ("\n");
		}
	}
}
