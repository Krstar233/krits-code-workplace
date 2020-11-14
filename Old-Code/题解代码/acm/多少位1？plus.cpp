#include <stdio.h>

int main()
{
	int n,i,num_1,yu;
	long long num;

	while (scanf("%d",&n)!=EOF)
	{
		num=1;
		num_1=1;
		while (num<n)
		{
			num=num*10+1;
			num_1++;
		}
		yu=num;
		while (yu!=0)
		{
			yu=yu%n;
			while (yu<n&&yu!=0)
			{
				yu=yu*10+1;
				num_1++;
			}
		}
		printf ("%d\n",num_1);
	}
}
