#include <iostream>
using namespace std;

int main()
{
	int n, v;
	int cost = 0;
	
	cin >> n >> v;
	
	if (n - 1 < v)
	{
		cost += n-1;		
	}
	else
	{
		cost += v;
		for (int i = 2; i <= n - v; i++)
		{
			cost += i;
		}
	}
	cout << cost << endl;
}
