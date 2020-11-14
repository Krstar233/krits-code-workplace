#include <stdio.h>
#include <string.h>
#include <limits.h>
struct shows
{
	int Ti_s,Ti_e;
}c[100],*p;
int main()
{
	int time[100],n,i,j,k,temp,error,show;
	
	while (scanf("%d",&n)!=EOF)
	{
		memset (time,0,sizeof(time));
		if(!n)	break;
		for (i=0;i<n;i++)
			scanf("%d%d",&c[i].Ti_s,&c[i].Ti_e);	//输入节目单
		c[n].Ti_s=0;c[n].Ti_e=INT_MAX;show=0;	//初始化 
		//以下找出按照节目长短，从短到长选节目 
		for (i=0;i<n;i++)
		{
			//以下将最短的节目找出
			p=&c[n];
			for (j=0;j<n;j++)
			{
				if ((c[j].Ti_e-c[j].Ti_s)<(p->Ti_e-p->Ti_s)&&(c[j].Ti_e-c[j].Ti_s)!=0)
					p=&c[j];
			}
			//以下将已选的时间先检查是否冲突
			error=0;
			for (k=p->Ti_s;k<p->Ti_e;k++)
				if (time[k]!=0)	{error=1;p->Ti_s=p->Ti_e=0;break;}
			//若冲突就先把这个节目丢弃 
			if (error==1)	continue;
			//不冲突就填入日程表：
			for (;p->Ti_s<p->Ti_e;p->Ti_s++)
				time[p->Ti_s]=1;
			//运行到这里说明已经填入一个节目，立即计数 ：
			 show++;
		}
		//打印可看的节目数
		printf("%d\n",show);
	}
	return 0;
}
