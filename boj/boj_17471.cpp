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

vector<int> graph[11];
int people[11];

void init() {
}
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}
	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++) {
			int from = i, to;
			cin >> to;
			graph[from].push_back(to);
		}
	}
}
vector<int> nCr_v;
bool visit[11];
bool v_check[11];
int dfs(int v) {
	int result = 0;
	for (int i = 0; i < graph[v].size(); i++) {
		int n_v = graph[v][i];
		if (visit[n_v] == false && v_check[n_v] == true) {
			visit[n_v] = true;
			result+=dfs(n_v);
		}
	}
	result += 1;
	return result;
}
bool dfs_check() {
	memset(visit, false, sizeof(visit));
	memset(v_check, false, sizeof(v_check));
	for (int i = 0; i < nCr_v.size(); i++) {
		v_check[nCr_v[i]] = true;
	}
	visit[nCr_v[0]] = true;
	int cnt=dfs(nCr_v[0]);
	if (cnt == nCr_v.size())return true;
	else return false;
}
bool r_dfs_check() {
	memset(visit, false, sizeof(visit));
	memset(v_check, true, sizeof(v_check));
	for (int i = 0; i < nCr_v.size(); i++) {
		v_check[nCr_v[i]] = false;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (v_check[i]) {
			visit[i] = true;
			cnt=dfs(i);
			break;
		}
	}
	if (cnt == n - nCr_v.size())return true;
	else return false;
}
int ans = MAX_VALUE;
bool check = false;
void nCr(int idx, int cnt,int end_cnt) {
	if (cnt == end_cnt) {
		if (dfs_check() && r_dfs_check()) {
			bool visit[11];
			memset(visit, false, sizeof(visit));
			int a_cnt = 0, b_cnt = 0;
			for (int i = 0; i < nCr_v.size(); i++) {
				visit[nCr_v[i]] = true;
				a_cnt += people[nCr_v[i]];
			}
			for (int i = 1; i <= n; i++) {
				if (visit[i] == false) {
					b_cnt += people[i];
				}
			}
			ans = min(ans, abs(a_cnt - b_cnt));
			check = true;
			return;
		}
	}
	for (int i = idx; i <= n; i++) {
		nCr_v.push_back(i);
		nCr(i + 1, cnt + 1, end_cnt);
		nCr_v.pop_back();
	}
}
void solve() {
	for (int i = 1; i <= n / 2; i++) {
		nCr(1, 0, i);
	}
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
	if (check == false) {
		cout << "-1";
	}else cout << ans;
	return 0;
}