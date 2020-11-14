#include <stdio.h>

int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while (t--)
	{
		int len = 0;
		int maxlen = 0;
		int last;
		int x;
		
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&x);
			if (len == 0)
			{
				last = x;
				len++;
			}
			else if (x == last + 1)
			{
				len++;
				last = x;
			}
			else
			{
				len = 1;
				last = x;
			}
			
			if (maxlen <= len)
				maxlen = len;
		}
		printf ("%d\n",maxlen);
	}
 } 
