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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n;
int d[1000001][3];
int dfs(int idx,int now_num) {
	if (idx < 1)return 0;
	if (idx == 1)return 1;
	int &ans = d[idx][now_num];
	if (ans != -1)return ans;
	if (now_num == 1) {
		ans = dfs(idx - 1,1) % 15746 + dfs(idx - 2,2) % 15746;
	}
	else if (now_num == 2) {
		ans = dfs(idx - 1, 1) % 15746 + dfs(idx - 2, 2) % 15746;
	}
	return ans %= 15746;
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
	cout << (dfs(n-1, 2) % 15746 + dfs(n, 1) % 15746) % 15746;
}