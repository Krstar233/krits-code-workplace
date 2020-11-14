#include <cstdio>
#include <queue>
#include <map>
#include <string.h>
#include <iostream>
using namespace std;

const int maxt = 1000 + 10;
int main ()
{
	int t, i, j, n, x;
	char order [20];
	queue <int> q, q2 [maxt];
	map <int, int>	team;
	
	cout << "please input the number of teams :" ;
	cin >> t;
	//记录所有人的团队编号 
	for (i = 1; i <= t; i ++)
	{	
		cin >> n;
		for (j = 0; j < n; j ++)
		{
			cin >> x;
			team[x] = i;		//team [x] 表示编号为x的人所在的团队编号 
		}
	}
	cout << "success" << endl;
	//输入完毕
	//模拟
	while (1)
	{
		gets (order);
		if (order[0] == 'S')	break;
		else if (order[0] == 'D')
		{
			int t = q.front();
			if (q2[t].empty())
			{
				q.pop();
			}
			t = q.front();
			cout << q2[t].front() << endl;
			q2[t].pop();
		}
		else if (order[0] == 'E')
		{
			cin >> x;
			int t = team[x];
			if (q2[t].empty())
			{
				q.push(t);
			}
			q2[t].push(x);
		}
	}
}
