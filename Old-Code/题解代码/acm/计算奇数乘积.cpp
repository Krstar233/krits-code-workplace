#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,k,plus;
	int a[50],b[50];//a==enter num,b==right num
	
	while (scanf("%d",&n)!=EOF)
	{
		k=0,plus=1;
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]%2!=0)
			{
				b[k]=a[i];
				k++;
			}
		}
		for (i=0;i<k;i++)
		{
			plus=plus*b[i];
		}
		printf("%d\n",plus);
		memset (a,0,sizeof(a));
		memset (b,0,sizeof(b));		
	}
	return 0;
}
