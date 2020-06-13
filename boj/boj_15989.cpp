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
int t;
int n;
ll d[10001][4];
ll dfs(int sum, int num) {
	if (sum <= 0)return 0;
	if (sum == 1 && num == 1)return 1;
	if (sum == 1 && num == 2)return 0;
	if (sum == 1 && num == 3)return 0;

	if (sum == 2 && num == 1)return 1;
	if (sum == 2 && num == 2)return 1;
	if (sum == 2 && num == 3)return 0;

	if (sum == 3 && num == 1)return 1;
	if (sum == 3 && num == 2)return 1;
	if (sum == 3 && num == 3)return 1;
	ll &ans = d[sum][num];
	if (ans != -1)return ans;
	ans = 0;
	for (int i = num; i >= 1; i--) {
		ans += dfs(sum - num, i);
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
	cin >> t;
	//solve
	while (t--) {
		cin >> n;
		cout << dfs(n, 1) + dfs(n, 2) + dfs(n, 3) << '\n';
	}
}