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
int maps[501][501];
int d[501][501];
int dfs(int x, int y) {
	if (x > n)return 0;
	int &ans = d[x][y];
	if (ans != -1)return ans;
	return ans = max(dfs(x + 1, y), dfs(x + 1, y + 1)) + maps[x][y];
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
		for (int j = 1; j <= i; j++) {
			cin >> maps[i][j];
		}
	}
	//solve print
	cout << dfs(1, 1);
}