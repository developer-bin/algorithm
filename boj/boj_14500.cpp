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
#include <stack>
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;

int n, m;
int a[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool visit[501][501];
int ans = MIN_VALUE;

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y, int cnt,int sum) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && visit[nx][ny] == false) {
			visit[nx][ny] = true;
			dfs(nx, ny, cnt + 1, sum + a[nx][ny]);
			visit[nx][ny] = false;
		}
	}
}

void checking(int x, int y) {
	int sum = 0;
	if (y + 2 <= m && x + 1 <= n) {
		sum = a[x][y] + a[x][y + 1] + a[x][y + 2] + a[x + 1][y + 1];
		ans = max(ans, sum);
	}
	
	if (x - 1 >= 1 && x + 1 <= n && y + 1 <= m) {
		sum = a[x][y] + a[x][y + 1] + a[x - 1][y + 1] + a[x + 1][y + 1];
		ans = max(ans, sum);
	}

	if (x - 1 >= 1 && y + 2 <= m) {
		sum = a[x][y] + a[x][y + 1] + a[x][y + 2] + a[x - 1][y + 1];
		ans = max(ans, sum);
	}

	if (x + 2 <= n && y + 1 <= m) {
		sum = a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x + 1][y + 1];
		ans = max(ans, sum);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = true;
			dfs(i, j, 1, a[i][j]);
			visit[i][j] = false;
			checking(i, j);
		}
	}

	cout << ans;
}