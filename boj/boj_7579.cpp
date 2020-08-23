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
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n, m;
int byte[101];
int cost[101];
int d[101][10001];
int state(int idx, int sum_cost) {
	if (idx == n + 1) return 0;
	int &result = d[idx][sum_cost];
	if (result != -1)return result;
	result = state(idx + 1, sum_cost);
	if (sum_cost >= cost[idx]) {
		result = max(result, byte[idx] + state(idx + 1, sum_cost - cost[idx]));
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> byte[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	//solve
	int sum_cost = 0;
	while (true) {
		if (state(1, sum_cost) >= m) {
			cout << sum_cost << '\n';
			break;
		}
		sum_cost += 1;
	}
	//print
}