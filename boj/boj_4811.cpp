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
#define MOD 9901
#define ll long long
using namespace std;
ll d[31][31];
int n;
ll dfs(int one, int half) {
	if (one == 0 && half == 0)return 1;
	ll &result = d[one][half];
	if (result != -1)return result;
	result = 0;
	if (one >= 1) {
		result += dfs(one - 1, half + 1);
	}
	if (half >= 1) {
		result += dfs(one, half - 1);
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
	//solve
	while (true) {
		cin >> n;
		if (n == 0)break;
		cout << dfs(n,0)<<'\n';
	}
}