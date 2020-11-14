#include <iostream>
using namespace std;

int main()
{
	int t;
	
	cin >> t;
	
	long long dp[25][25][25] = {0};
	
	dp[1][1][1] = 1;
	
	for (int i = 2; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			for (int k = 1; k <= 20; k++)
			{
				dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + (i-2)*dp[i-1][j][k];
			}
		}
	}
	
	while (t--)
	{
		int n, l, r;
		cin >> n >> l >> r;
		cout << dp[n][l][r] << endl;
	}
}
