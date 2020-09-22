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
int dist[51][51];
int ans = MAX_VALUE;
int ans_cnt;
vector<int> ans_v;
void init() {
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			dist[i][j] = MAX_VALUE;
		}
	}
}
void input() {
	cin >> n;
	while (true) {
		int from, to;
		cin >> from >> to;
		if (from == -1 && to == -1)break;
		dist[from][to] = 1;
		dist[to][from] = 1;
	}
}
void solve() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int mid_max = MIN_VALUE;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			mid_max = max(mid_max, dist[i][j]);
		}
		if (ans > mid_max) {
			ans_cnt = 1;
			ans = mid_max;
			ans_v.clear();
			ans_v.push_back(i);
		}
		else if (ans == mid_max) {
			ans_cnt += 1;
			ans_v.push_back(i);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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
	cout << ans<<' '<<ans_cnt<<'\n';
	for (int k : ans_v) {
		cout << k << ' ';
	}
	return 0;
}