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
int d1[1001];
int d2[1001];
int ans = MIN_VALUE;
int up_dfs(int idx) {
	int &ans = d1[idx];
	if (ans != -1)return ans;
	ans = 1;
	for (int i = 1; i <= idx - 1; i++) {
		if (a[i] < a[idx]) {
			ans = max(ans, up_dfs(i) + 1);
		}
	}
	return ans;
}

int down_dfs(int idx) {
	int &ans = d2[idx];
	if (ans != -1)return ans;
	ans = 1;
	for (int i = idx + 1; i <= n; i++) {
		if (a[idx] > a[i]) {
			ans = max(ans, down_dfs(i) + 1);
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//solve
	for (int i = 1; i <= n; i++) {
		up_dfs(i);
		down_dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d1[i] + d2[i] - 1);
	}
	cout << ans;
}