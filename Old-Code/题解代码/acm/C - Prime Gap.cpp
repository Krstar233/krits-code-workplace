#include <stdio.h>
#include <math.h>
int is_prime (int num)
{
	int i;
	double m;
	
	m = sqrt((double)num);
	if (num == 0||num == 1)	return 0;
	for (i=2;i<=m;i++)
	{
		if (num%i == 0)	break;
	}
	if (i>m)	return 1;
	else return 0;
}
int main()
{
	int left,right,gap;
	int k;
	
	while (1)
	{
		scanf("%d",&k);
		if (k == 0)	break;
		left = right = k;
		while (is_prime(left) == 0)
		{
			left--;
		}
		while (is_prime(right) == 0)
		{
			right++;
		}
		gap = right - left;
		printf ("%d\n",gap);
	}
}
