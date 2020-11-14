#include <stdio.h>

int main()
{
	int t,num,i,j,k;
	char ch;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d %c",&num,&ch);
		for (i=1;i<=num;i++)
		{
			for (j=0;j<(2*num-1)-(2*i-1);j++)
				printf (" ");
			for (j=0;j<(2*i-1);j++)
				printf ("%c",ch);
			printf("\n");
		}
		printf ("\n");
	}
}
