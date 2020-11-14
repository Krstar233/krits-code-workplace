#include <stdio.h>

int main()
{
	char **p;
	char *name[]={"abcsa","defs","ghl"};
	
	p=name+1;
	printf("%s\n",*p);
}
