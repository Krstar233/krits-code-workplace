#include <stdio.h>
#include <string.h>
int main ()
{
	char sen[100];
	int i;
	
	while (gets(sen)!=NULL)
	{
		if (sen[0]>='a'&&sen[0]<='z')	sen[0]-=32;
		for (i=0;sen[i+1]!='\0';i++)
		{
			if (sen[i]==' ')
			{
				if (sen[i+1]>='a'&&sen[i+1]<='z')	sen[i+1]-=32;
			}
		}
		puts(sen);
	}
}
