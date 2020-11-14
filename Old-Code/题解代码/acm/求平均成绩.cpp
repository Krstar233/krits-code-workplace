#include <stdio.h>
#include <string.h>

int main()
{
	int n,m,score[50][5],i,j,temp,good;
	double sum_n[50],sum_m[5];
	
	/*1.求每个学生平均成绩  	ok
	  2.求每科平均成绩			ok
	  3.划分学生				ok	
	  4.输出					ok	*/ 
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
				sum_n[i]+=score[i][j];		//计算各学生的总成绩 
			}
		}
		for (j=0;j<m;j++)		//计算各科的总成绩 
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
				if (score[i][j]>=(sum_m[j]/n))	temp++;	//sum_m[j]/n是对应科目的全班平均成绩 
			}
			if (temp==m)	good++;
		}
		for (i=0;i<n-1;i++)		printf("%.2lf ",sum_n[i]/m);	printf("%.2lf\n",sum_n[n-1]/m);	//输出各学生平均成绩 
		for (i=0;i<m-1;i++)		printf("%.2lf ",sum_m[i]/n);	printf("%.2lf\n",sum_m[m-1]/n);	//输出各科目平均成绩 
		printf("%d\n\n",good);	//输出优秀学生的个数 
	}
	return 0;
}
