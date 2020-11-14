#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	int num[3][100],com[100];
	int n[3];
	
	scanf("%d",&t);
	while (t--)
	{
		int i,j,k,q;
		int x;
		int flag1,flag2;
		int c_com=0;
		for (i=0;i<3;i++)
		{
			scanf ("%d",&n[i]);
			for (j=0;j<n[i];j++)
			{
				scanf ("%d",&num[i][j]);
			}
		}
		for (i=0;i<n[0];i++)
		{
			flag1=flag2=0;
			x=num[0][i];
			for (j=0;j<n[1];j++)
			{
				if (x==num[1][j])
				{
					for (q=0;q<c_com;q++)
					{
						if (x==com[q])	break;
					}
					if (q==c_com)
					{
						flag1=1;
					}
				}
			}
			for (k=0;k<n[2];k++)
			{
				if (x==num[2][k])
				{
					for (q=0;q<c_com;q++)
					{
						if (x==com[q])	break;
					}
					if (q==c_com)
					{
						flag2=1;
					}
				}
			}
			if (flag1==1&&flag2==1)
			{
				com[c_com]=x;
				c_com++;	
			}
		}
		sort(com,com+c_com);
		printf ("%d:",c_com);
		for (i=0;i<c_com;i++)
		{
			printf ("%d",com[i]);
			if (i!=c_com-1)	printf (" ");
		}
		printf ("\n");
	}
}
