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
string s;
int len;
string permu_s;
bool visit[11];
int alpa_cnt[26];
int ans;
int Factorial(int n)
{
	int R = 1;
	for (int i = n; i >= 1; i--)
	{
		R = R * i;
	}
	return R;
}
void permu(int cnt) {
	if (cnt == len) {
		int permu_len = permu_s.length();
		for (int i = 0; i < permu_len - 1; i++) {
			if (permu_s[i] == permu_s[i + 1])return;
		}
		ans += 1;
		return;
	}
	for (int i = 0; i < len; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			permu_s.push_back(s[i]);
			permu(cnt + 1);
			permu_s.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s;
	len = s.length();
	for (int i = 0; i < len; i++) {
		alpa_cnt[s[i] - 'a'] += 1;
	}
	permu(0);
	for (int i = 0; i < 26; i++) {
		if (alpa_cnt[i] >= 2) {
			ans /= Factorial(alpa_cnt[i]);
		}
	}
	//solve
	cout << ans;
}