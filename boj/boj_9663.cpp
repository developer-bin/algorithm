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
#include <unordered_set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 1000000009
#define ll long long
using namespace std;
int n;
bool col[15];
bool down[30];
bool up[30];
int ans;
void dfs(int row) {
	if (row == n + 1) {
		ans += 1;
		return;
	}
	int i = row;
	for (int j = 1; j <= n; j++) {
		if (col[j] == false && down[n + (i - j)] == false && up[i + j] == false) {
			col[j] = down[n + (i - j)] = up[i + j] = true;
			dfs(row + 1);
			col[j] = down[n + (i - j)] = up[i + j] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	//solve
	dfs(1);
	cout << ans;
}