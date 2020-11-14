#include <iostream>
using namespace std;

int maze[5][5];
int xn[100] = {0};
int yn[100] = {0};
int minbu_xn[100] = {0};
int minbu_yn[100] = {0};
int minbu = 100;
int test = 0;
const int N = 5;

bool ok(int x, int y)
{
//	cout << ++test << endl;
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	if (maze[x][y] == 1)
		return false;
	return true;
}
void walk(int x, int y, int bu, int lastdir) //r -- 0	u -- 1	  d -- 2
{
	if (x == N-1 && y == N-1)
	{
		if (minbu > bu)
		{
			minbu = bu;
			for (int i = 0; i < minbu; i++)
			{
				minbu_xn[i] = xn[i];
				minbu_yn[i] = yn[i];
			}
		}
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (i + lastdir == 3)
			continue;
		switch (i)
		{
			case 0:
				if (ok(x+1,y))
				{
					xn[bu+1] = x+1;
					yn[bu+1] = y;
					walk(x+1, y, bu + 1, i);
				}
				break;
			case 1:
				if (ok(x,y-1))
				{
					xn[bu+1] = x;
					yn[bu+1] = y-1;
					walk(x, y-1, bu + 1, i);
				}
				break;
			case 2:
				if (ok(x,y+1))
				{
					xn[bu+1] = x;
					yn[bu+1] = y+1;
					walk(x, y+1, bu + 1, i);
				}
				break;
		}
	}
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> maze[i][j];
	}

	walk(0, 0, 0, -1);
	minbu_xn[minbu] = N-1;
	minbu_yn[minbu] = N-1;
	minbu++;
	for (int i = 0; i < minbu; i++)
	{
		printf ("(%d, %d)\n", minbu_xn[i], minbu_yn[i]);
	}
	
}
