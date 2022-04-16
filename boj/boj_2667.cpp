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
using namespace std;
int maps[26][26];
int n;
bool visit[26][26];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<int> ans;
int cnt;

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
int bfs(int s_x, int s_y) {
	int cnt = 0;
	queue<pair<int, int>> q;
	visit[s_x][s_y] = true;
	q.push({ s_x,s_y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt += 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false && maps[nx][ny] == 1) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	return cnt;
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	//init

	//input
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &maps[i][j]);
		}
	}
	//solve
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == false && maps[i][j]==1) {
				cnt += 1;
				ans.push_back(bfs(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	//print
	printf("%d\n", cnt);
	for (int k : ans) {
		printf("%d\n", k);
	}
}