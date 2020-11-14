#include <stdio.h>
#include <string.h>
int main()
{
	int n,i;
	char a[31],b[31],s1[62];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a);
		scanf("%s",b);
		b[0]=b[0]-('a'-'A');
		strcpy(s1,b);
		strcat(s1,a);
		printf("%s\n",s1);
	}
} 
