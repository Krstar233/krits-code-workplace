#include <stdio.h>
#include <string.h>
int main()
{
	int file_lon,i,x_num,n;
	char str[115];
	
	while (scanf("%d",&file_lon)!=EOF)
	{
		n=0;
		x_num=0;
		getchar();
		gets(str);
		for (i=0;i<file_lon;i++)
		{
			if (str[i]=='x')	
			{	
				x_num++;
				if (x_num>=3)	n++;
			}
			else x_num=0;
		}
		printf("%d\n",n);
	}
}
