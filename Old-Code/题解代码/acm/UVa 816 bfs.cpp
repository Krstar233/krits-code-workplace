//“— AC 

#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <memory.h>
#include <cstring>
#include <string>
using namespace std;

const char* dirs = "NESW"; //À≥ ±’Î 
const char* turns = "FLR";
struct Node{
	int r,c,dir;
	Node(int r=0, int c=0, int dir=-1): r(r), c(c), dir(dir) {}
};
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

Node walk(const Node &u, int turn){
	int r, c, dir = u.dir;
	if (turn == 1){
		dir = (u.dir + 3) % 4;
	}else if (turn == 2){
		dir = (u.dir + 1) % 4;
	}
	r = u.r + dr[dir];
	c = u.c + dc[dir];
	return Node(r, c, dir);
}


const int maxn = 128 + 8;
int d[maxn][maxn][4];
Node p[maxn][maxn][4];
bool has_edge[maxn][maxn][4][3] = {false};

int m = 9, n = 9;
int r1, c1, r2, c2, dir;

int to_dir(char ch){
	return strchr(dirs, ch) - dirs;
}
int to_turn(char ch){
	return strchr(turns, ch) - turns;
}
bool inside(int r, int c){
	if (r <= 0 || r > m || c <= 0 || c > n)
		return false;
	return true;
}
void read_input(){
	string s;
	int r, c;
	int ch;
	
	memset(has_edge, false, sizeof(has_edge));
	scanf("%d %d %c %d %d", &r1, &c1, &ch, &r2, &c2);
	dir = to_dir(ch);
	has_edge[r1][c1][dir][0] = true;
	while (cin >> r){
		if (r == 0)
			break;
		cin >> c;
		while (cin >> s && s != "*"){
			for (int i = 1; i < s.length(); i++){
//				cout << r << " " << c << " " << to_dir(s[0]) << " " << to_turn(s[i]) << endl;
				has_edge[r][c][to_dir(s[0])][to_turn(s[i])] = true;
			}
		}
	}
}
void print_ans(Node u){
	stack<Node> ans;
	while (u.r != r1 || u.c != c1){
		ans.push(u);
		u = p[u.r][u.c][u.dir];
	}
	ans.push(u);
	
	bool flag = false;
	if (ans.size()%10 != 0)
		flag = true;
	int cnt = 0;
	while (!ans.empty()){
		u = ans.top();ans.pop();
		if (cnt % 10 == 0)	printf(" ");
		printf(" (%d,%d)", u.r, u.c);
		if (++cnt % 10 == 0)	printf("\n");
	}
	if (flag)
		printf("\n");
}
//bfs
void solve(){
	queue<Node> q;
	memset(d, -1, sizeof(d));
	Node u(r1, c1, dir);
	q.push(u);
	while (!q.empty()){
		Node u = q.front(); q.pop();
		if (u.r == r2 && u.c == c2){
			print_ans(u);
			return;
		}
		for (int i = 0; i < 3; i++){
			Node v = walk(u, i);
//			cout << u.r << " " << u.c << " " << u.dir << " " << i << endl;
			if (has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0){
//				cout << "*" << endl;
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf("  No Solution Possible\n");
}

int main(){
//		
	string s1;
	while (true){
		cin >> s1;
		if (s1 == "END")
			break;
		read_input();
		cout << s1 << endl;
		solve();
	}
}
