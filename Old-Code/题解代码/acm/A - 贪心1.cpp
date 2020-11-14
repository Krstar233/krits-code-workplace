#include <iostream>
using namespace std;

int main()
{
	int n;
	int Ti_s, Ti_e;
	
	while (cin >> n && n != 0)
	{
		int starts[100], ends[100], end = 0, sum = 0;
		
		for (int i = 0; i < n; i++)
		{
			cin >> Ti_s >> Ti_e;
			starts[i] = Ti_s;
			ends[i] = Ti_e;
		}
		for (int i = 0; i < n - 1; i++)
		{
			int min_key = i;
			for (int j = i; j < n; j++)
			{
				if (ends[min_key] > ends[j])
				{
					min_key = j;
				}
			}
			if (min_key != i)
			{
				int tmp1 = ends[min_key];
				int tmp2 = starts[min_key];
				ends[min_key] = ends[i];
				starts[min_key] = starts[i];
				ends[i] = tmp1;
				starts[i] = tmp2;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (end <= starts[i])
			{
				sum++;
				end = ends[i];
			}
		}
		cout << sum << endl;
	}
}
