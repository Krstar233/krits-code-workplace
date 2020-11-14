#include <iostream>
#include <algorithm>
using namespace std;
void tran(int a[], int n)
{
	for (int i = 0; i < 6; i++)
	{
		a[i] = n % 10;
		n /= 10;
	}
	sort(a, a + 6);
}
int check(int a[], int n)
{
	int b[6];
	int flag = 0;
	tran(b, n);
	for (int i = 0; i < 6; i++)
	{
		if (b[i] != a[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)	return 0;
	else return 1;
}
int main()
{
	int a[6];
	int flag = 0;
	int flagp = 0;
	int max = 999999 / 6; 
	int i = 142857;
	tran (a,i);
	
	for (int i = 100000; i <= max; i++)
	{
		flag = 0;
		tran(a, i);
		for (int k = 2; k <= 6; k++)
		{
			if (check(a, k*i) == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			flagp = 1;
			cout << i << endl;
			break;
		}
	}
	if (flagp == 0)
	{
		cout << "不存在这样的数" << endl;
	} 
}
