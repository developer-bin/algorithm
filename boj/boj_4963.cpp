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
int w, h;
int maps[51][51];
bool visit[51][51];
int dx[] = { 0,0,-1,1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,-1,1 };
bool boundary(int x, int y) {
	return x >= 1 && x <= w && y >= 1 && y <= h;
}
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && visit[nx][ny] == false && maps[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		//init
		memset(visit, false, sizeof(visit));
		//input
		cin >> h >> w;
		if (w == 0 && h == 0)break;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				cin >> maps[i][j];
			}
		}
		//solve
		int ans = 0;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				if (visit[i][j] == false && maps[i][j] == 1) {
					dfs(i, j);
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}