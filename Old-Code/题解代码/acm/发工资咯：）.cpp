#include <stdio.h>
int cul_rmb (int x);

int main()
{
	int n,salary[100],i,all_rmb;
	
	while  (scanf("%d",&n)!=EOF)
	{
		if (n<=0||n>=100)	continue;
		all_rmb=0;
		for (i=0;i<n;i++)	
		{
			scanf("%d",&salary[i]);
			all_rmb+=cul_rmb (salary[i]);
		}
		printf("%d\n",all_rmb);
	}
	return 0;
}

int cul_rmb (int x)
{
	int t=0,rmb100=0,rmb50=0,rmb10=0,rmb5=0,rmb2=0,rmb1=0,all_rmb=0;
	
	rmb100=x/100;t=x%100;
	rmb50=t/50;t=t%50;
	rmb10=t/10;t=t%10;
	rmb5=t/5;t=t%5;
	rmb2=t/2;
	rmb1=t%2;
	all_rmb=rmb100+rmb50+rmb10+rmb5+rmb2+rmb1;
	return all_rmb;
}
