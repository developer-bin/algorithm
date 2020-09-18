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
int n;
int a[1001];
int ans;
int d[1001];
int dfs(int idx) {
	int &ans = d[idx];
	if (ans != -1) {  return ans; }
	ans = 0;
	bool checking = false;
	for (int i = idx + 1; i <= n; i++) {
		if (a[idx] < a[i]) {
			ans = max(ans, dfs(i) + 1);
			checking = true;
		}
	}
	if (checking == false) { return ans=1; }
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
	for (int i = 1; i <= n; i++)cin >> a[i];
	//solve
	for (int i = 1; i <= n; i++) {
		ans=max(ans,dfs(i));
	}
	//print
	cout << ans;
}