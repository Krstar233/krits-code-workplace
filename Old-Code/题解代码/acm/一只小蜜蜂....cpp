#include <stdio.h>
long long Cmn(int m,int n);
int main()
{
	int n,a,b,i,num,num_1,num_2;
	long long sum;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		if (a>=b||a<=0||a>=50||b<=0||b>=50)	continue;
		num=b-a;
		sum=0;
		for (num_2=0;num_2<=num/2;num_2++)
		{
			num_1=num-num_2*2;
			sum+=Cmn (num_1,num_1+num_2);
		}
		printf("%lld\n",sum);
	}
}
long long Cmn(int m,int n)
{
	long long yanghui[100][100],i,j;
	
		for (i=0;i<n+1;i++)
		{
			for (j=0;j<=i;j++)
			{
				if (j==0||j==i)	{yanghui[i][j]=1;}
					else {yanghui[i][j]=yanghui[i-1][j]+yanghui[i-1][j-1];}
			}
		}
	return yanghui[n][m];
}
