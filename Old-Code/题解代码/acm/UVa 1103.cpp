#include <cstdio>
#include <memory.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200 * 4 + 10;
int H, W;
int pic[maxn][maxn];
int ids[maxn][maxn];
char un_ch[256][5];
char anc_chs[20];
int holes[100];
int m, n;
vector<char> ans;

void unload(char ch, int r, int c) {
	for (int i = 0; i < 4; i++) {
		pic[r][4 * c + i] = un_ch[ch][i] - '0';
	}
}

const int dr[] = { -1, 1, 0, 0};
const int dc[] = { 0, 0, 1, -1};

void dfs(int r, int c, int id) {
	if (r < 0 || r >= m || c < 0 || c >= n)	return;
	if (pic[r][c] != 1 || ids[r][c] != 0)	return;
	ids[r][c] = id;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++)
			if (i != 0 || j != 0)
				dfs(r + i, c + j, id);
	}
}
void dfs2(int r, int c, int id) {
	if (r < 0 || r >= m || c < 0 || c >= n)	return;
	if (pic[r][c] != 0 || ids[r][c] != 0)	return;
	ids[r][c] = id;
	for (int i = 0; i < 4; i++) {
		dfs2(r + dr[i], c + dc[i], id);
	}
}

int main() {

	strcpy(un_ch['0'], "0000");
	strcpy(un_ch['1'], "0001");
	strcpy(un_ch['2'], "0010");
	strcpy(un_ch['3'], "0011");
	strcpy(un_ch['4'], "0100");
	strcpy(un_ch['5'], "0101");
	strcpy(un_ch['6'], "0110");
	strcpy(un_ch['7'], "0111");
	strcpy(un_ch['8'], "1000");
	strcpy(un_ch['9'], "1001");
	strcpy(un_ch['a'], "1010");
	strcpy(un_ch['b'], "1011");
	strcpy(un_ch['c'], "1100");
	strcpy(un_ch['d'], "1101");
	strcpy(un_ch['e'], "1110");
	strcpy(un_ch['f'], "1111");

	anc_chs[1] = 'A';
	anc_chs[3] = 'J';
	anc_chs[5] = 'D';
	anc_chs[4] = 'S';
	anc_chs[0] = 'W';
	anc_chs[2] = 'K';

	while (cin >> H >> W) {
		while (getchar() != '\n');
		m = H;
		n = 4 * W;
		memset(pic, 0, sizeof(pic));
		memset(ids, 0, sizeof(ids));
		memset(holes, 0, sizeof(holes));
		ans.clear();
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char ch = getchar();
				unload(ch, i, j);
			}
			getchar();
		}
		int id = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (pic[i][j] == 1 && ids[i][j] == 0) {
					dfs(i, j, ++id);
				}
			}
		}
		
		dfs2(0, 0, -1);//把背景标记为-1;
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (ids[i][j] > 0) {
					int cur_id = ids[i][j];
					for (int k = 0; k < 4; k++) {
						if (i + dr[k] >= 0 && i + dr[k] < m && j + dc[k] >= 0 && j + dc[k] < n) {
							
							if (pic[i + dr[k]][j + dc[k]] == 0 && ids[i + dr[k]][j + dc[k]] == 0) {
								dfs2(i + dr[k], j + dc[k], -1);
								holes[cur_id]++;
							}
						}
					}
				}
			}
		}
//3 3
//012
//345
//666
		for (int i = 1; i <= id; i++) {
			ans.push_back(anc_chs[holes[i]]);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}
		cout << endl;
	}
}
