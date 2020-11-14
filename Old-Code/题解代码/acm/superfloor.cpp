#include <stdio.h>

int Floor(int m);
int main()
{
	int n;
	int m;
	
	scanf ("%d", &n);
	while (n--)
	{
		scanf ("%d", &m);
		printf ("%d\n", Floor(m));
	}
}
int Floor(int m)
{
	if (m == 2)
		return 1;
	if (m == 3)
		return 2;
	return Floor(m - 1) + Floor(m - 2);
}
