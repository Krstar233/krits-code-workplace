#include <iostream>
#include <memory.h>
using namespace std;

int weight[505];
int p[505];
int f[505][505];
int Min(int a[], int x)
{
	int min = a[0];
	for (int i = 0; i < x; i++)
	{
		if (min > a[i])
			min = a[i];
	}
	return min;
}
int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		memset(f, -10000, sizeof(int) *505*505);
		f[0][0] = 0;
		
		int E, F;
		
		cin >> E >> F;
		
		int v = F - E;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i] >> weight[i];
		}
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= v; j++)
			{
				int tmp[505];
				int k;
				for (k = 0; k*weight[i] <= v; k++)
				{
					tmp[k] = f[i-1][v-k*weight[i]] + k*p[i];
				}
				f[i][j] = Min(tmp, k);
			}
		}
		if (f[n][v] < 0)
		{
			cout << "This is impossible." << endl;
		}
		else
		{
			cout << "The minimum amount of money in the piggy-bank is " << f[n][v] << "." << endl;
		}
	}
}
