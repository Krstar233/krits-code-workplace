#include <algorithm>
#include <iostream>
using namespace std;
static int Count = 0;
static int flag[10] = {0};
static int arr[100] = {0};
int change ()
{
	int i,num = 0;
	
	for (i = 0;i < 8;i ++)
	{
		num += flag[i] + 1;
		if (i != 7)	num*=10;	
	}
	return num;
}
int check (int x, int y)
{
	int i,data;
	for (i = 0;i < y;i++)
	{
		data = flag[i];
		if (data == x)	return 0;
		if ((data + i) == (x + y))	return 0;
		if ((data - i) == (x - y))	return 0;
	}
	return 1;
}
void Eightqueen(int y)
{
	int x;
	for (x = 0;x < 8;x++)
	{
		if (check(x,y))
		{
			if (y == 7)
			{
				flag[y] = x;
				arr[Count] = change ();
				Count ++;
				flag[y] = 0;
				return;
			}
			flag[y] = x;
			Eightqueen (y + 1);
			flag[y] = 0;
		}
	}
}
int main()
{
	int t,n;
	
	Eightqueen(0);
	sort (arr,arr + Count);
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << arr[n-1] << endl;
	}
	
	return 0;
}
