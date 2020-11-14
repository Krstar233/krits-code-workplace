#include <stdio.h>
#include <stdlib.h>
char *week[]={"Monday","Tuesday","Wednesday","Thursday","Firday","Saturday","Sunday"};
int main(int argc,char *argv[])
{
	if (argc!=2)
	{
		printf("error!!\n");
		exit(0);
	}
	if (*argv[1]>='1'&&*argv[1]<='7')
	{
		switch (*argv[1])
		{
			case '1':{
				printf ("%s\n",week[0]);
				break;
			}
			case '2':{
				printf ("%s\n",week[1]);
				break;
			}
			case '3':{
				printf ("%s\n",week[2]);
				break;
			}
			case '4':{
				printf ("%s\n",week[3]);
				break;
			}
			case '5':{
				printf ("%s\n",week[4]);
				break;
			}
			case '6':{
				printf ("%s\n",week[5]);
				break;
			}
			case '7':{
				printf ("%s\n",week[6]);
				break;
			}
		}
	}
	else
	{
		printf ("error!!\n");
			
	}
}
