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
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
ll d[1 << 16][17];
int n;
ll w[17][17];
ll ans = MAX_VALUE;
ll dfs(int bit, ll num) {
	if (bit == (1 << n) - 1) {
		if (w[num][0] != 0)return w[num][0];
		else return MAX_VALUE;
	}
	ll &ans = d[bit][num];
	if (ans != -1)return ans;
	ans = MAX_VALUE;
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (!(bit & (1 << i))) {
			if (w[num][i] != 0) {
				check = true;
				ans = min(ans, dfs((bit | (1 << i)), i) + w[num][i]);
			}
		}
	}
	if (check == false) { return MAX_VALUE; }
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}
	//solve
	ans = dfs(1, 0);
	//print
	cout << ans;
}