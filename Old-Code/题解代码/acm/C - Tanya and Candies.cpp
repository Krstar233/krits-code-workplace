#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	
	cin >> n;
	int a[n], b[n];
	int counts = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int cul = 1;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			sum = sum + cul * a[j];
			cul = -cul;
		}
		if (sum == 0)
			counts++;
	}
	cout << counts << endl;
}
