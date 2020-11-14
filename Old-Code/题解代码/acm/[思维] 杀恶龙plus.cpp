#include <stdio.h>
#include <algorithm>
#define N 20000

using namespace std;
int a[N + 5], b[N + 5];
void del(int key, int n[], int &len);
int search(int n[], int len, int num);
int judge(int n, int m);

int main()
{
	int n, m;
	int sum;
	
	while (scanf("%d%d",&n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		for (int i = 0; i < m; i++)
			scanf("%d",&b[i]);
		sort(b, b+m);
		sum = judge(n, m);
		if (sum != -1)
			printf ("%d\n", sum);
		else
			printf ("Loowater is doomed!\n");
	}
	/*
	while(~scanf("%d",&n))
	{
	for (int i = 0; i < n; i++)
			scanf("%d",&a[i]);
	sort(a, a + n);
	scanf("%d",&m);
	search(a,n,m);
	}*/
}

int judge(int n, int m)
{
	int sum = 0;
	int left = n;
	int key;
	
	for(int i = 0; i < n; i++)
	{
		key = search(b, m, a[i]);
		if (key != m)
		{
			sum += b[key];
			del (key, b, m);
			left--;
		}
	}
	if (left != 0)
		return -1;
	else
		return sum;
}

void del(int key, int n[], int &len)
{
	for (int i = key; i < len - 1; i++)
	{
		n[i] = n[i + 1];
	}
	len--;
}

int search(int n[], int len, int num)
{
	
	for (int i = 0; i < len; i++)
	{
		if (n[i] >= num)
			return i;
	}
	return len;	
/*	
	int left = -1;
	int right = len;
	int mid;
	
	while (right - left != 1)
	{
		mid = left + (right - left) / 2;
		if (a[mid] >= num)
		{
			right = mid;
			//printf ("right = %d\n",right);
		}
		else
		{
			left = mid;
			//printf ("left = %d\n",left);
		}
	}
	//printf ("right = %d\n",right);
	return right;
*/
}
