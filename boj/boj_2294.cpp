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
#define MOD 1000000000
#define ll long long
using namespace std;
int n, k;
int d[10001];
int a[101];

int dfs(int sum) {
	if (sum > k)return MAX_VALUE;
	if (sum == k)return 0;
	int &ans = d[sum];
	if (ans != -1)return ans;
	ans = MAX_VALUE;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dfs(sum + a[i]) + 1);
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
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//solve
	int ans = dfs(0);
	if (ans == MAX_VALUE)cout << "-1";
	else cout << ans;
}