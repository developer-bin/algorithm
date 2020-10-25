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
int n, s, m;
int v[101];
bool boundary(int x) {
	return x >= 0 && x <= m;
}
int d[101][101001];
int dfs(int idx,int s) {
	if (idx == n + 1) {
		return s; 
	}
	int &ans = d[idx][s];
	if (ans != -1)return ans;
	ans = MIN_VALUE;
	if (boundary(s + v[idx]))ans = max(ans, dfs(idx + 1, s + v[idx]));
	if (boundary(s - v[idx]))ans = max(ans, dfs(idx + 1, s - v[idx]));
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)cin >> v[i];
	//solve print
	int ans = dfs(1, s);
	if (ans == MIN_VALUE)cout << -1;
	else cout << ans;
}