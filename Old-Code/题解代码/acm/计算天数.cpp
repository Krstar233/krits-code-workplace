#include <stdio.h>
int DAY(int month);//�����ȥ���µ�����������2�°�30�촦�� 

int main()
{
	int year,month,day,alday;//alday==all day 
	 
	while (scanf("%d/%d/%d",&year,&month,&day)==3)
	{
		while (getchar()!='\n');
		alday=0;
		if (year%4==0&&year%100!=0)
		{
			alday=DAY(month);
			if(month<=2)
			{
				alday=alday+day;		//2�¼����¾Ͳ������ 
			}
			else
			{
				alday=alday+day-1;        //����ͼ�ȥ�����1�� 
			}
		}
		else
		{
			alday=DAY(month);
			if(month<=2)
			{
				alday=alday+day;			////2�¼����¾Ͳ������  
			}
			else
			{
				alday=alday+day-2;			//ƽ��ͼ�ȥ������� 
			}
		}
		printf("%d\n",alday);
	}
	return 0;
	
}

int DAY(int month)
{
	int add_m=0,alday=0;
    	add_m=month-1;
			for (add_m=month-1;add_m>0;add_m--)
			{
				if (add_m%2==0)
				{
					alday=alday+30;
				}
				else
				{
					alday=alday+31;
				}
			}
		return alday;
}
