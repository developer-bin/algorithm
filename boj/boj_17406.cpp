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
#define MOD_VALUE 1000000000
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m;
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool boundary(int x) {
	return x >= 0 && x <= 100000;
}

int maps[51][51];
int k;
vector<tuple<int, int, int>> v;

void init() {
}
void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maps[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
}
bool visit[7];
vector<int> permu_v;
void rotate(int r, int c, int s) {
	int c_map[51][51];
	memcpy(c_map, maps, sizeof(maps));
	for (; s >= 1; s--) {
		for (int j = c - s + 1; j <= c + s; j++) {
			c_map[r - s][j] = maps[r - s][j - 1];
		}
		for (int i = r - s + 1; i <= r + s; i++) {
			c_map[i][c + s] = maps[i - 1][c + s];
		}
		for (int j = c + s - 1; j >= c - s; j--) {
			c_map[r + s][j] = maps[r + s][j + 1];
		}
		for (int i = r + s - 1; i >= r - s; i--) {
			c_map[i][c - s] = maps[i + 1][c - s];
		}
	}
	memcpy(maps, c_map, sizeof(c_map));
}
int ans = MAX_VALUE;
void permu(int cnt) {
	if (cnt == k) {
		int ori_map[51][51];
		memcpy(ori_map, maps, sizeof(maps));
		for (int i = 0; i < permu_v.size(); i++) {
			int r, c, s;
			tie(r, c, s) = v[permu_v[i]];
			rotate(r,c,s);
		}
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				sum += maps[i][j];
			}
			ans = min(ans, sum);
		}
		memcpy(maps, ori_map, sizeof(ori_map));
		return;
	}
	for (int i = 0; i < k; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			permu_v.push_back(i);
			permu(cnt + 1);
			permu_v.pop_back();
			visit[i] = false;
		}
	}
}
void solve() {
	permu(0);
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	/*
	int t;
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		cout<<'#'<<testcase<<' '<<ans<<'\n';
	}*/
	//init
	init();
	//input
	input();
	//solve and print
	solve();
	cout << ans;
	return 0;
}