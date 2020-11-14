#include <stdio.h>
#include <math.h>
int isPrime_3(long long num )
{
	long long i;
	
	for (i=2;i*i<=num;i++)
	{
		if (num%i==0)	break;
	}
	if (i*i>num)	return 1;
	else return 0;
}
int main()
{
	long long a,b,l;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		if (a-b==1)
		{
			l=a+b;
			if(isPrime_3(l)==1)	printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
}
