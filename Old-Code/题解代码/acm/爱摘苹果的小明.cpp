#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int a[10];
	int x;
	
	scanf("%d",&N);
	while (N--)
	{
		int tall = 30;
		int flag;
		int i;
		for (i = 0; i < 10; i++)
			scanf("%d",&a[i]);
		sort(a, a + 10);
		scanf("%d",&x);
		tall += x;
		for (i = 0; i < 10; i++)
		{
			if (a[i] > tall)
				break;
		}
		printf ("%d\n",i);
	}
}
