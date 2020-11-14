#include <stdio.h>

int main()
{
	int arr[10],i,t,search;
	
	scanf ("%d",&t);
	while (t--)
	{
		for (i = 0;i < 10;i ++)
			scanf ("%d",&arr[i]);
		scanf ("%d",&search);
		for (i = 0;i < 10;i ++)
			if (search == arr[i])	break;
		if (i == 10)	printf ("Not found\n");
		else printf ("%d\n",i);
	}
}
/*test data:
input:	3
		1 2 3 4 5 6 7 8 9 10
		2
		1 2 3 4 5 6 -8 -7 -6 -5
		8
		1 2 3 6 6 6 6 6 5 6
		6
		
output:	1	
		Not found
		3	
*/
