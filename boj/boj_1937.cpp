#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
int d[501][501];
int n;
int maps[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans;
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
int dfs(int x, int y) {
	if (d[x][y] != -1)return d[x][y];
	int &ans=d[x][y];
	ans = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && maps[x][y]<maps[nx][ny]) {
			ans=max(dfs(nx, ny) + 1,ans);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans=max(ans,dfs(i, j));
		}
	}
	//print
	cout << ans;
	return 0;
}