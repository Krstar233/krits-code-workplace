#include <stdio.h>

int main ()
{
	int p,n,sn[500],i,x,k;
	
	scanf("%d%d",&n,&p);
	
	for (i=1;i<n+1;i++)
	{
		for (x=0;x<p;x++)
		{
			k=(x+i)%p;
			printf ("%d ",k);
		}
	}
} 
