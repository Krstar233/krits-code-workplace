#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(int x, int n, int m, int a[])
{
	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		while (m > 0 && tmp > 0)
		{
			tmp -= x;
			m--;
		}
		if (tmp > 0 && m <= 0)
			return false;
	}
	return true;
}

int main()
{
	int n, m;
	while (cin >> n >> m && n != -1 && m != -1)
	{
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		
		int left = 0;
		int right = a[n - 1];
		
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (check(mid, n, m, a))
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << left + 1 << endl;
	}
} 
