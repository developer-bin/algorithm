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
int n, m;
int cost_a[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			cost_a[i][j] = MAX_VALUE;
			if (i == j)cost_a[i][j] = 0;
		}
	}
	//input
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		cost_a[from][to] = min(cost_a[from][to], cost);
	}
	//solve
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (cost_a[i][k] + cost_a[k][j] < cost_a[i][j]) {
					cost_a[i][j] = cost_a[i][k] + cost_a[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost_a[i][j] == MAX_VALUE)cost_a[i][j] = 0;
			cout << cost_a[i][j] << ' ';
		}cout << '\n';
	}
}