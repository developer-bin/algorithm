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
#define ll long long
using namespace std;
int a[100001];
int n;
int d[100001];
int ans = MIN_VALUE;
int f(int idx) {
	if (idx == 0)return 0;
	int &ans = d[idx];
	if (ans != MIN_VALUE - 1)return ans;
	ans = MIN_VALUE;
	ans=max(a[idx], f(idx - 1) + a[idx]);
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	for (int i = 0; i <= 100000; i++)d[i] = MIN_VALUE-1;
	//input
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	//solve
	f(n);
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]);
	}
	cout << ans;
}