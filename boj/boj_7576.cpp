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
#include <unordered_set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
struct vertex {
	int x; int y; int cnt;
};
int maps[1001][1001];
int n, m;
queue<vertex> q;
bool visit[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int no_tomato_cnt;
int ans;
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 0) {
				no_tomato_cnt += 1;
			}
			else if (maps[i][j] == 1) {
				q.push({ i,j,0 });
			}
		}
	}
	//solve
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		ans = cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false) {
				if (maps[nx][ny] == 0) {
					visit[nx][ny] = true;
					no_tomato_cnt -= 1;
					q.push({ nx,ny,cnt+1 });
				}
			}
		}
	}
	if (no_tomato_cnt == 0) {
		cout << ans;
	}
	else cout << -1;
}