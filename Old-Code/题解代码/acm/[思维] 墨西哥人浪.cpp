#include <stdio.h>

int main()
{
	int n,k,t,stand,i;
	
	scanf("%d%d%d",&n,&k,&t);
	stand=-1;
	if (t<=k)
	{	
		for (i=0;i<=t;i++)	stand++;
	}
	else if (t>n)
	{	
		stand=k;
		for (i=0;i<t-n;i++)	stand--;
	}
	else stand=k;
	printf("%d",stand);
}
