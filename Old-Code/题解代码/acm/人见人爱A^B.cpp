#include <stdio.h>

int main()
{
	int a,b,t;
	
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0&&b==0)	break;
		t=a=a%1000;
		while (--b)
		{
			t*=a;
			t=t%1000;
		}
		printf("%d\n",t);
	}
}
