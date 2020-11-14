#include <iostream>
#include <memory.h>
#include <stack>
#include <string>
using namespace std;
const int maxn = 256 + 10;
int G[maxn][maxn];
int vis[maxn][maxn];
int n1 = 'a', n2 = 'z';
string s;

int abs(int x){
	return x > 0 ? x : -x;
}
//递归调用： 
//void dfs(int u){
//	for (int v = n1; v <= n2; v++){
//		if (G[u][v] && vis[u][v] != G[u][v]){
//			vis[u][v]++;
//			dfs(v);
//			return;
//		}
//	}
//}

//非递归（压栈）调用： 
void dfs(int u){
	stack<int> st;
	st.push(u);
	while (!st.empty()){
		u = st.top(); st.pop();
		for (int v = n1; v <= n2; v++){
			if (G[u][v] && vis[u][v] != G[u][v]){
				vis[u][v]++;
				st.push(v);
				break;
			}
		}
	}
}

bool ok(){
	bool started = false;
	int cnt2 = 0;
	for (int u = n1; u <= n2; u++){
		int out = 0;
		int in = 0;
		for (int v = n1; v <= n2; v++){
			if (G[u][v])
				out += G[u][v];
			if (G[v][u])
				in += G[v][u];
		}
//		cout << out << " " << in << endl;
		if (out - in == 1){
			started = true;
			dfs(u);
			break;
		}
	}
	if (!started)
		dfs(s[0]);
	for (int u = n1; u <= n2; u++){
		for (int v = n1; v <= n2; v++){
			if (G[u][v] != vis[u][v])
				return false;
		}
	}
	return true;
}
int main(){
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++){
			cin >> s;
			if (s[0] != s[s.length() - 1])
				G[s[0]][s[s.length()-1]]++;
		}
		if (ok()){
			cout << "Ordering is possible." << endl;
		}else
			cout << "The door cannot be opened." << endl;
	}
}
