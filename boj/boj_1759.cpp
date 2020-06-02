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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
char a[16];
int l, c;
bool visit[16];
bool checking(string s) {
	int za = 0, mo = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			mo += 1;
		}
		else za += 1;
	}
	return mo >= 1 && za >= 2;
}
void permu(int idx, int cnt, string s) {
	if (cnt == l) {
		if (checking(s)) {
			cout << s << '\n';
		}
		return;
	}
	for (int i = idx; i <= c; i++) {
		permu(i + 1, cnt + 1, s + a[i]);
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
	//input
	cin >> l >> c;
	for (int i = 1; i <= c; i++) {
		cin >> a[i];
	}
	//solve
	sort(a + 1, a + 1 + c);
	permu(1, 0, "");
}