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
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int hx[] = { -2,-2,-1,-1,1,1,2,2 };
int hy[] = { -1,1,-2,2,-2,2,-1,1 };
int n, m, k;

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int maps[201][201];
bool visit[201][201];
int dist[201][201];
struct v {
	int x; int y; int cnt; int h_cnt;
};
void init() {
	for (int i = 1; i <= 200; i++)
		for (int j = 1; j <= 200; j++)
			dist[i][j] = MAX_VALUE;
}
void input() {
	cin >> k >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maps[i][j];
		}
	}
}
int solve() {
	queue<v> q;
	q.push({ 1,1,0,0 });
	visit[1][1] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int h_cnt = q.front().h_cnt;
		//cout << x << ' ' << y << ' ' << cnt << ' ' << h_cnt << '\n';
		q.pop();
		if (dist[x][y] < h_cnt)continue;
		if (x == n && y == m) {
			return cnt;
		}
		if (h_cnt >= k) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (boundary(nx, ny) && maps[nx][ny] == 0) {
					if (dist[nx][ny] > h_cnt) {
						dist[nx][ny] = h_cnt;
						q.push({ nx,ny,cnt + 1,h_cnt });
					}
				}
			}
		}
		else if (h_cnt < k) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (boundary(nx, ny) && maps[nx][ny] == 0) {
					if (dist[nx][ny] > h_cnt) {
						dist[nx][ny] = h_cnt;
						q.push({ nx,ny,cnt + 1,h_cnt });
					}
				}
			}
			for (int i = 0; i < 8; i++) {
				int nx = x + hx[i];
				int ny = y + hy[i];
				if (boundary(nx, ny) && maps[nx][ny] == 0) {
					if (dist[nx][ny] > h_cnt + 1) {
						dist[nx][ny] = h_cnt + 1;
						q.push({ nx,ny,cnt + 1,h_cnt+1 });
					}
				}
			}
		}
	}
	return -1;
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
	init();
	//input
	input();
	//solve and print
	cout<<solve();
	return 0;
}
