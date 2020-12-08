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
ll d[91];
ll state(int n) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	ll& ans = d[n];
	if (ans != -1)return ans;
	return ans = state(n - 1) + state(n - 2);
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
	cout << state(n);
	//print
}