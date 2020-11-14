#include <stdio.h>
#include <string.h>
void change (char *a,char *b);
int reorder (char str[],int lon);
int main()
{
	int lon,i,n;
	char str[101];
	
	scanf("%d\n",&lon);
	gets(str);
	reorder(str,lon);
	puts(str);
}
void change (char *a,char *b)
{
	char temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
}
int reorder (char str[],int lon)
{
	int i;
	if (lon==1)	return 0;
	else
	{
		reorder (str,lon/2);
		for (i=0;i<lon/2;i++)
		{
			change(&str[i],&str[lon-i-1]);
		}
	}
}
