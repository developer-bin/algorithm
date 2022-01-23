#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
int n, k;
bool alpa[26];
vector<string> v;
int ans;

int checking() {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		string s = v[i];
		bool check = true;
		for (int j = 0; j < s.length(); j++) {
			if (alpa[s[j] - 'a'] == false) {
				check = false;
				break;
			}
		}
		if (check)cnt += 1;
	}
	return cnt;
}
void combi(int idx, int cnt) {
	if (cnt == k) {
		ans=max(ans,checking());
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (i == 'a' - 'a' || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a')continue;
		alpa[i] = true;
		combi(i + 1, cnt + 1);
		alpa[i] = false;
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> n >> k;
	if (k < 5) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	//solve
	k -= 5;
	alpa['a' - 'a'] = alpa['n' - 'a'] = alpa['t' - 'a'] = alpa['i' - 'a'] = alpa['c'- 'a'] = true;
	combi(0,0);
	//print
	cout << ans;
	return 0;
}