#include <stdio.h>

int main()
{
	long long n,result;
	
	scanf("%lld",&n);
	if (n<=3)
	{
		switch (n)
		{
			case 1:result = 1; break;
			case 2:result = 2; break;
			case 3:result = 6; break;
		}
	}
	else if (n%2==1)
	{
		result = n*(n-1)*(n-2);
	}
	else if (n%3==0)
	{
		result = (n-1)*(n-2)*(n-3);
	}
	else
	{
		result = n*(n-1)*(n-3);
	}
	printf("%lld",result);
}
