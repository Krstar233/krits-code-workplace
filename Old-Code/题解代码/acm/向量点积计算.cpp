#include <stdio.h>

int Culculate(int a[], int b[], int n);
int main()
{
	int n;
	int a[1005], b[1005];
	int ans;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	ans = Culculate(a, b, n);
	printf ("%d",ans);
}
int Culculate(int a[], int b[], int n)
{
	int sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
	}
	return sum;
}
