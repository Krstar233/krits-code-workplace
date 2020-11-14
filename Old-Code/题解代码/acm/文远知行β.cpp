#include <stdio.h>

int main()
{
	int t;
	int n;
	int a[105];
	
	scanf("%d",&t);
	while (t--)
	{
		int flag = 0;
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
			if (a[i] <= 0)
				flag = 1;
		}
		if (flag == 1)
			printf ("Transform Mobility With Autonomous Driving\n");
		else 
			printf ("WeRide.ai\n");
	}
}
