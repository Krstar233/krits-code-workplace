#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	int cases = 0;
	while (cin >> n >> m){
		if (n == 0 && m == 0)
			break;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		printf ("CASE# %d:\n", ++cases);
		for (int i = 1; i <= m; i++){
			int x, p;
			cin >> x;
			p = lower_bound(a, a+n, x) - a;
			if (a[p] == x){
				printf ("%d found at %d\n", x, p+1);
			}
			else
				printf ("%d not found\n", x);
		}
	}
	return 0;
}
