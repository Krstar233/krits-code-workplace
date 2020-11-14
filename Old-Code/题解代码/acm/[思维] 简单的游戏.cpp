#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m,p,a,c,t,t_a;
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
	t=0;
	for (a=1;a<=n;a++)
	{
		p=0;
		for (c=1;c<=n;c++)
		{
			if (abs(a-c)<abs(m-c))	p++;
		}
		if (t<p)
		{
			t=p;
			t_a=a;
		}
	}
	printf ("%d\n",t_a);
	}
}
