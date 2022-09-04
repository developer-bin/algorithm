#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int maps[51][51];
int n, m;
int ans;

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	//init
	//input
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maps[i][j]);
		}
	}
	//solve
	for (int weight = 0; weight <= min(n, m); weight++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i + weight <= n && j + weight <= m) {
					if (maps[i][j] == maps[i][j + weight] && maps[i][j] == maps[i + weight][j] && maps[i][j]==maps[i + weight][j + weight]) {
						ans = max(ans, weight + 1);
					}
				}
			}
		}
	}
	//print
	printf("%d", ans*ans);
}
