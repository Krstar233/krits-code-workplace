#include <stdio.h>

int main()
{
	int t;

	while (scanf("%d",&t)==1)
	{
		while (getchar()!='\n');
		if (t>=0&&t<=100)
		{
			if (t<60)
			{
				printf("E\n");
			}
			else if (t<70)
			{
				printf("D\n");
			}
			else if (t<80)
			{
				printf("C\n");
			}
			else if (t<90)
			{
				printf("B\n");
			}
			else
			{
				printf("A\n");
			}
		}
		else
		{
			printf("Score is error!\n");
		}
	}
	return 0;
}
