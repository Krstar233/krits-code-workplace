#include <iostream>
using namespace std;

struct my_struct
{
	int A2[30][30];
	int A4[30][30];
};

void MatrixMultiply(int a[][30], int b[][30], int n)
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
void MatrixDouble(int a[][30], int n)
{
	MatrixMultiply(a, a, n);
}
void mod_a(my_struct &a, int x, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a.A2[i][j] %= x;
			a.A4[i][j] %= x;
		}
	}
}
void add(int a[][30], int b[][30], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] += b[i][j];
		}
	}
}
void multi(my_struct &a, my_struct b, int  n)
{
	MatrixMultiply(a.A2, b.A4, n);
	add(a.A2, b.A2, n);
	MatrixMultiply(a.A4, b.A4, n);
}

int main()
{
	int n, k, m;
	

	while (cin >> n >> k >> m)
	{
		int A[30][30];
		struct my_struct my;
		struct my_struct my2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> A[i][j];
				my.A2[i][j] = my.A4[i][j] = A[i][j];
				my2.A2[i][j] = my2.A4[i][j] = A[i][j];
			}
		}
		if (k == 0)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << 0;
					if (j != n - 1)
						cout << " ";
				}
				cout << endl;
			}
			continue;
		}
		if (k = 1)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << A[i][j] % m;
					if (j != n - 1)
						cout << " ";
				}
				cout << endl;
			}
			continue;
		}

		k -= 2;
		while (k > 0)
		{
			if (k % 2 == 1)
			{
				multi(my2, my, n);
				mod_a(my2, m, n);
			}
			multi(my, my, n);
			mod_a(my, m, n);
			k /= 2;
		}

		MatrixMultiply(my2.A2, A, n);
		add(my2.A2, A, n);
		mod_a(my2, m, n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << my2.A2[i][j];
				if (j != n - 1)
					cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
