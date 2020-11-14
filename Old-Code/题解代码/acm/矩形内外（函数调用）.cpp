#include <stdio.h>

struct point
{
	int x, y;
	point(int a, int b){
		x = a;
		y = b;
	}
};

int check(point a);
int main()
{
	int n;
	
	scanf("%d",&n);
	while (n--)
	{
		int x, y;
		
		scanf("%d%d",&x, &y);
		point a(x, y);
		
		if (check(a))
			printf ("in\n");
		else
			printf ("out\n");
	}
}

int check(point a)
{
	if (a.x >= 1 && a.x <= 5)
	{
		if (a.y >= 1 && a.y <= 5)
		{
			return 1;
		}
	}

	return 0;
}
