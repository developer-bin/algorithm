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
using namespace std;
struct v {
	int x; int y; int cnt;
};
bool visit[101][101];
int maps[101][101];
int n, m;
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < num.length(); j++) {
			maps[i][j + 1] = num[j]-'0';
		}
	}

	//solve
	queue<v> q;
	q.push({ 1,1,1 });
	visit[1][1] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		if (x == n && y == m) {
			cout << cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false && maps[nx][ny]==1) {
				visit[nx][ny] = true;
				q.push({ nx,ny,cnt + 1 });
			}
		}
	}
}