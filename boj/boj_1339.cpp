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
#include <unordered_set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 1000000009
#define ll long long
using namespace std;
int n;
int m;
bool alpa[26];
vector<char> alpa_v;
int permu_arr[11];
vector<string> s_v;
bool visit[10];
int ans = MIN_VALUE;
void add() {
	int sum = 0;
	for (int i = 0; i < s_v.size(); i++) {
		string s = s_v[i];
		int num = 0;
		for (int j = 0; j < (int)s.length(); j++) {
			for (int k = 0; k < alpa_v.size(); k++) {
				if (alpa_v[k] == s[j]) {
					num += permu_arr[k];
					num *= 10;
					break;
				}
			}
		}
		num /= 10;
		sum += num;
	}
	ans = max(ans, sum);
}
void permu(int cnt) {
	if (cnt == m) {
		add();
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (visit[i])continue;
		visit[i] = true;
		permu_arr[cnt] = i;
		permu(cnt + 1);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int i = 0; i < (int)s.length(); i++) {
			alpa[s[i] - 'A'] = true;
		}
		s_v.push_back(s);
	}
	//solve
	for (int i = 0; i < 26; i++) {
		if (alpa[i]) {
			m += 1;
			alpa_v.push_back(i + 'A');
		}
	}
	permu(0);
	cout << ans;
}