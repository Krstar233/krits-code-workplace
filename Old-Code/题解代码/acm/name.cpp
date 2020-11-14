#include <stdio.h>
#include <string.h>
int main (void)
{
	int fnum,lnum;
	char fname[20],lname[20];
	
	printf("Please input your name:");
	scanf("%s",fname);
	scanf("%s",lname);
	printf("You name is:\n");
	printf("%s %s\n",fname,lname);
	fnum=strlen(fname);
	lnum=strlen(lname);
	printf("%*d %*d",fnum,fnum,lnum,lnum);	
	return 0;
}
