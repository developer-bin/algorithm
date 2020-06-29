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
int p[1001];
int d[1001];
int dfs(int cnt) {
	if (cnt == 0)return 0;
	if (cnt < 0)return MAX_VALUE;
	int &ans = d[cnt];
	if (ans != -1)return ans;
	ans = MAX_VALUE;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dfs(cnt - i) + p[i]);
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
		cin >> p[i];
	}
	//solve
	cout << dfs(n);
}