#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n;
ll ans;
ll d[10][101];

ll dfs(int floor, int cnt) {
	if (cnt == 1 && floor == 0)return 0;
	if (cnt == 1)return 1;
	ll &result = d[floor][cnt];
	if (result != -1)return result;
	result = 0;
	int last_floor = floor + 1;
	if (0 <= last_floor && last_floor <= 9) {
		result = dfs(last_floor, cnt - 1) % MOD;
	}
	last_floor = floor - 1;
	if (0 <= last_floor && last_floor <= 9) {
		result += dfs(last_floor, cnt - 1) % MOD;
	}
	return result %= MOD;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	//solve
	for (int i = 0; i <= 9; i++) {
		ans += dfs(i, n) % MOD;
	}
	//print
	cout << ans % MOD;
}
