#include <iostream>
using namespace std;

int n = 2;
void copy(int a[][2], int b[][2])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
void MatrixMultiply(int a[][2], int b[][2])
{
	int c[30][30];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			for (int k = 0; k < n; k++)
			{
				tmp += a[i][k] * b[k][j];
			}
			c[i][j] = tmp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = c[i][j];
		}
	}
}
void MatrixDouble(int a[][2])
{
	MatrixMultiply(a, a);
}	
void Mod_a(int a[][2], int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] %= x;
		}
	}
}
int main()
{
	int t;
	while (cin >> t && t != -1)
	{
		int rs[][2] = { 1,0,1,0 };
		int a[][2] = { 1,1,1,0 };
		while (t != 0)
		{
			if (t % 2 == 1)
			{
				MatrixMultiply(rs, a);
				Mod_a(rs, 10000);
			}
			MatrixDouble(a);
			Mod_a(a, 10000);
			t /= 2;
		}
		cout << rs[0][1] << endl;
	}
}
