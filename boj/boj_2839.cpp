#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n;
int d[5001];

int dfs(int w) {
	if (w > n)return MAX_VALUE;
	if (w == n) {
		return 0;
	}
	int &ans = d[w];
	if (ans != -1)return ans;
	ans = MAX_VALUE;
	return ans = min(dfs(w + 3), dfs(w + 5)) + 1;
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
	int ans=dfs(0);
	//print
	if (ans >= MAX_VALUE)cout << "-1";
	else cout << ans;
}