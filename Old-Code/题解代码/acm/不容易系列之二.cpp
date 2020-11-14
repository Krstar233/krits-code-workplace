#include <stdio.h>

int main()
{
	int n,a,i,j,sheep;
	
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a<=0||a>30)	continue;
		sheep=3;
		for (j=0;j<a;j++)
		{
			sheep=(sheep-1)*2;
		}
		printf("%d\n",sheep);
	}
}
