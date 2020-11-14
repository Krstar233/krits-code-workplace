#include <iostream>
using namespace std;

int Max(int a, int b, int &flag)
{
	if (a > b)
	{
		flag = 0;
		return a;
	}
	else
	{
		flag = 1;
		return b;
	}
}
int main()
{
	int n, m;
	int a[105];
	int k[105][105] = {0};
	int f[105][105] = {0};
	int flag;
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum < m)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][n] = Max(f[i-1][n-1] + a[i], f[i-1][n] + a[i] - k[i-1][n] + 1, flag);
			if (flag == 0)
			{
				k[i][n] = 1;
			}
			else if (flag == 1)
			{
				k[i][n] += k[i-1][n] + 1;				
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[n][i] >= m)
		{
			cout << i << endl;
			return 0;
		}
	}
//	cout << -1 << endl;
//	return 0;
}
