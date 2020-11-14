#include <stdio.h>

int main()
{
	int a[6],b[8];
	int i,j;
	
	for (i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	for (i=0;i<8;i++)
	{
		scanf("%d",&b[i]);
	}
	for (i=0;i<6;i++)
	{
		for (j=0;j<8;j++)
		{
			if (a[i]==b[j])
			{
				printf ("%d\n",a[i]);
			}
		}
	}
}
