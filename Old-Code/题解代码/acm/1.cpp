#include <stdio.h>
#include <string.h>

int main()
{
	char ch1[10]="ABC";
	char ch2[10]="ABC";
	int k;
	
	strcat(ch1,ch2);
	printf("strcat(ch1,ch2)=%s**********%d",ch1,strlen(ch1));
	
	return 0;
}
