#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	bool last_light=0;
	scanf("%d",&n);
	if (fabs(sqrt(n)-int(sqrt(n)))<=1e-6)	last_light=1;
	if (last_light==0)	printf("no");
	if (last_light==1)	printf("yes");
}

