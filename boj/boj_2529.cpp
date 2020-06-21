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
string s;
vector<int> v = { 9,8,7,6,5,4,3,2,1,0 };
vector<int> permu_v;
bool visit[11];
vector<string> ans;
bool checking() {
	int idx = 0;
	for (int i = 0; i < permu_v.size() - 1; i++) {
		if (s[idx] == '<' && permu_v[i] > permu_v[i + 1]) return false;
		else if (s[idx] == '>' && permu_v[i] < permu_v[i + 1]) return false;
		idx += 1;
	}
	return true;
}
void permu(int cnt) {
	if (cnt == n + 1) {
		if (checking()) {
			string s;
			for (int i = 0; i < permu_v.size(); i++) {
				s += to_string(permu_v[i]);
			}
			ans.push_back(s);
		}
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (visit[i])continue;
		visit[i] = true;
		permu_v.push_back(v[i]);
		permu(cnt + 1);
		permu_v.pop_back();
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
		string tmp_s;
		cin >> tmp_s;
		s += tmp_s;
	}
	//solve
	permu(0);
	sort(ans.begin(), ans.end());
	cout << ans.back() << '\n' << ans.front();
}