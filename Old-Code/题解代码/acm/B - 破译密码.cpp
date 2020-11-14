#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char start[20]={0},end[20],password[201],lon,i;
	
	while (strcmp(start,"ENDOFINPUT")!=0)
	{
		gets(start);
		if (strcmp(start,"START")==0)
		{
			gets(password);
			lon=strlen(password);
			for (i=0;i<lon;i++)
			{
				if (password[i]>'E'&&password[i]>='A'&&password[i]<='Z')
				{
					password[i]-=5;
				}
				else if (password[i]>='A'&&password[i]<='Z')
				{
					password[i]='Z'-('A'-(password[i]-4));
				}
				else continue;
			}
			gets(end);
			puts(password);
		}
	}
}
