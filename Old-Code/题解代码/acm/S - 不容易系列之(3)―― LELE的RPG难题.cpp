#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int num,i;
	long long dp[51];
	
	dp[1] = 3;
	dp[2] = 6;
	dp[3] = 6;
	for (i = 4;i < 51;i ++)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	
	while (~scanf ("%d",&num))
	{
		cout << dp[num] << endl;
	}
}

