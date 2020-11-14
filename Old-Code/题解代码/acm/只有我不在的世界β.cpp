#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int Fun1(int a, int b);
int Fun2(int n, int m);
int check(vector<int> &num, int n);
int main()
{
	int t, b, res;
	scanf("%d",&t);
	while (t--)
	{
		vector<int> num;
		scanf("%d",&b);
		for (int i = 1; i <= 1000; i++)
		{
			res = Fun1(i, b) / i;
			if (check(num, res))
				num.push_back(res);
		}
		printf ("%d\n",num.size());
	}
}
int check(vector<int> &num, int n)
{
	sort(num.begin(), num.end());
	vector<int>::iterator p = lower_bound(num.begin(), num.end(), n);
	if (p != num.end() && *p == n)
		return 0;
	else
		return 1;
}
int Fun1(int a, int b)
{
	int c;
	if (Fun2(a, b) == 1)
		return a*b;
	c = Fun1(a / Fun2(a,b), b / Fun2(a,b)) * Fun2(a,b);
	return c;
}
int Fun2(int n, int m)
{
	int r;
	do
	{
		r = m % n;
		m = n;
		n = r;
	}while (r != 0);
	return m;
}
