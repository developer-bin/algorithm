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
int a[101];
ll d[21][101];

ll dfs(int sum, int idx) {
	if (idx == n - 1) {
		if (sum == a[n])return 1;
		else return 0;
	}
	if (sum < 0 || sum>20)return 0;
	ll &ans=d[sum][idx];
	if (ans != -1)return ans;
	return ans = dfs(sum + a[idx + 1], idx + 1) + dfs(sum - a[idx + 1], idx + 1);
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
	cout<<dfs(a[1], 1);
}