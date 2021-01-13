#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n, m;
vector<string> v;
map<char, int> maps;
int ans_cnt;
string ans_s;
bool cmp(pair<char, int> a, pair<char, int> b) {
	if (a.second > b.second) {
		return true;
	}
	else if (a.second == b.second) {
		if (a.first < b.first)return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	//solve
	for (int j = 0; j < m; j++) {
		maps.clear();
		for (int i = 0; i < n; i++) {
			maps[v[i][j]] += 1;
		}
		vector<pair<char, int>> v(maps.begin(), maps.end());
		sort(v.begin(),v.end(), cmp);
		ans_cnt += (n-v.front().second);
		ans_s += v.front().first;
	}
	//print
	cout << ans_s << '\n' << ans_cnt;
}