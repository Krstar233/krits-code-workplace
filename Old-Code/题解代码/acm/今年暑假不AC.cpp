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
			scanf("%d%d",&c[i].Ti_s,&c[i].Ti_e);	//�����Ŀ��
		c[n].Ti_s=0;c[n].Ti_e=INT_MAX;show=0;	//��ʼ�� 
		//�����ҳ����ս�Ŀ���̣��Ӷ̵���ѡ��Ŀ 
		for (i=0;i<n;i++)
		{
			//���½���̵Ľ�Ŀ�ҳ�
			p=&c[n];
			for (j=0;j<n;j++)
			{
				if ((c[j].Ti_e-c[j].Ti_s)<(p->Ti_e-p->Ti_s)&&(c[j].Ti_e-c[j].Ti_s)!=0)
					p=&c[j];
			}
			//���½���ѡ��ʱ���ȼ���Ƿ��ͻ
			error=0;
			for (k=p->Ti_s;k<p->Ti_e;k++)
				if (time[k]!=0)	{error=1;p->Ti_s=p->Ti_e=0;break;}
			//����ͻ���Ȱ������Ŀ���� 
			if (error==1)	continue;
			//����ͻ�������ճ̱�
			for (;p->Ti_s<p->Ti_e;p->Ti_s++)
				time[p->Ti_s]=1;
			//���е�����˵���Ѿ�����һ����Ŀ���������� ��
			 show++;
		}
		//��ӡ�ɿ��Ľ�Ŀ��
		printf("%d\n",show);
	}
	return 0;
}
