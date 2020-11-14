#include <cstdio>
#include <iostream>
using namespace std;
long long Combine (int m, int n)
{
	if (n == 1 || n == 0)	return 1;
	else if (m > 0 && m < n)
	{
		return (Combine (m, n - 1) + Combine (m - 1, n - 1));
	}
	else return 1;
}
int main ()
{
	int t, m, n, i;
	long long dp[25] = {0}, result;
	dp[2] = 1;
	dp[3] = 2;
	for (i = 4; i <=20; i ++)
	{
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
	}
	cin >> t;
	while (t --)
	{
		cin >> n >> m;	
		result = dp[m] * Combine (m, n);
		cout << result << endl;
	}
} 
