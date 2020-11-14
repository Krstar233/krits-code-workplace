#include <iostream>
using namespace std;

int n = 4;
void MatrixMultiply(int a[][4], int b[][4])
{
	int c[4][4];
	
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
		for (int j = 0; j < n; j++)
			a[i][j] = c[i][j];
}
void MatrixDouble(int a[][4])
{
	MatrixMultiply(a,a);
}
void Mod_a(int a[][4], int x)
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
	int num;
	
	cin >> t;
	while (t--)
	{
		cin >> num;
		num--;
		int a[][4] ={
		2,1,1,0,
		1,2,0,1,
		1,0,2,1,
		0,1,1,2
		};
		int b[4] = {2,1,1,0}; 
		int c[][4] ={
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1
		};
		
		while (num != 0)
		{
			if (num % 2 == 1)
			{
				MatrixMultiply(c, a);
				Mod_a(c, 10007);
			}
			MatrixDouble(a);
			Mod_a(a, 10007);
			num /= 2;
		}
		int result = 0;
		for (int i = 0; i < n; i++)
		{
			result += b[i] * c[0][i];
		}
		result %= 10007;
		cout << result << endl;
		
	}
}
