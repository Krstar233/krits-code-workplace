#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,k,i,j;
	int *num;
	
	scanf("%d%d",&n,&k);
	num=(int *)malloc(n*sizeof(int));
	if (num==NULL)	return 0;
	for (i=0;i<n;i++)
	{
		scanf("%d",num+i);
	}
	i=j=0;
	while (1)
	{
		if (*(num+i)<=k)
		{
			i++;
			if (i==n)	break;
		}
		else
		{
			if	(*(num+n-j-1)>k)	break;
			else
			{
				j++;	
			}
		}
	}
	printf("%d",i+j);
	free(num);
}
