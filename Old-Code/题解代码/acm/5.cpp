#include <stdio.h>

int main()
{
	int year,month,day,alday;
	int normon[]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	while (scanf("%d/%d/%d",&year,&month,&day)!=EOF)
	{
		alday=0;
		for (--month;month>0;--month)
		{
			alday=alday+normon[month-1];
		}
		alday=alday+day;
		if ((year%4==0&&year%100!=0)||year%400==0)
			alday++;
		printf("%d\n",alday);
	}
	return 0;	
} 
