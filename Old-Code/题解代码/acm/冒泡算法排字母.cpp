#include <stdio.h>

int main()
{
	char ch1,ch2,ch3,ch;
	int i;
	
	while (scanf("%c%c%c",&ch1,&ch2,&ch3)==3)
	{
		i=0;
		while (i++<2)
		{
			if (ch1>ch2)
			{
				ch=ch1;
				ch1=ch2;
				ch2=ch;
			}
			if (ch2>ch3)
			{
				ch=ch2;
				ch2=ch3;
				ch3=ch;
			}
		}
		printf("%c %c %c\n",ch1,ch2,ch3);
		while (getchar()!='\n');
	}
}
