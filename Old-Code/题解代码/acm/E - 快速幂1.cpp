#include <iostream>
using namespace std;

int M;
long long pow_m(long long a, long long b)
{
	long long result = 1;
	long long di = a;
	
	while (b != 0)
	{
		if (b % 2 == 1)
		{
			result *= di;
			result %= M;
		}
		di *= di;
		di %= M;
		b /= 2;
	}
	return result;
}
int main()
{
	int t;
	
	cin >> t;
	while (t--)
	{
		int n;
		cin >> M;
		cin >> n;
		
		long long A[n], B[n];
		long long result = 0;
		
		for (int i = 0; i < n; i++)
		{
			cin >> A[i] >> B[i];
		}
		for (int i = 0; i < n; i++)
		{
			result += pow_m(A[i], B[i]) % M;
		}
		result %= M;
		cout << result << endl;
	}
}
