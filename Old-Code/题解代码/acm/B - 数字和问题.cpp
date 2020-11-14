#include <iostream>
using namespace std;

long long pow_m(long long a, long long b, long long need_div)
{
	long long result = 1;
	long long di = a;
	
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			result *= di;
//			if (result > 10)
//			{
//				if (need_div > 0)
//				{
//					result /= 10;
//					need_div--;
//				}
//			}
			result %= 10;
		}
		di *= di;
		di %= 10;
		b /= 2;
	}
	return result % 10;
}
int cul_wei(int x)
{
	int sum = 0;
	
	while (x != 0)
	{
		x /= 10;
		sum++;
	}
	return sum;
}
int deal(long long x)
{
	int sum = 0;
	if (x / 10 == 0)
		return x;
	while (x != 0)
	{
		sum += x % 10;
		x /= 10;
	}
	return deal(sum);
}
int main()
{
	long long a, b;
	long long sum = 0;
	
	while (cin >> a >> b)
	{
		long long a_wei = cul_wei(a);
		for (long long i = 0; i <= a_wei * b; i++)
		{
			sum += pow_m(a, b, i);
		}
		cout << sum << endl;
	}
}
