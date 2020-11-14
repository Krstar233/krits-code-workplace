#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct friends
{
	int x;
	int v;
	double left;
	double right;
}Friend[60005];
void border (friends &m, double t)
{
	m.left = m.x - m.v * t;
	m.right = m.x + m.v * t;
}
void reload (int friends_num,double t)
{
	int i;
	for (i = 1; i <= friends_num; i ++)
	{
		border (Friend[i] , t);
	}
}
friends mix (friends m1,friends m2)
{
	friends m;
	
	m.left = max (m1.left, m2.left);
	m.right = min (m1.right, m2.right);
	return m;
}
int check_f (int friends_num)	//ÓÐÂß¼­´íÎó£¬ÒªÖØÐ´ 
{
	int i;
	friends m;
	
	m = mix (Friend[1], Friend[2]);
	for (i = 3; i <= friends_num; i ++)
	{
		if (m.left < m.right)
		{
			m = mix (m , Friend[i]);
		}
		else break;
	}
	if (m.left < m.right)	return 1;
	else return 0;
}
int main ()
{
	int friends_num;
	int x, i;
	double t_left = 0, t_right = 1, t;
	
	cin >> friends_num;
	for (i = 1; i <= friends_num; i ++)
	{
		cin >> Friend[i].x;
	//	cout << Friend[i].x << endl;
	}
	for (i = 1; i <= friends_num; i ++)
	{
		cin >> Friend[i].v;
	//	cout << Friend[i].v << endl;
	}
	while (1)
	{
		reload (friends_num, t_right);
		if (check_f (friends_num) == 0)	t_right *= 10.0;
		else break;
	}
	while (1)
	{
		if (t_right - t_left > 1e-6)	
		{
			t = (t_left + t_right) / 2.0;
			reload (friends_num, t);
		}
		else break;
		if (check_f (friends_num) == 0)	t_left = t;
		else t_right = t;
	}
	t = (t_left + t_right) / 2.0;
	printf ("%f", t);
}
