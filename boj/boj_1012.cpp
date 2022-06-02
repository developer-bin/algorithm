#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int t;
int n, m, k;
bool maps[51][51];
bool visit[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
void bfs(int s_x, int s_y) {
	visit[s_x][s_y] = true;
	queue<pair<int, int>> q;
	q.push({ s_x,s_y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false && maps[nx][ny] == true) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> t;

	while (t--) {
		memset(maps, false, sizeof(maps));
		memset(visit, false, sizeof(visit));
		//input
		cin >> n >> m >> k;
		for (int i = 1; i <= k; i++) {
			int x, y;
			cin >> x >> y;
			maps[x+1][y+1] = true;
		}
		//solve
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (visit[i][j] == false && maps[i][j] == true) {
					bfs(i, j);
					cnt += 1;
				}
			}
		}
		cout << cnt << '\n';
	}
}
