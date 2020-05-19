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
int d[3][100001];
int dfs(int state, int n) {
	if (n == ::n)return 1;
	int &ans = d[state][n];
	if (ans != -1)return ans;
	ans = 0;
	if (state == 0) {
		ans += dfs(0, n + 1) % MOD + dfs(1, n + 1) % MOD + dfs(2, n + 1) % MOD;
	}
	else if (state == 1) {
		ans += dfs(0, n + 1) % MOD + dfs(2, n + 1) % MOD;
	}
	else if (state == 2) {
		ans += dfs(0, n + 1) % MOD + dfs(1, n + 1) % MOD;
	}
	return ans %= MOD;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	//solve print
	cout << (dfs(0, 1) % MOD + dfs(1, 1) % MOD + dfs(2, 1) % MOD) % MOD;
}