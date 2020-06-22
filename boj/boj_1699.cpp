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
int d[100001];
int ans = MAX_VALUE;
int dfs(int sum) {
	if (sum == n)return 1;
	if (sum > n)return MAX_VALUE;
	int &ans = d[sum];
	if (ans != -1)return ans;
	ans = MAX_VALUE;
	for (int i = 1; i*i <= n; i++) {
		ans = min(ans, dfs(sum + (i * i)) + 1);
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
	//solve
	for (int i = 1; i*i <= n; i++) {
		ans = min(ans, dfs(i*i));
	}
	cout << ans;
}