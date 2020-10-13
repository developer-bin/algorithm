#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_map>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n, m, k;
int maps[1001][1001];
int ans = -1;
struct vertex {
	int x;
	int y;
	int broke;
	int cnt;
};
queue<vertex> q;
bool visit[1001][1001][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	//init
	//input
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maps[i][j]);
		}
	}
	//solve
	q.push({ 1,1,0,1 });
	visit[1][1][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int broke = q.front().broke;
		q.pop();
		if (x == n && y == m) {
			ans = cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int n_broke = broke + 1;
			if (boundary(nx, ny)) {
				if (maps[nx][ny] == 0 && visit[nx][ny][broke] == false) {
					visit[nx][ny][broke] = true;
					q.push({ nx,ny,broke,cnt + 1 });
				}
				if (n_broke <= k && maps[nx][ny] == 1 && visit[nx][ny][n_broke] == false) {
					visit[nx][ny][n_broke] = true;
					q.push({ nx,ny,n_broke,cnt + 1 });
				}
			}
		}
	}
	//print
	cout << ans;
	return 0;
}