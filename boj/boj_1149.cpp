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
using namespace std;
int cost[1001][4];
int n;
int ans = MAX_VALUE;
int d[1001][4];

int state(int idx, int color) {
	if (idx == 0) {
		return 0;
	}
	int &ans = d[idx][color];
	if (ans != -1)return ans;
	if (color == 1) {
		return ans = min(state(idx - 1, 2), state(idx - 1, 3)) + cost[idx][1];
	}
	else if (color == 2) {
		return ans = min(state(idx - 1, 1), state(idx - 1, 3)) + cost[idx][2];
	}
	else if (color == 3) {
		return ans = min(state(idx - 1, 1), state(idx - 1, 2)) + cost[idx][3];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	memset(d, -1, sizeof(d));

	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> cost[i][j];
		}
	}

	//solve
	ans=min(ans,state(n, 1));
	ans=min(ans,state(n, 2));
	ans=min(ans,state(n, 3));
	
	//print
	cout << ans;
}