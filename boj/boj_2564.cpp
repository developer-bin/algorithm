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
int r, c;
int n;
int maps[102][102];
bool visit[102][102];
int dist, diff;
int min_ans[101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool boundary(int x, int y) {
	if (x >= 1 && x <= r && y >= 1 && y <= c) {
		if (x >= 2 && x <= r - 1 && y >= 2 && y <= c - 1)return false;
		return true;
	}
	return false;
}

void state(int x,int y,int cnt) {
	if (maps[x][y] != 0) {
		min_ans[maps[x][y]] = min(min_ans[maps[x][y]], cnt);
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && visit[nx][ny]==false) {
			visit[nx][ny] = true;
			state(nx, ny, cnt + 1);
			visit[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int i = 0; i <= 100; i++) {
		min_ans[i] = MAX_VALUE;
	}

	cin >> c >> r;
	c += 1;
	r += 1;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dist >> diff;
		if (dist == 1) {
			maps[1][diff + 1] = i;
		}
		else if (dist == 2) {
			maps[r][diff + 1] = i;
		}
		else if (dist == 3) {
			maps[diff + 1][1] = i;
		}
		else if (dist == 4) {
			maps[diff + 1][c] = i;
		}
	}

	cin >> dist >> diff;
	if (dist == 1) {
		visit[1][diff + 1] = true;
		state(1, diff + 1, 0);
	}
	else if (dist == 2) {
		visit[r][diff + 1] = true;
		state(r, diff + 1, 0);
	}
	else if (dist == 3) {
		visit[diff + 1][1] = true;
		state(diff + 1, 1, 0);
	}
	else if (dist == 4) {
		visit[diff + 1][c] = true;
		state(diff + 1, c, 0);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += min_ans[i];
	}
	cout << ans;
}