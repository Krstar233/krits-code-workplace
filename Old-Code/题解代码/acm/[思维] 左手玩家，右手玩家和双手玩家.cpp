#include <stdio.h>

int main()
{
	int a,b,c,halfstudent;
	
	scanf("%d%d%d",&a,&b,&c);
	if (a>b)
	{
		b+=c;
		if (b-a>0)
		{
			c=b-a;
			halfstudent=c/2+a;
		}
		else
		{
			halfstudent=b;
		}
	}
	else
	{
		a+=c;
		if (a-b>0)
		{
			c=a-b;
			halfstudent=c/2+b;
		}
		else
		{
			halfstudent=a;
		}
	}
	printf ("%d",2*halfstudent);
 } 
