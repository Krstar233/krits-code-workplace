#include <iostream>
using namespace std;

int main()
{
	int n;
	int F[50] = {0}, f[50] = {0};
	
	F[3] = 1;
	F[4] = 3;
	f[1] = 2;
	f[2] = 4;
	f[3] = 7;
	
	for (int i = 4; i < 35; i++)
	{
		f[i] = f[i-1] + f[i-2] + f[i-3];
	}
	for (int i = 5; i < 35; i++)
	{
		F[i] = 2*F[i-1] + f[i-4];
	}
	while (cin >> n && n != 0)
	{
		cout << F[n] << endl;
	}
}
