#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000000;
bool arr[MAXN + 1] = {false};
vector<int> prim;

long long Pow(int a, int b)
{
	long long ans = 1;
	while (b != 0)
	{
		if (b % 2 == 1)
		{
			ans *= a;
		}
		a *= a;
		b /= 2;
	}
	return ans;
}
void getPrim()
{
	prim.push_back(2);
	int i, j;
	
	for (i = 3; i * i <= MAXN; i += 2)
	{
		if (!arr[i])
		{
			prim.push_back(i);
			for (j = i*i; j <= MAXN; j += i)
			{
				arr[j] = true;
			}
		}
	}
	while (i <= MAXN)
	{
		if (!arr[i])
		{
			prim.push_back(i);
		}
		i += 2;
	}
}

int getPrimpow(int n, int x)
{
	int pow = 0;
	while (n >= x)
	{
		int tmp = n / x;
		pow += tmp;
		n = tmp;
	}
	return pow;
}
int main()
{
	getPrim();
	int n, k;
	
	while (cin >> n >> k)
	{
		long long ans = 1;
		if (n == 0 && k == 0)
			break;
		for (int i = 0; i < prim.size(); i++)
		{
			if (prim[i] <= n)
			{
				int pow = getPrimpow(n, prim[i]) - getPrimpow(k, prim[i]) - getPrimpow(n-k, prim[i]);
				ans *= Pow(prim[i], pow);
			}
			else
				break;
		}
		cout << ans << endl;
	}
	
}
