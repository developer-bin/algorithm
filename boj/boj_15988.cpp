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
ll d[1000001];
int t, n;
ll dfs(int num) {
	if (num == n)return 1;
	if (num > n)return 0;
	ll &ans = d[num];
	if (ans != -1)return ans;
	ans = dfs(num + 1) % MOD + dfs(num + 2) % MOD + dfs(num + 3) % MOD;
	return ans %= MOD;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	d[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		if (i - 1 >= 0) {
			d[i] += d[i - 1] % MOD;
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2] % MOD;
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3] % MOD;
		}
		d[i] %= MOD;
	}
	//input
	cin >> t;
	//solve
	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}

}