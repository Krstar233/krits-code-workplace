#include <stdio.h>

int main()
{
	int m,n,temp,x,y,i;
	
	while (scanf("%d%d",&m,&n)!=EOF)
	{
		temp=x=y=0;
		if (m>n)
		{
			temp=m;
			m=n;
			n=temp;
		}
		for (i=m;i<=n;i++)
		{
			if (i%2==0)
				x+=i*i;
			else if (i%2==1)
				y+=i*i*i;
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}
