#include <stdio.h>
int Cmn (int m,int n);

int main()
{
	int num_2,num_1,num,i,n,sum,t;
	
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&num);
		sum=0;num--;
		for (num_2=0;num_2<=num/2;num_2++)
		{
			num_1=num-num_2*2;
			sum+=Cmn (num_1,num_1+num_2);
		}
		printf("%d\n",sum);
	}
}

int Cmn(int m,int n)
{
	int yanghui[100][100],i,j;
	
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
