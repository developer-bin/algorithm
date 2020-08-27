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
int maps[101][101];
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
ll d[101][101];
ll dfs(int x, int y) {
	if (x == n && y == n)return 1;
	ll &ans = d[x][y];
	if (ans != -1)return ans;
	ans = 0;
	int nx = x + maps[x][y];
	int ny = y;
	if (boundary(nx, ny)) {
		ans+=dfs(nx, ny);
	}
	nx = x;
	ny = y + maps[x][y];
	if (boundary(nx, ny)) {
		ans+=dfs(nx, ny);
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
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	cout<<dfs(1, 1);
}