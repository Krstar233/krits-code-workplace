#include <stdio.h>

int main()
{
	int t,num;
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&num);
		if (num % 6 == 0)	printf ("Yes\n");
		else if (num >= 100000 && num < 1000000)	printf ("Yes\n");
		else if (num % 10 == 6)	printf ("Yes\n");
		else printf ("No\n");
	}
}
