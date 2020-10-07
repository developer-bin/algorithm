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
int d[4002][4002];
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool boundary(int x) {
	return x >= 0 && x <= 100000;
}
string ans="-1";
void init() {
}
void input() {
	cin >> n;
}
void solve() {
	queue<string> q;
	for (int i = 0; i <= 9; i++) {
		char c = i + '0';
		string s = "";
		s = s + c;
		q.push(s);
	}
	int cnt = -1;
	while (!q.empty()) {
		cnt += 1;
		string s = q.front();
		q.pop();
		char last_c = s[s.length() - 1];
		if (cnt == n) { ans = s; break; }
		for (char c = '0'; c <= last_c - 1; c++) {
			string mid_s = s + c;
			q.push(mid_s);
		}
	}
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
	init();
	//input
	input();
	//solve and print
	solve();
	cout << ans;
	return 0;
}