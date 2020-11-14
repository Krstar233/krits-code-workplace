#include <iostream>
using namespace std;

long long a[100][100] = {0};
long long m[100];
int main()
{
	int n, k;
	int t;
	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				a[i][j] = 1;
			else
			{
				a[i][j] = a[i-1][j-1] + a[i-1][j];
			}
		}
	}
	m[0] = 0;
	m[1] = 0;
	m[2] = 1;
	for (int i = 3; i < 100; i++)
	{
		m[i] = (i-1)*(m[i-1] + m[i-2]);
	}
	
	
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cout << a[n][k] * m[k] << endl;
	}
} 
