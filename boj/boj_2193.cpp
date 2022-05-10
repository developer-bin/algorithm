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
#define MOD 1000000000
#define ll long long
using namespace std;
int n;
ll d[91][2];

ll dfs(int idx, int cnt) {
	if (idx == n)return 1LL;
	ll &result = d[idx][cnt];
	if (result != -1)return result;
	result = 0;
	if (cnt == 0) {
		result += dfs(idx + 1, 1);
	}
	result += dfs(idx + 1, 0);
	return result;
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
	cout << dfs(1, 1);
}