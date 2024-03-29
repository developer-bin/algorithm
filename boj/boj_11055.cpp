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
int a[1001];
int d[1001];
int ans = MIN_VALUE;

int dfs(int idx) {
	int &ans = d[idx];
	if (ans != -1)return ans;
	ans = a[idx];
	for (int i = 1; i <= idx - 1; i++) {
		if (a[i] < a[idx]) {
			ans = max(ans, dfs(i) + a[idx]);
		}
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
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//solve
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dfs(i));
	}
	cout << ans;
}