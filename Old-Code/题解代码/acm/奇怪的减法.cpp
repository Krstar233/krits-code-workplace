#include <stdio.h>
void F(long long *a,long long *b)
{
	if (*a==0||*b==0)	return;
	else if (*a>*b*4)
	{
		*a=*a%(2*(*b))+2*(*b);
		F(a,b);
	}
	else if (*b>*a*4)
	{
		*b=*b%(2*(*a))+2*(*a);
		F(a,b);
	}
	else if (*a>=(*b)*2)
	{
		*a=*a-(*b)*2;
		F(a,b);
	}
	else if (*b>=(*a)*2)
	{
		*b=*b-(*a)*2;
		F(a,b);
	}
	else return;
}
int main()
{
	long long m,n;
	
	while (scanf("%lld%lld",&n,&m)!=EOF)
	{
		if (n==0||m==0)
		{
			printf ("%lld %lld\n",n,m);
			continue;
		}
		F(&n,&m);
		printf ("%lld %lld\n",n,m);
	}
}
