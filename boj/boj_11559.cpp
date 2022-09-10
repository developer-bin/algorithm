#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <cmath>
#include <map>
#define MAX_VALUE 200000000
#define MIN_VALUE -200000000
#define MOD_VALUE 1000000000
using namespace std;
char maps[13][7];
queue<pair<int, int>> pung_q;
queue<pair<int, int>> tmp_q;
int pung_col_cnt[7];
bool visit[13][7];
bool pung_visit[13][7];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool boundary(int x, int y) {
	return x >= 1 && x <= 12 && y >= 1 && y <= 6;
}
void input() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf(" %c", &maps[i][j]);
			if (maps[i][j] != '.')pung_q.push({ i,j });
		}
	}
}
void dfs(int x,int y,char s_alpa) {
	tmp_q.push({ x,y });
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && visit[nx][ny] == false && maps[nx][ny] == s_alpa) {
			visit[nx][ny] = true;
			dfs(nx, ny, s_alpa);
		}
	}
}
bool pung() {
	memset(visit, false, sizeof(visit));
	int size = pung_q.size();
	int cnt = 0;
	for (int i = 1; i <= size; i++) {
		int s_x = pung_q.front().first;
		int s_y = pung_q.front().second;
		pung_q.pop();
		if (visit[s_x][s_y] == false && maps[s_x][s_y]!='.') {
			visit[s_x][s_y] = true;
			dfs(s_x, s_y, maps[s_x][s_y]);
			if (tmp_q.size() >= 4) {
				cnt += 1;
				while (!tmp_q.empty()) {
					int x = tmp_q.front().first;
					int y = tmp_q.front().second;
					tmp_q.pop();
					maps[x][y] = 'X';
				}
			}
			else {
				while (!tmp_q.empty()) {
					tmp_q.pop();
				}
			}
		}
	}
	if (cnt >= 1)return true;
	else return false;
}
void down_go(int x, int y) {
	for (int i = x; i >= 2; i--) {
		maps[i][y] = maps[i - 1][y];
		if (pung_visit[i][y] == false) {
			pung_visit[i][y] = true;
			pung_q.push({ i,y });
		}
	}
	maps[1][y] = '.';
}
void down() {
	memset(pung_visit, false, sizeof(pung_visit));
	for (int j = 1; j <= 6; j++) {
		for (int i = 12; i >= 1; i--) {
			if (maps[i][j] == 'X') {
				down_go(i, j);
				i += 1;
			}
		}
	}
}
int solve() {
	int cnt = 0;
	while (true) {
		if (pung() == false)break;
		cnt += 1;
		down();
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
	int t;
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		cout<<'#'<<testcase<<' '<<ans<<'\n';
	}*/
	//init
	//input
	input();
	//solve
	cout<<solve();
	//print
	return 0;
}
