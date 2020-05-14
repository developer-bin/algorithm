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
string s;
int len;
int d[5001];
int dfs(int idx) {
	if (idx == len) { return 1; }
	int& ans = d[idx];
	if (ans != -1)return ans;
	ans = 0;
	int num = s[idx] - '0';
	if (num != 0) {
		ans += dfs(idx + 1) % 1000000;
	}
	if (idx + 1 <= len - 1) {
		num *= 10; num += s[idx + 1] - '0';
		if (10 <= num && num <= 26) {
			ans += dfs(idx + 2) % 1000000;
		}
	}
	return ans % 1000000;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> s;
	len = s.length();
	//solve print
	cout << dfs(0);
}