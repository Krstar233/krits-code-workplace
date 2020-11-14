#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;
int in_order[maxn], post_order[maxn], lch[maxn], rch[maxn];
int n;
bool read_list(int *a){
	string s;
	int x;
	n = 0;
	if (!getline(cin, s))
		return false;
	stringstream ss(s);
	while (ss >> x)
		a[n++] = x;
	return n > 0;
}
int build(int L1, int R1, int L2, int R2){
	if (L1 > R1)
		return 0;
	int root = post_order[R2];
	int p = L1;
	while (in_order[p] != root)	p++;
	int cnt = p - L1;
	lch[root] = build(L1, p-1, L2, L2+cnt-1);
	rch[root] = build(p+1, R1, L2+cnt, R2-1);
	return root;
}
int best, best_sum;
void dfs(int u, int sum){
	sum += u;
	if (!lch[u] && !rch[u]){
		if (sum < best_sum || (sum == best_sum && u < best)){
			best = u;
			best_sum = sum;
		}
		return;
	}
	if (lch[u])
		dfs(lch[u], sum);
	if (rch[u])
		dfs(rch[u], sum);1	
	return;
}
int main(){
	while (read_list(in_order)){
		read_list(post_order);
		best = 1000000;
		best_sum = 1000000;
		build(0, n-1, 0, n-1);
		dfs(post_order[n-1], 0);
		cout << best << endl;
	}
}
