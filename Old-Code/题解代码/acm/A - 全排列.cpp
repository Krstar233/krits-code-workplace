#include <iostream>
#include <algorithm>
using namespace std;

int a[1024];
int main()
{
	int m;
	
	cin >> m;
	while (m--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < k; i++)
		{
			next_permutation(a, a+n);
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d", a[i]);
			if (i != n-1)
				printf(" ");
		}
		cout << endl;
	}
}
