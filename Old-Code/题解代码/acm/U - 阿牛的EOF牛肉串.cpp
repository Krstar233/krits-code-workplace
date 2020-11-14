#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n,i;
	long long dp[45] = {0};
	
	dp[1] = 3;
	dp[2] = 8;
	for (i = 3; i < 40; i ++)
	{
		dp[i] = 2 * dp[i - 1] + 2 * dp[i - 2];
	}
	while (cin >> n)
	{
		cout << dp[n] << endl;
	}
}
