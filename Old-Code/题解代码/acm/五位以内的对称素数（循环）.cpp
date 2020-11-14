#include <stdio.h>

int jud1(int n)
{
	int arrn[8],i=0,k,num=0,n1;
	
	n1=n;
	while (n!=0)
	{
		arrn[i]=n%10;
		n/=10;
		i++;
	}
	for (k=0;k<i;k++)
	{
		num+=arrn[k];
		num*=10;
	}
	num/=10;
	if (num==n1)	return 1;
	else return 0;
}
int jud2(int n)
{
	int i;
	if (n==1)	return 0;
	for (i=2;i*i<=n;i++)
	{
		if (n%i==0)	break;
	}
	if (i*i>n)
		return 1;
	else return 0;
}
int main()
{
	int t,num;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&num);
		if (jud1(num))
		{
			if (jud2(num))
				printf ("Yes\n");
			else printf ("No\n");
		}
		else printf ("No\n");
	}
}
