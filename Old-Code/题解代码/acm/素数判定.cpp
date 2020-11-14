#include <stdio.h>
int is_prime (int x);

int main()
{
	int n,rst,x,y,i;//rst==result
	
	while (scanf("%d%d",&x,&y)!=EOF)
	{
		i=0;
		if (x==0&&y==0) continue;
		else if (x>=-39&&x<y&&y<=50)
		{
			for (n=x;n<=y;n++)
			{
				rst=n*n+n+41;
				if ((is_prime(rst)==1)) i++;
			}
			if (i==(y-x+1)) printf("OK\n");
			else printf("Sorry\n");
		}
	}
	return 0;
}


int is_prime (int x)
{
	int i;
	if (x<=1)	return 0;
	for (i=2;i*i<=x;i++)
		if (x%i==0) return 0;
	return 1;
}
