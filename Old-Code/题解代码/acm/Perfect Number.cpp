#include <stdio.h>

int result=10;
int jud (int num)
{
	int sum=0;

	while (num)
	{
		sum+=num%10;
		num/=10;
	}
	if (sum%10==0)	return 1;
	else return 0;
}
void cul(int k)
{
	int other=0,i;
	for (i=0;i<k;)
	{
		result+=9;
		if (jud(result))	i++;
	}
}
int main()
{
	int k;
	
	scanf("%d",&k);
	cul(k);
	printf("%d",result);
}
