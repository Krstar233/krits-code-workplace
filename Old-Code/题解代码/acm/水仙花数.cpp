#include <stdio.h>

int main()
{
	int m,n,i,fnum,ge,shi,bai;
	
	while (scanf("%d%d",&m,&n)!=EOF)
	{
		fnum=0;
		if (m>=100&&m<=n&&n<=999)
		{
			for (i=m;i<=n;i++)
			{
				bai=i/100,shi=i%100/10,ge=i%100%10;
				if (i==(bai*bai*bai+shi*shi*shi+ge*ge*ge))
				{
					fnum++;
					if (fnum==1) printf("%d",i);
					else printf(" %d",i);
				}
			}
			if (fnum!=0) printf("\n");
			else printf("no\n");
		}
	}
	return 0;
}
