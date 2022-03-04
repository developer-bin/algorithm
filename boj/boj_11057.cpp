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
#define MOD 1000000000
#define ll long long
using namespace std;
int n;
int d[1001][10];
int ans;

int dfs(int idx, int num) {
	if (idx == n)return 1;
	int &ans = d[idx][num];
	if (ans != -1)return ans;
	ans = 0;
	for (int i = num; i <= 9; i++) {
		ans += dfs(idx + 1, i) % 10007;
	}
	return ans % 10007;
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
	for (int i = 0; i <= 9; i++) {
		ans += dfs(1, i);
	}
	//print
	cout << ans % 10007;
}