#include <iostream>
using namespace std;
int main()
{
	int t;
	int k = 1;
	int n = 1;
	char s[1000];
	
	cin >> t;
	cin >> s;
	
	while (n <= t)
	{
		printf("%c", s[n - 1]);
		k++;
		n = (1+k)*k/2;
	}
	cout << endl; 
}
