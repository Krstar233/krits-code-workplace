#include <stdio.h>
int yanghui (int m,int n);
int main()
{
	int m,i,n;
	while (scanf("%d",&m)!=EOF)
	{
		for (i=1;i<=m;i++)
		{
			for (n=1;n<=i;n++)
			{
				printf("%d",yanghui(i,n));
				if (n!=i)	printf(" ");
			}
			printf ("\n");
		}
	}
}
int yanghui (int m,int n)
{
	int t;
	if (m==1||m==2)	return 1;
	if (n>1&&n<m)	t=yanghui(m-1,n)+yanghui(m-1,n-1);
		else t=1;
	return t;
}
