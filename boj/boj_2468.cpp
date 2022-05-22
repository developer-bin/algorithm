#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int maps[101][101];
int n;
bool visit[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans;

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
void dfs(int x, int y,int &rain) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && visit[nx][ny]==false && maps[nx][ny] > rain) {
			visit[nx][ny] = true;
			dfs(nx, ny, rain);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	for (int rain = 0; rain <= 99; rain++) {
		memset(visit, false, sizeof(visit));
		int safety = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visit[i][j] == false && maps[i][j] > rain) {
					visit[i][j] = true;
					dfs(i, j,rain);
					safety += 1;
				}
			}
		}
		ans = max(ans, safety);
	}
	//print
	cout << ans;
}