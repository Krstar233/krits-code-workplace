#include <stdio.h>
#include <string.h>

int main()
{
	int n,m,score[50][5],i,j,temp,good;
	double sum_n[50],sum_m[5];
	
	/*1.��ÿ��ѧ��ƽ���ɼ�  	ok
	  2.��ÿ��ƽ���ɼ�			ok
	  3.����ѧ��				ok	
	  4.���					ok	*/ 
	while (scanf("%d%d",&n,&m)!=EOF)	
	{
		if (n<=0||n>50||m<=0||m>5)	{printf("\n");	continue;}
		memset (sum_n,0,sizeof(sum_n));
		memset (sum_m,0,sizeof(sum_m));
		memset (score,0,sizeof(score));
		temp=0;good=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				scanf("%d",&score[i][j]);
				sum_n[i]+=score[i][j];		//�����ѧ�����ܳɼ� 
			}
		}
		for (j=0;j<m;j++)		//������Ƶ��ܳɼ� 
		{
			for (i=0;i<n;i++) 
			{
				sum_m[j]+=score[i][j];	 
			}
		}
		for (i=0;i<n;i++) 
		{
			temp=0;
			for (j=0;j<m;j++)
			{
				if (score[i][j]>=(sum_m[j]/n))	temp++;	//sum_m[j]/n�Ƕ�Ӧ��Ŀ��ȫ��ƽ���ɼ� 
			}
			if (temp==m)	good++;
		}
		for (i=0;i<n-1;i++)		printf("%.2lf ",sum_n[i]/m);	printf("%.2lf\n",sum_n[n-1]/m);	//�����ѧ��ƽ���ɼ� 
		for (i=0;i<m-1;i++)		printf("%.2lf ",sum_m[i]/n);	printf("%.2lf\n",sum_m[m-1]/n);	//�������Ŀƽ���ɼ� 
		printf("%d\n\n",good);	//�������ѧ���ĸ��� 
	}
	return 0;
}
