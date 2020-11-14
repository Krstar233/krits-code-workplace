#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf ("Menu:A(dd) D(elete) S(ort) Q(uit),select one:\n");
	switch (getchar())
	{
		case 'A':{
			printf ("data is added\n");
			break;
		}
		case 'D':{
			printf ("data is deleted\n");
			break;
		}
		case 'S':{
			printf("data is sorted\n");
			break;
		}
		case 'Q':{
			exit (0);
			break;
		}
	}
}
