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
int start_v[100001];
int visit[100001];
int visit_num[100001];
int t;
int n;
int a[100001];
int dfs(int s_v, int v, int cnt) {
	int n_v = a[v];
	if (visit[n_v] == false) {
		visit[n_v] = true;
		start_v[n_v] = s_v;
		visit_num[n_v] = cnt + 1;
		return dfs(s_v, n_v, cnt + 1);
	}
	else if (start_v[n_v] == s_v) {
		return cnt - visit_num[n_v] + 1;
	}
	else if (start_v[n_v] != s_v) {
		return 0;
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
	//input
	cin >> t;
	while (t--) {
		memset(visit, false, sizeof(visit));
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) {
				start_v[i] = i;
				visit[i] = true;
				visit_num[i] = 1;
				ans+=dfs(i, i, 1);
			}
		}
		cout << n - ans<<'\n';
	}
	//solve
	//print
	return 0;
}