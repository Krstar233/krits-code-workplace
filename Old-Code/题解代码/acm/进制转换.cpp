#include <stdio.h>

int main()
{
	int n,r,mo[100],quo,i;//quo==quotients
	
	while (scanf("%d%d",&n,&r)!=EOF)
	{
		if (r>16||r<2||r==10)	continue;
		i=0;
			if (n<0)	{quo=-n;printf ("-");}
				else quo=n;
		while (quo!=0)
		{
			mo[i]=quo%r;
			quo=quo/r;
			i++;
		}
		while (i--)
		{
			switch (mo[i])
			{
				case 10:
				{
					printf("A");
					break;
				}
				case 11:
				{
					printf("B");
					break;
				}
				case 12:
				{
					printf("C");
					break;
				}
				case 13:
				{
					printf("D");
					break;
				}
				case 14:
				{
					printf("E");
					break;
				}
				case 15:
				{
					printf("F");
					break;
				}
				default:
					printf("%d",mo[i]);
			}
		}
		printf("\n");
	}
}
