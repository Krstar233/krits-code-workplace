#include <iostream>

using namespace std;

int cul_wei(long long x)
{
	int sum = 0;
	while (true)
	{
		x = x >> 1;
		sum ++;
		if (x == 0)
			break;
	}
	return sum;
}
void change(long long x, int a[], int wei)
{
	int b[wei] = {0};
	for (int i = 0; i < wei; i++)
	{
		b[i] = (int)(x & 1);
		x = x >> 1;
	}
	for (int i = 0; i < wei; i++)
	{
		a[i] = b[wei - i - 1];
	}
}
long long change_back(int a[], int wei)
{
	long long x = 0;
	
	for (int i = 0; i < wei; i++)
	{
		long long tmp = a[i];
		x = x << 1;
		x = x | tmp;
	}
	return x;
}
int main()
{
	int t;
	
	cin >> t;
	while (t--)
	{
		long long l, r;
		int wei = 0;
		long long result = 0;
				
		cin >> l >> r;
		int l_wei = cul_wei(l);
		int r_wei = cul_wei(r);
		if (l_wei < r_wei)
		{
			for (int i = 0; i < r_wei; i++)
			{
				result = result << 1;
				result = result | 1;
			}
		}
		else
		{
			int X[l_wei] = {0};
			int R[r_wei] = {0}, L[l_wei] = {0};
			change(r, R, r_wei);
			change(l, L, l_wei);
			for (int i = 0; i < l_wei; i++)
				X[i] = L[i];
			for (int i = 0; i < l_wei; i++)
			{
				if ((X[i] | R[i]) == 0)
				{
					X[i] = 1;
					if (change_back(X, l_wei) > change_back(R, r_wei))
					{
						X[i] = 0;
					}
				}
			}
			result = (change_back(X, l_wei)) | r;
		}
		cout << result << endl;
	}
}
