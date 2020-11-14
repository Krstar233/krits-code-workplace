#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,k,tf;
	char s[100];
	
	scanf("%d",&n);	//string number
	for (i=0;i<n;i++)
	{
		scanf("%s",s);
		tf=1;
		for (k=0;k<strlen(s)/2;k++)
		{
			if (s[k]!=s[strlen(s)-1-k])	tf=0;
		}
		if (tf==0)	printf("no\n");
			else printf("yes\n");
	}
	
}
