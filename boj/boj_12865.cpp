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
#define MOD 1000000009
#define ll long long
using namespace std;
int n, k;
int w[101];
int v[101];
int d[101][100001];

int dfs(int idx, int sum_w) {
	if (sum_w > k)return MIN_VALUE;
	if (sum_w == k || idx == n + 1) {
		return 0;
	}
	int &ans = d[idx][sum_w];
	if (ans != -1)return ans;
	ans = MIN_VALUE;
	return ans = max(dfs(idx + 1, sum_w), dfs(idx + 1, sum_w + w[idx]) + v[idx]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	//solve
	int ans = dfs(1, 0);
	if (ans == MIN_VALUE)cout << 0;
	else cout << ans;
}
