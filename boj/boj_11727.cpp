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
int n;
int d[1001];
int dfs(int idx) {
	if (idx > n)return 0;
	if (idx == n)return 1;
	int &ans = d[idx];
	if (ans != -1)return ans;
	ans = 0;
	ans = (dfs(idx + 1)%10007 + 2 * dfs(idx + 2)%10007)%10007;
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
	//solve print
	cout<<dfs(0);
}