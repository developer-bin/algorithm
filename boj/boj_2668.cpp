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
int d[4002][4002];
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool boundary(int x) {
	return x >= 0 && x <= 100000;
}
int a[101];
bool visit[101];
int ans;
void init() {
}
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}
bool check;
vector<int> mid_v;
vector<int> ans_v;
int dfs(int s_v,int v, int cnt) {
	int n_v = a[v];
	if (visit[n_v] == false) {
		visit[n_v] = true;
		mid_v.push_back(n_v);
		int num = dfs(s_v, n_v, cnt + 1);
		if (check == false)visit[n_v] = false;
		return num;
	}
	else if (visit[n_v] == true && n_v == s_v) {
		return cnt;
	}
	else if (visit[n_v] == true && n_v != s_v) {
		check = false;
		return 0;
	}
}
void solve() {
	for (int s_v = 1; s_v <= n; s_v++) {
		if (visit[s_v] == false) {
			visit[s_v] = true;
			check = true;
			mid_v.clear();
			mid_v.push_back(s_v);
			ans+=dfs(s_v,s_v,1);
			if (check == false)visit[s_v] = false;
			else {
				for (int i = 0; i < mid_v.size(); i++)ans_v.push_back(mid_v[i]);
			}
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
	sort(ans_v.begin(), ans_v.end());
	cout << ans << '\n';
	for (int k : ans_v) {
		cout << k << '\n';
	}
	return 0;
}