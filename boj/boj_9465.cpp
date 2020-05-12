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
int t, n;
int a[3][100001];
int d[100001][3];
int dfs(int idx, int state) {//0-x 1-À§¿¡²¨ 2-¹Ø¿¡²¨
	if (idx == n + 1)return 0;
	int &ans = d[idx][state];
	if (ans != -1)return ans;
	if (state == 0) {
		ans = max({ dfs(idx + 1, 1), dfs(idx + 1, 0), dfs(idx + 1, 2) });
	}
	else if (state == 1) {
		ans = max({ dfs(idx + 1, 0) + a[1][idx] ,dfs(idx + 1, 2) + a[1][idx] });
	}
	else if (state == 2) {
		ans = max(dfs(idx + 1, 0) + a[2][idx], dfs(idx + 1, 1) + a[2][idx]);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	while (t--) {
		memset(d, -1, sizeof(d));
		//input
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		//solve print
		cout << max({ dfs(1,0),dfs(1,1),dfs(1,2) }) << '\n';
	}
}