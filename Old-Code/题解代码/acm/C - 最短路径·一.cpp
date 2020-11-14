#include <iostream>
#include <set>
#include <memory.h>
using namespace std;
int test = 0;

int dis[1005];
int roads[1005][1005];
int main()
{
	int n, m, s, t;
	set<int> s1;
	
	memset(dis, 10015, sizeof(int)*1005);
	memset(roads, 10015, sizeof(int)*1005*1005);
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		if (roads[a][b] > c)
		{
			roads[a][b] = c;
			roads[b][a] = c;
		}
//		cout << "----test----" << endl;
//		cout << roads[a][b] << endl;
//		cout << "------------" << endl;
	}
	//dis:[a1,a2,a3,...,an]
	for (int i = 0; i <= n; i++)
	{
		dis[i] = roads[s][i];
		//cout << dis[i] << endl;
	}
	dis[s] = 0;
	roads[s][s] = 0;
	s1.insert(s);
	while (true)
	{
		int min_road_index = 1001;
		for (int i = 1; i <= n; i++)
		{
			if (s1.find(i) == s1.end())
			{
				if (dis[min_road_index] > dis[i])
				{
					min_road_index = i;
				}
			}
		}
		if (min_road_index == 1001 || dis[min_road_index] >= 10015)
			break;
		s1.insert(min_road_index);
		//киЁз
		for (int i = 1; i <= n; i++)
		{
			int tmp = roads[min_road_index][i] + dis[min_road_index];
			if (tmp < roads[s][i])
			{
//				cout << ++test << endl;
				dis[i] = tmp;
			}
		}
	}
	cout << dis[t] << endl;
}
