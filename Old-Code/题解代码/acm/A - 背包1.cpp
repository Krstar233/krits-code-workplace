#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	
	cin >> t;
	
	while (t--)
	{
		int n, v;
		int value[1000] = {0};
		int volume[1000] = {0};
		int tab[1000][1000] = {0};
		
		cin >> n >> v;
		for (int i = 1; i <= n; i++)
		{
			cin >> value[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> volume[i];
		}
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= v; j++)
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
		cout << tab[n][v] << endl;
	}	
} 
