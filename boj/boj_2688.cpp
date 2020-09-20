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
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int t;
int n;
ll d[65][10];
ll state(int idx, int num) {
	if (idx == 1)return 1;
	ll &result = d[idx][num];
	if (result != -1)return result;
	result = 0;
	for (int i = num; i >= 0; i--) {
		result += state(idx - 1, i);
	}
	return result;
}
int main() {
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> t;
	while (t--) {
		cin >> n;
		ll ans = 0;
		for (int i = 0; i <= 9; i++) {
			ans += state(n, i);
		}
		cout << ans << '\n';
	}
	//solve
	//print
}