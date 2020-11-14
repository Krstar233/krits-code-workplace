#include <iostream>
using namespace std;
int main ()
{
	int i,n;
	long long dp[55] = {0};
	
	dp[1] = 1 ;dp[2] = 2;
	for (i = 3; i <= 50; i ++)
		dp[i] = dp[i - 1] + dp[i - 2];
	while (cin >> n)
	{
		cout << dp[n] << endl;
	}
} 
