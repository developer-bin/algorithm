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
int n;
int d[100001];
int state(int sum) {
	if (sum > n)return MAX_VALUE;
	if (sum == n)return 0;
	int& ans = d[sum];
	if (ans != -1)return ans;
	ans = MAX_VALUE;
	ans = min(state(sum + 2), state(sum + 5)) + 1;
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	//solve
	//print
	int ans = state(0);
	if (ans >= MAX_VALUE)cout << -1;
	else cout << ans;
}