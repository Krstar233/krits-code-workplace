#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m,a;
	
	scanf("%d%d",&n,&m);
	if (n==1&&m==1)
	{
		a=1;
		printf ("%d",a);
		exit(0);
	}
	if (m>n/2)	a=m-1;
		else	a=m+1;
	printf ("%d",a);
}
