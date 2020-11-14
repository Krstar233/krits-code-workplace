#include <iostream>
#include <cmath>
using namespace std;

double H, h, D, X;
double Fun(double l1)
{
	X = D * h / H;
	double l3 = H - h;
	double l4 = D - (X - l1);
	double x = l3 * D / l4;
	double l2 = H - x;
	double l = l2 + (X - l1);
	
	return l;
}
double max_l()
{
	double left = 0;
	double right = X;
	
	while (fabs(left - right) > 1e-5)
	{
		double mid = (left + right) / 2.0;
		double midmid = (mid + right) / 2.0;
		if (Fun(mid) > Fun(midmid))
		{
			right = midmid;
		}
		else
		{
			left = mid;
		}
	}
	return Fun(left);
}
int main()
{
	int T;
	
	cin >> T;
	while (T--)
	{
		cin >> H >> h >> D;
		Fun(0);
		printf ("%.3f\n", max_l());
	}
}
