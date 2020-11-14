#include <stdio.h>

int main()
{
	int n,num_1;
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
		while (num%n!=0)
		{
				num=num*10+1;
				num_1++;
		}
		printf ("%d\n",num_1);
	}
}
