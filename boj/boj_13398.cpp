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
int n;
int a[100001];
int d[100001][2];
int ans = MIN_VALUE;

int dfs(int idx, int erase) {
	int &ans = d[idx][erase];
	if (ans != MAX_VALUE)return ans;
	ans = MIN_VALUE;
	if (erase == 1) {
		if (idx != 1) {
			ans = max(ans, dfs(idx - 1, 0));
		}
		ans = max(ans, dfs(idx - 1, 1) + a[idx]);
		ans = max(ans, a[idx]);
	}
	else if (erase == 0) {
		ans = max({ dfs(idx - 1,0) + a[idx],a[idx] });
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j <= 1; j++) {
			d[i][j] = MAX_VALUE;
		}
	}
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//solve
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dfs(i, 1));
		ans = max(ans, dfs(i, 0));
	}
	cout << ans;
}
