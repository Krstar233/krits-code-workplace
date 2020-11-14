#include <iostream>
using namespace std;
int main()
{
	int n;
	int length;
	int k;
	char ch = '*';

	while (cin >> n)
	{
		if (n < 4)
		{
			cout << "ERROR\n";
			continue;
		}
		length = 2 * n - 1;
		k = length / 6;

		while (true)
		{
			if (k <= 0)
				break;
			for (int i = 0; i < k; i++)
				cout << "  ";
			for (int i = 0; i < length / 2 - k * 2 + 1; i++)
				cout << ch << " ";
			for (int i = 0; i < length / 2 - (length / 2 - k * 2 + 1); i++)
				cout << "  ";
			for (int i = 0; i < length / 2 - k * 2 + 1; i++)
				cout << ch << " ";
			cout << endl;
			k--;
		}
		
		for (int i = 0; i < length / 6; i++)
		{
			for (int j = 0; j < length; j++)
				cout << ch << " ";
			cout << endl;
		} 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cout << "  ";
			}
			for (int j = 0; j < (2 * n - 1) - 2 * i; j++)
			{
				cout << ch << " ";
			}
			cout << endl;
		}
	}
}
