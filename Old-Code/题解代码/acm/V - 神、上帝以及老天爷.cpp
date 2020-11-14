#include <iostream>
#include <cstdio>
using namespace std;
long long factorial (int n)
{
	long long res = 1;
	int i;
	for (i = 1; i <= n; i ++)
	{
		res *= i;
	}
	return res;
}
int main ()
{
	int t, i , n;
	long long dp[25] = {0};
	double probability = 0;
	
	cin >> t;
	dp[2] = 1;
	dp[3] = 2;
	for  (i = 4; i <= 20; i ++)
	{
		dp[i] = (i - 1) * ( dp[i - 1] + dp[i - 2] );
	}
	while (t --)
	{
		cin >> n;
		probability =( (double) dp[n] / (double) factorial (n) ) * 100;
		printf ("%.2f%%\n",probability);
	}
}
