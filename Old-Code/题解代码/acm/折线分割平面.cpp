#include <iostream>
using namespace std;
int main ()
{
	int t, n;
	long long res;
	
	cin >> t;
	while (t --)
	{
		cin >> n;
		res = 2 * n * n - n + 1;
		cout << res << endl;
	}
}
