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
#define MOD 9901
#define ll long long
using namespace std;
ll n, m;
ll k;
ll mid_d[16][16];
ll d[16][16];

bool boundary(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
ll dfs(int x, int y) {
	if (x == 0 && y == 0)return 1;
	ll &ans = d[x][y];
	if (ans != -1)return ans;
	ans = 0;
	int last_x = x - 1;
	int last_y = y;
	if (boundary(last_x, last_y)) {
		ans += dfs(last_x, last_y);
	}
	last_x = x;
	last_y = y - 1;
	if (boundary(last_x, last_y)) {
		ans += dfs(last_x, last_y);
	}
	return ans;
}
ll mid_dfs(int x, int y) {
	if (x == k / m && y == k % m)return d[x][y];
	ll &ans = mid_d[x][y];
	if (ans != -1)return ans;
	ans = 0;
	int last_x = x - 1;
	int last_y = y;
	if (boundary(last_x, last_y)) {
		ans += mid_dfs(last_x, last_y);
	}
	last_x = x;
	last_y = y - 1;
	if (boundary(last_x, last_y)) {
		ans += mid_dfs(last_x, last_y);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	memset(d, -1, sizeof(d));
	memset(mid_d, -1, sizeof(mid_d));
	//input
	cin >> n >> m >> k;
	k -= 1;
	//solve
	if (k == -1) {
		//print
		cout << dfs(n-1, m-1);
	}
	else {
		//print
		dfs(k / m, k%m);
		cout << mid_dfs(n - 1, m - 1);
	}
}