#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <cmath>
#include <map>
#define MAX_VALUE 200000000
#define MIN_VALUE -200000000
#define MOD_VALUE 1000000000
using namespace std;
int n, m;
int maps[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int d[501][501];
int state(int x, int y) {
	if (x == n && y == m)return 1;
	int &ans = d[x][y];
	if (ans != -1)return ans;
	ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && maps[x][y] > maps[nx][ny]) {
			ans+=state(nx, ny);
		}
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	cout<<state(1, 1);
	//print
}