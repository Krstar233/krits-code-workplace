#include <stdio.h>

int main()
{
	int t,n,times;
	
	scanf("%d",&t);
	while (t--)
	{
		times=0;
		scanf("%d",&n);
		while (n!=1)
		{
			if (n%2==1)
				n=3*n+1;
			else 	n/=2;
			times++;
		}
		printf("%d",times);
		if (t!=0)	printf(" ");
	}
}
