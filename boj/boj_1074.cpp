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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n, r, c;
int num = -1;
int ans;
bool check;

void dfs(int x, int y, int n) {
	if (n == 1) {
		num += 1;
		if (x == r && y == c) {
			ans = num;
			check = true;
		}
		return;
	}
	if (r < x + n / 2 && c < y + n / 2) {
		dfs(x, y, n / 2);
	}
	else if (r < x + n / 2 && y + n / 2 <= c) {
		num += pow(n / 2, 2);
		dfs(x, y + n / 2, n / 2);
	}
	else if (x + n / 2 <= r && c < y + n / 2) {
		num += pow(n / 2, 2) * 2;
		dfs(x + n / 2, y, n / 2);
	}
	else if (x + n / 2 <= r && y + n / 2 <= c) {
		num += pow(n / 2, 2) * 3;
		dfs(x + n / 2, y + n / 2, n / 2);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> r >> c;
	r += 1; c += 1;
	//solve
	dfs(1, 1, pow(2, n));
	//print
	cout << ans;
}