#include <stdio.h>

int main()
{
	int num[10];
	int n = 10;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d",&num[i]);
	}
	scanf ("%d",&num[9]);
	int i = 0;
	while (i < 8 && num[i] == num[i+1] )	i++;
	if (i == 8) {}
	else if (num[i] < num[i + 1])
	{
		for (int k = n - 1; k > 0; k--)
		{
			int tmp = 0;
			if (num[k] < num[k - 1])
			{
				tmp = num[k];
				num[k] = num[k - 1];
				num[k - 1] = tmp;
			}
		}
	}
	else if (num[i] > num[i + 1])
	{
		for (int k = n - 1; k > 0; k--)
		{
			int tmp = 0;
			if (num[k] > num[k - 1])
			{
				tmp = num[k];
				num[k] = num[k - 1];
				num[k - 1] = tmp;
			}
		}
	}
	
	for (int k = 0; k < n; k++)
	{
		printf ("%d\n",num[k]);
	}
}
