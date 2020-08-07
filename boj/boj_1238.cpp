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
#include <unordered_map>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n, m, x;
int dist[1001][1001];
int ans = MIN_VALUE;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		dist[from][to] = cost;
	}
	//solve
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (dist[i][k]==0 || dist[k][j]==0)continue;
				if (dist[i][j] == 0)dist[i][j] = dist[i][k] + dist[k][j];
				else {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist[i][x] + dist[x][i]);
	}
	cout << ans;
}