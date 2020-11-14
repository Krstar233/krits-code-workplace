#include <iostream>
#include <memory.h>
using namespace std;
bool a[10][10];
bool b[10][10] = {false};
int n;
int count = 0;
bool check(int row, int i)
{
	if (!a[row][i])
		return false;
	for (int j = 0; j < row; j++)
	{
		if (b[j][i])
			return false;
	}
	return true;
}
void putchess(int row, int k)
{
	if (k == 0)
	{
		count++;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (b[i][j])
//					cout << "*";
//				else 
//					cout << " ";
//			}
//			cout << endl;
//		}
//		cout << "--------------" << endl;
		return;
	}
	else if (row >= n)
	{
		return;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n; j++)
				b[row][j] = false;
		if (i == n)
		{
			putchess(row+1, k);
		}
		else if(check(row, i))
		{
			b[row][i] = true;
			putchess(row+1, k-1);
		}
	}
}
int main()
{
	char ch;
	int k;
	
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
			break;
		count = 0;
		memset(b, false, sizeof(bool)*10*10);
		for (int i = 0; i < n; i++)
		{
			getchar();
			for (int j = 0; j < n; j++)
			{
				ch = getchar();
				if (ch == '#')
				{
					a[i][j] = true;
				}
				else if (ch == '.')
				{
					a[i][j] = false;
				}
			}
		}
		putchess(0, k);
		cout << count << endl;
	}
}
