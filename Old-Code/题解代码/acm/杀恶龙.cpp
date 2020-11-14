#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	vector<int> a, b;
	vector<int>::iterator p1,p2;
	int pay = 0;
	int n,m;
	
	while (cin >> n >> m)
	{
		int x;
		vector<int>().swap(a);
		vector<int>().swap(b);
		pay = 0;
		int del = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&x);
			a.push_back(x);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d",&x);
			b.push_back(x);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for (p1 = a.begin(); p1 < a.end(); p1++)
		{
			p2 = upper_bound (b.begin(),b.end(),*p1);
			if (p2 != b.begin() && *(p2 - 1) == *p1)
			{
				p2--;
			}
			if (p2 != b.end())
			{
				pay += *p2;
				b.erase(p2);
				del++;
			}
		}
		if (del == n)
		{
			printf ("%d\n",pay);
		}
		else	printf ("Loowater is doomed!\n");
	}
}

