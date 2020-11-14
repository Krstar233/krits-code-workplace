#include <stdio.h>
int Sum(int num);
int main()
{
	int n,a,b,i;
	
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);//0 <= A,B <= 600000 ;
		if (a<0||b<0||a>600000||b>600000)	continue;
		if (a==Sum(b)&&b==Sum(a))	printf ("YES\n");
			else printf("NO\n");
	}
}
int Sum(int num)
{
	int i,sum;
	sum=0;
	for (i=1;i<num;i++)
		if  (num%i==0)	sum+=i;
	return sum;
}
