#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int sum, k, m, t, i, j, n;
	double aver, dis, min_dis;
	int pm[505] = {0}, flag[505] = {0};
	
	cin >> t;
	while (t --)
	{
		sum = aver = n = 0;
		cin >> m >> k;
		for (i = 0; i < m; i ++)
		{
			cin >> pm[i];
			aver += pm[i];
		}
		aver = aver / k;
		min_dis = aver + 10;
		for (i = 0; i < m; i ++)
		{
			if (n == k - 1)	break;
			sum += pm [i];
			dis = fabs (aver - sum);
			if (dis < min_dis)	min_dis = dis;
			else
			{
				sum = 0;
				min_dis =  aver + 10;
				i --;
				if (n < k)
				{
					flag [n] = i;
					n ++;
				}
			}
		}
		for (n = 0, i = 0; i < m; i ++)
		{
			cout << pm [i];
			if (i != m - 1) cout << " "; 
			if (i == flag [n] && i != m - 1)
			{
				cout << "/ ";
				n ++;
			}
		}
		cout << endl;
	}
}
