#include <stdio.h>

void change(int a[], int n, int m);
int main()
{
	int n, m;
	int a[100];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	change(a, n, m);
	
	for (int i = 0; i < n; i++)
	{
		printf ("%d", a[i]);
		if (i != n - 1)
			printf (" ");
	}
	
}
void change(int a[], int n, int m)
{
	int b[100];
	
	for (int i = 0; i < n; i++)
	{
		b[(i + m) % n] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
}
	
