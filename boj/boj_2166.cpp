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
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m;
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool boundary(int x) {
	return x >= 0 && x <= 100000;
}
vector<pair<double, double>> v;
void init() {
}
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
}
double ans;
double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
void solve() {
	double x, y;
	if (v.empty() == false) {
		x = v[0].first;
		y = v[0].second;
	}
	for (int i = 1; i < v.size()-1; i++) {
		ans += ccw(x, y, v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
	}
	ans = abs(ans);
	ans /= 2;
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	/*
	int t;
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		cout<<'#'<<testcase<<' '<<ans<<'\n';
	}*/
	//init
	init();
	//input
	input();
	//solve and print
	solve();
	cout.setf(ios::fixed);
	cout.precision(1);
	cout << ans;
	return 0;
}