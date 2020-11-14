#include <stdio.h>
int DAY(int month);//计算除去当月的总天数并且2月按30天处理 

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
				alday=alday+day;		//2月及以下就不会多算 
			}
			else
			{
				alday=alday+day-1;        //闰年就减去多算的1天 
			}
		}
		else
		{
			alday=DAY(month);
			if(month<=2)
			{
				alday=alday+day;			////2月及以下就不会多算  
			}
			else
			{
				alday=alday+day-2;			//平年就减去多算的天 
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
