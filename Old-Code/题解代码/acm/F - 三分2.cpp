#include <iostream>
#include <cmath>
using namespace std;

int n;
double a[10000], b[10000], c[10000];

double S(double x, int i)
{
	return a[i]*x*x + b[i]*x + c[i];
}
double Fun(double x)
{
	double max = S(x, 0);
	for (int i = 0; i < n; i++)
	{
		if (max < S(x, i))
			max = S(x, i);
	}
	return max;
}
double min_f()
{
	double left = 0;
	double right = 1000;
	
	while (fabs(left - right) > 1e-6)
	{
		double mid = (left + right) / 2.0;
		double midmid = (mid + right) / 2.0;
		if (Fun(mid) > Fun(midmid))
		{
			left = mid;
		}
		else
		{
			right = midmid;
		}
	}
	return Fun(left);
}
int main()
{
	int t;
	
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		printf ("%.4f\n", min_f());
	}
}
