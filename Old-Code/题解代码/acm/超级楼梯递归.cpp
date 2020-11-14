#include <stdio.h>
int a(int n)
{
	if(n==1||n==2)	return 1;
	else	 return a(n-1)+a(n-2);
}
int main()
{
	int n,i,m;
	
	scanf("%d",&m);
	for (i=0;i<m;i++)
	{
		scanf("%d",&n);
		printf("%d\n",a(n));
	}
}
