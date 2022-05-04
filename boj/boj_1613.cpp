#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
bool dist[401][401];
bool r_dist[401][401];
int n, k, s;

void dist_solve() {
	for (int i = 1; i <= n; i++) { 
		dist[i][i] = true;
		r_dist[i][i] = true;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)continue;
				if (dist[i][j]==false && dist[i][k] && dist[k][j])dist[i][j] = true;
				if (r_dist[i][j]==false && r_dist[i][k] && r_dist[k][j])r_dist[i][j] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int from, to;
		cin >> from >> to;
		dist[from][to] = true;
		r_dist[to][from] = true;
	}
	dist_solve();
	cin >> s;
	for (int i = 1; i <= s; i++) {
		int from, to;
		cin >> from >> to;
		if (dist[from][to]) {
			cout << "-1\n";
		}
		else if (r_dist[from][to]) {
			cout << "1\n";
		}
		else cout << "0\n";
	}
}