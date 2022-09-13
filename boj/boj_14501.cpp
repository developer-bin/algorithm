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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n;
int t[16];
int p[16];
int ans;

void dfs(int idx, int sum) {
	if (idx > n + 1)return;
	if (idx == n + 1) {
		ans = max(ans, sum);
		return;
	}
	dfs(idx + t[idx], sum + p[idx]);
	dfs(idx + 1, sum);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	//solve
	dfs(1, 0);
	cout << ans;
}
