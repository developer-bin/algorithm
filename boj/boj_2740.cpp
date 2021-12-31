#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n, m, k;
int a[101][101];
int b[101][101];
int ans[101][101];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> m >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			cin >> b[i][j];
		}
	}
	//solve
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int sum = 0;
			for (int k = 1; k <= m; k++) {
				ans[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}
	//print
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << ans[i][j] << ' ';
		}cout << '\n';
	}
}
