#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,k,ch_long[100]={0},num[100]={0};
	char ch[100][100]={0};
	
	while (scanf("%d",&n)!=EOF)
	{
		if (n>100||n<=0)	continue;
		memset(num,0,sizeof(num));
		memset(ch_long,0,sizeof(ch_long));
		memset(ch,0,sizeof(ch));
		k=0;
		for (i=0;i<n;i++)
		{
			scanf("%s",ch[i]);
			ch_long[i]=strlen(ch[i]);
			printf("i=%d\n",i);
			for(k=0;k<ch_long[i];k++);
			{ 
				printf("i=%d	k=%d\n",i,k);
				printf("%c\n",ch[i][k]);
				if (ch[i][k]>=48&&ch[i][k]<=57)
					num[i]++;
			}
		}
		for (i=0;i<n;i++)	printf("%d\n",num[i]);
	}
	return 0;
}
