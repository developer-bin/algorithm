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
int t;
int n;
int d[12];
int dfs(int sum) {
	if (sum < 0)return 0;
	if (sum == 0)return 1;
	int &ans = d[sum];
	if (ans != -1)return ans;
	return ans = dfs(sum - 1) + dfs(sum - 2) + dfs(sum - 3);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	dfs(11);
	//input
	cin >> t;
	while (t--) {
		cin >> n;
		//solve print
		cout << d[n] << '\n';
	}
}