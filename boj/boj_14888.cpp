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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n;
int a[12];
int cnt[5];
int max_ans = MIN_VALUE;
int min_ans = MAX_VALUE;

void dfs(int idx, int sum) {
	if (idx == n) {
		max_ans = max(sum, max_ans);
		min_ans = min(sum, min_ans);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (cnt[i] >= 1) {
			cnt[i] -= 1;
			switch (i) {
			case 1:
				dfs(idx + 1, sum + a[idx + 1]);
				break;
			case 2:
				dfs(idx + 1, sum - a[idx + 1]);
				break;
			case 3:
				dfs(idx + 1, sum * a[idx + 1]);
				break;
			case 4:
				dfs(idx + 1, sum / a[idx + 1]);
				break;
			}
			cnt[i] += 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= 4; i++)cin >> cnt[i];
	//solve
	dfs(1, a[1]);
	cout << max_ans << '\n' << min_ans;
}
