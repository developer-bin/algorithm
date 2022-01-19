#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n, m;
int maps[501][501];
bool visit[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans1,ans2;

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int bfs(int sx, int sy) {
	visit[sx][sy] = true;
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;	
		cnt += 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				if (maps[nx][ny] == 1) {
					q.push({ nx,ny });
				}
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == false && maps[i][j] == 1) {
				ans2=max(ans2,bfs(i, j));
				ans1 += 1;
			}
		}
	}
	//print
	cout << ans1 << '\n' << ans2;
}