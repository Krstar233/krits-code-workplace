#include <stdio.h>
int MIN(int x,int y)
{
	if (x<y)	return x;
	else return y;
}
int main()
{
	int n,a,b,c,meter,times;
	
	scanf ("%d%d%d%d",&n,&a,&b,&c);
	if (n==1)	printf ("0");
	else printf("%d",MIN(a,b)+MIN(a,MIN(b,c))*(n-2));
}
