#include <stdio.h>
int factorial(int x);
int main()
{
	int n,i,k,Cm,Cn,result;
	
	while (scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			Cn=factorial(i);
			for (k=0;k<=i;k++)
			{
				Cm=factorial(k);
				result=Cn/(Cm*(factorial(i-k)));
				printf("%d",result);
				if (k!=i)	printf(" ");
			}
			printf("\n");
		}
	}
}
int factorial(int t)
{
	int result=1;
	if (t==0)	return 1;
	while (t>0)
	{
		result*=t;
		t--;
	}
	return result;		
}
