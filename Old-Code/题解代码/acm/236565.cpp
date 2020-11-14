#include <stdio.h>
#include <string.h>
int main()
{
	int t,i,j,c[100]={0},s[100]={0},x,k;
	char ch[50][105],str[105];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
		scanf("%s",ch[i]);
	}
	for(i=0;i<t;i++)
	{
		x = 1;
		c[i]=strlen(ch[i]);
		for(j=c[i]-1;j>=0;j--)
		{
			s[i]+=('Z'-ch[i][j]+1)*x;
			x*=26;
		}
	}
	for(i=0;i<t-1;i++)
	{
		k=i;
		for(j=i+1;j<t;j++)
		{
			if(s[j]<s[k])
				k=j;
		}
		if(k!=i)
		{
			x=s[k];
			s[k]=s[i];
			s[i]=x;
			strcpy(str,ch[i]);
			strcpy(ch[i],ch[k]);
			strcpy(ch[k],str);
		}
	}
	for(i=0;i<t;i++)
	{
		printf("%s",ch[i]);
		if(i<t-1)
			printf("\n");
	}
	return 0;
}
