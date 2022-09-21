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
int maps[101][101];
bool bridge[101][101];
int n, l;
int ans;

bool row_state(int x, int y) {
	if (y >= n) {
		return true;
	}
	if (maps[x][y] == maps[x][y + 1]) {
		return row_state(x, y + 1);
	}
	if (maps[x][y] + 1 == maps[x][y + 1]) {
		if (y - (l - 1) <= 0)return false;
		for (int j = y; j >= y - (l - 1); j--) {
			if (maps[x][y] != maps[x][j] || bridge[x][j])return false;
		}
		for (int j = y; j >= y - (l - 1); j--) {
			bridge[x][j] = true;
		}
		return row_state(x, y + 1);
	}
	if (maps[x][y] == maps[x][y + 1] + 1) {
		if (y + l > n)return false;
		for (int j = y + 1; j <= y + l; j++) {
			if (maps[x][y + 1] != maps[x][j] || bridge[x][j])return false;
		}
		for (int j = y + 1; j <= y + l; j++) {
			bridge[x][j] = true;
		}
		return row_state(x, y + l);
	}
	return false;
}
bool col_state(int x, int y) {
	if (x >= n) {
		return true;
	}
	if (maps[x][y] == maps[x + 1][y]) {
		return col_state(x + 1, y);
	}
	if (maps[x][y] + 1 == maps[x + 1][y]) {
		if (x - (l - 1) <= 0)return false;
		for (int i = x; i >= x - (l - 1); i--) {
			if (maps[x][y] != maps[i][y] || bridge[i][y])return false;
		}
		for (int i = x; i >= x - (l - 1); i--) {
			bridge[i][y] = true;
		}
		return col_state(x + 1, y);
	}
	if (maps[x][y] == maps[x + 1][y] + 1) {
		if (x + l > n)return false;
		for (int i = x + 1; i <= x + l; i++) {
			if (maps[x + 1][y] != maps[i][y] || bridge[i][y])return false;
		}
		for (int i = x + 1; i <= x + l; i++) {
			bridge[i][y] = true;
		}
		return col_state(x + l, y);
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	for (int i = 1; i <= n; i++) {
		if (row_state(i, 1)) {
			ans += 1; 
		}
	}
	memset(bridge, false, sizeof(bridge));
	for (int j = 1; j <= n; j++) {
		if (col_state(1, j)) {
			ans += 1;
		}
	}
	cout << ans;
}
