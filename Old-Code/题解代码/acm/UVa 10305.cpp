#include <deque>
#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 128;
int G[maxn][maxn];
int c[maxn];
int topo[maxn], t;
int n, m;
bool toposort();
void solve(){
	int a, b;
	while (true){
		memset(G, 0, sizeof(G));
		cin >> n >> m;
		t = n;
		if (n == 0 && m == 0)
			break;
		while (m--){
			cin >> a >> b;
			G[a][b] = 1;
		}
		if (toposort()){
			for (int i = 0; i < n; i++){
				printf("%d", topo[i]);
				if (i != n - 1)
					printf(" ");
			}
			printf("\n");
		}
	}
}
bool dfs(int u){
	c[u] = -1;
	for (int v = 1; v <= n; v++){
		if (G[u][v]){
			if (c[v] < 0){
				return false;
			}
			else if (!c[v] && !dfs(v))	return false;
		}
	}
	c[u] = 1;
	topo[--t] = u;
	return true;
}
bool toposort(){
	memset(c, 0, sizeof(c));
	for (int u = 1; u <= n; u++){
		if (!c[u]){
			if (!dfs(u))
				return false;
		}
	}
	return true;
}
int main(){	
	solve();
}
