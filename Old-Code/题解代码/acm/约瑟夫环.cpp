#include <stdio.h>

int main()
{
	int n;
	int num;
	bool flag[500] = {0};
	int i = 0;
	int sum = 0;
	
	scanf("%d",&n);
	num = n;
	while (1)
	{
		sum++;
		if (num == 1)	
			break;
		if (sum % 3 == 0)
		{
			flag[i] = 1;
			num--;
			printf ("%d ",i + 1);
		}
		i++;
		if (i == n) i = 0;
		while (flag[i] != 0)
		{
			i++;
			if (i == n)	
			{
				i = 0;
			}
		}
	}
	printf ("\n%d",i + 1);
}
