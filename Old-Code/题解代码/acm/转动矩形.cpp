#include <stdio.h>
int max (int x,int y)
{
	if (x>y)	return x;
	else return y;
}
int min (int x,int y)
{
	if (x<y)	return x;
	else return y;
}
int main()
{
	int n,a1,b1,max_,i,tof;
	
	while (scanf("%d",&n)!=EOF)
	{
		tof=0;
		scanf("%d%d",&a1,&b1);
		max_=max(a1,b1);
		for (i=1;i<n;i++)
		{
			scanf("%d%d",&a1,&b1);
			if (max_>=max(a1,b1))
			{
				max_=max(a1,b1);
			}
			else if (max_>=min(a1,b1))
			{
				max_=min(a1,b1);
			}
			else tof=1;
		}
		if (tof==1)	printf("NO\n");
		else printf("YES\n");
	}
}
