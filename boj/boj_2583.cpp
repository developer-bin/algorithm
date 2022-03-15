#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;  
int maps[101][101];
int m, n, k;
bool visit[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int area_cnt;
vector<int> ans;

void map_checking(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			maps[i][j] = 1;
		}
	}
}
bool boundary(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}
void bfs(int sx, int sy) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		cnt += 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false && maps[nx][ny]==0) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	ans.push_back(cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> m >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		map_checking(x1,y1,x2,y2);
	}
	//solve
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (maps[i][j] == 0 && visit[i][j]==false) {
				area_cnt += 1;
				bfs(i,j);
			}
		}
	}
	//print
	sort(ans.begin(), ans.end());
	cout << area_cnt << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}