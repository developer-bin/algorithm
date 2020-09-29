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
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n, m;
int dist[201][201];
int path[201];
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dist[i][j];
			if (i == j)dist[i][j] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> path[i];
	}
}
void all_path() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (dist[i][k] != 0 && dist[k][j] != 0) {
					dist[i][j] = 1;
				}
			}
		}
	}
}
void path_check() {
	for (int i = 1; i <= m - 1; i++) {
		if (dist[path[i]][path[i + 1]] == 0) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
	return;
}
void solve() {
	all_path();
	path_check();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	input();
	//solve
	solve();
}