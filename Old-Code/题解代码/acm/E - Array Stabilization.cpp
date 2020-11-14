#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int x;
	vector<int> a;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	
	if (a.size() > 2)
	{
		int del1 = a[n-1] - a[1];
		int del2 = a[n-2] - a[0];
		cout << min(del1, del2) << endl;;
	}
	else
	{
		cout << 0 << endl;
	}
	
}
