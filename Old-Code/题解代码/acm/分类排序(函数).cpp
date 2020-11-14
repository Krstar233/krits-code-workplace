#include <stdio.h>

void sort(int a[], int n);
int find(int a[], int n, int value);
void display(int a[], int n);
void reverse(int a[], int n);
void resort(int a[], int n);

int main()
{
	int t;
	int num[11];
	int a;
	
	scanf("%d",&t);
	while (t--)
	{
		int n = 10;
		int flag;
		int tmp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&num[i]);
		}
		scanf("%d",&a);
		if (a % 2 == 0)
		{
			flag = find(num, n, a);
			if (flag == -1)
			{
				num[n] = a;
				n++;
				sort(num, n);
				reverse(num, n);
				display(num, n);
			}
			else
			{
				resort(num, n);
				display(num, n);
			}
		}
		else
		{
			flag = find(num, n, a);
			if (flag == -1)
			{
				resort(num, n);
				display(num, n);
			}
			else
			{
				for (int i = flag; i < n - 1; i++)
					num[i] = num[i + 1];
				n--;
				sort(num, n);
				display(num, n);
			}
		}
	}
	
}

void sort(int a[], int n)
{
	int min;
	int t;
	
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i; j < n; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		t = a[i];
		a[i] = a[min];
		a[min] = t;
	}
}

int find(int a[], int n, int value)
{
	for (int i = 0; i < n; i++)
		if (a[i] == value)
			return i;
	return -1;
}

void display(int a[], int n)
{
	for (int i =0; i < n; i++)
	{
		printf ("%d", a[i]);
		if (i != n - 1)
			printf (" ");
	}
	printf("\n");
}

void reverse(int a[], int n)
{
	int t;
	for (int i = 0; i < n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}

void resort(int a[], int n)
{
	int tmp;
	
	sort(a, n);
	reverse(a, n);
	for (int i = 0; i < n; i++)
	{
		if (!(a[i] % 2 == 0))
		{
			while (i - 1 >= 0 && a[i - 1] % 2 == 0)
			{
				tmp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = tmp;
				i--;
			}
		}
	}
}
