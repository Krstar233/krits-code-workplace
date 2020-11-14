#include <bits/stdc++.h>
using namespace std;
bool check(set<int> a, set<int> b)
{
	vector<int> c;
	
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
	if (c.size() != 0)
		return true;
	return false;
}
int main()
{
	int t;
	int n, m;
	
	vector<set<int> > a;
	vector<set<int> >::iterator ve_iter1, ve_iter2;
	set<int>::iterator se_iter;
	
	cin >> t;
	
	while (t--)
	{
		cin >> n >> m;
		a.clear();
		for (int i = 1; i <= n; i++)
		{
			set<int> tmp;
			tmp.insert(i);
			a.push_back(tmp);
		}
		for (int i = 0; i < m; i++)
		{
			int per1, per2;
			cin >> per1 >> per2;
			set<int> tmp;
			tmp.insert(per1);
			tmp.insert(per2);
			a.push_back(tmp);
		}
		for (ve_iter1 = a.begin(); ve_iter1 != a.end(); ve_iter1++)
		{
			int count = 1;
			while (count)
			{
				for (ve_iter2 = ve_iter1 + 1; ve_iter2 != a.end();)
				{
					if (check(*ve_iter1, *ve_iter2))
					{
						(*ve_iter1).insert((*ve_iter2).begin(), (*ve_iter2).end());
						ve_iter2 = a.erase(ve_iter2);
						count++;
					}
					else
					{
						ve_iter2++;
					}
				}
				count /= 2;
			}
		}
		cout << a.size() << endl;
	}
}
