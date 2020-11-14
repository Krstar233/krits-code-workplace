#include <iostream>
using namespace std;
long long c[41] = {0};
int main()
{
	c[2] = 1;
	for (int i = 2; i < 40; i++)
	{
		c[i + 1] = ((2*(2*i+1))/(i+2))*c[i];
	}
	int n;
	int k = 0;
	while (cin >> n)
	{
		if (n == -1)
			break;
		printf ("%d %d %lld\n", ++k, n, c[n+2]*2);
	}
}
