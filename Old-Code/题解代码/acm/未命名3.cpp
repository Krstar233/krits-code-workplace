#include <iostream>
#include <algorithm>

using namespace std;

int n;
char table[] = "ABCDE";
char res[1024];
void solve(int cur)
{
	if (cur == n)
	{
		res[n] = 0;
		puts(res);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		bool ok = true;
		for (int j = 0; j < cur; j++)
		{
			if (res[j] == table[i])
				ok = false;
		}
		if (ok)
		{
			res[cur] = table[i];
			solve(cur + 1);
		}
	}
}
int main()
{
//	while (cin >> n)
//		solve(0);
	do
	{
		puts(table);
	}while (next_permutation(table, table+5));
	return 0;
}
