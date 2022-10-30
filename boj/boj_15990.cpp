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
ll d[100001][4];
int n;
int t;

ll dfs(int sum, int now_num) {
	if (sum == 0)return 0;
	if (sum == 1 && now_num == 1)return 1;
	if (sum == 1 && now_num == 2)return 0;
	if (sum == 1 && now_num == 3)return 0;

	if (sum == 2 && now_num == 1)return 0;
	if (sum == 2 && now_num == 2)return 1;
	if (sum == 2 && now_num == 3)return 0;

	if (sum == 3 && now_num == 1)return 1;
	if (sum == 3 && now_num == 2)return 1;
	if (sum == 3 && now_num == 3)return 1;
	ll &ans = d[sum][now_num];
	if (ans != -1)return ans;
	ans = 0;
	for (int i = 1; i <= 3; i++) {
		if (i == now_num)continue;
		ans += dfs(sum - now_num, i) % MOD;
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
	cin >> t;
	//solve
	while (t--) {
		cin >> n;
		cout << (dfs(n, 1) % MOD + dfs(n, 2) % MOD + dfs(n, 3) % MOD) % MOD << '\n';
	}
}
