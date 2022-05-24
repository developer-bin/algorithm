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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n;
int a[1001];
int d[1001];

int dfs(int idx) {
	if (idx > n)return MAX_VALUE;
	if (idx == n)return 0;
	int &ans = d[idx];
	if (ans != -1)return ans;
	ans = MAX_VALUE;
	for (int i = 1; i <= a[idx]; i++) {
		int n_idx = idx + i;
		ans = min(ans, dfs(n_idx) + 1);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	//solve print
	int ans = dfs(1);
	if (ans >= MAX_VALUE)cout << -1;
	else cout << ans;
}