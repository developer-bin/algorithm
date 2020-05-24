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
int a[1001];
int t, w;
int d[3][31][1001];
int tree_idx_change(int idx) {
	if (idx == 1)return 2;
	if (idx == 2)return 1;
}
int dfs(int tree_idx, int cnt, int time) {
	if (time == t)return 0;
	int &ans = d[tree_idx][cnt][time];
	if (ans != -1)return ans;
	ans = MIN_VALUE;
	if (cnt + 1 <= w) {
		//움직
		if (a[time] == tree_idx) {
			ans = max(ans, dfs(tree_idx_change(tree_idx), cnt + 1, time + 1));
		}
		else {
			ans = max(ans, 1 + dfs(tree_idx_change(tree_idx), cnt + 1, time + 1));
		}
	}
	//안움직
	if (a[time] == tree_idx) {
		ans = max(ans, 1 + dfs(tree_idx, cnt, time + 1));
	}
	else {
		ans = max(ans, dfs(tree_idx, cnt, time + 1));
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
	cin >> t >> w;
	for (int i = 0; i < t; i++)cin >> a[i];
	//solve
	cout << dfs(1, 0, 0);
}