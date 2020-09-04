#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#define ll long long
#define MAX_VALUE 200000000
#define MIN_VALUE 200000000
using namespace std;
ll a, b;
int ans;
void dfs(string s) {
	ll num = stoll(s);
	if (b < num)return;
	if (a <= num && num <= b) {
		ans += 1;
	}
	dfs(s + '4');
	dfs(s + '7');
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> a >> b;
	//solve
	dfs("4");
	dfs("7");
	//print
	cout << ans;
}