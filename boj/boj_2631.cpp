#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <cmath>
#include <map>
#define MAX_VALUE 200000000
#define MIN_VALUE -200000000
#define MOD_VALUE 1000000000
using namespace std;
int a[201];
int d[201];
int n;
int state(int n) {
	int &ans = d[n];
	if (ans != -1)return ans;
	ans = MIN_VALUE;
	bool check = false;
	for (int i = n-1; i >= 1; i--) {
		if (a[i] < a[n]) {
			ans = max(ans, state(i));
			check = true;
		}
	}
	if (check == false)ans = 1;
	else ans += 1;
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*
	int t;
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		cout<<'#'<<testcase<<' '<<ans<<'\n';
	}*/
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//solve
	int max_num = MIN_VALUE;
	for (int i = 1; i <= n; i++) {
		max_num = max(max_num, state(i));
	}
	//print
	cout << n - max_num;
	return 0;
}