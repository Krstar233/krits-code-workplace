#include <stdio.h>
int arr[1000];
int main()
{
	int n,i,k;
	
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]%2==0)	arr[i]--;
		printf("%d",arr[i]);
		if(i!=n-1)	printf(" ");
	}
}
