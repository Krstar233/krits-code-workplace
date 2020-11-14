#include <iostream>
#include <memory.h>
using namespace std;
int p[100], h[100], c[100];
int value[1000];
int volume[1000];
int tab[1000][1000] = {0};
int main()
{
	int C;
	cin >> C;
	
	while (C--)
	{
		int n, m;
		int key = 1;
		memset(tab, 0, sizeof(int)*1000*1000);
		
		cin >> n >> m;
		
		for (int i = 0; i < m; i++)
		{
			cin >> p[i] >> h[i] >> c[i];
		}
		for (int i = 0; i < m; i++)
		{
			int di = 1;
			while (c[i] != 0)
			{
				if (di > c[i])
				{
					value[key] = h[i] * c[i];
					volume[key] = p[i] * c[i];
					key++;
					c[i] -= c[i];
				}
				else 
				{
					value[key] = h[i] * di;
					volume[key] = p[i] * di;
					key++;
					c[i] -= di;
				}
				di *= 2;
			}
		}
		for (int i = 1; i <= key; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (j < volume[i])
				{
					tab[i][j] = tab[i - 1][j];	
				}
				else
				{
					tab[i][j] = max(tab[i-1][j-volume[i]] + value[i], tab[i-1][j]);
				}
			}
		}
		cout << tab[key][n] << endl;
	}
}
