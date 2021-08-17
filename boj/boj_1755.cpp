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
#include <stack>
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;

int n, m;
map<char, string> maps;
vector<pair<string,int>> v;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.first < b.first)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	maps['0'] = "zero";
	maps['1'] = "one";
	maps['2'] = "two";
	maps['3'] = "three";
	maps['4'] = "four";
	maps['5'] = "five";
	maps['6'] = "six";
	maps['7'] = "seven";
	maps['8'] = "eight";
	maps['9'] = "nine";

	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		string s = to_string(i);
		string mid_s = "";

		for (int j = 0; j < (int)s.length(); j++) {
			mid_s += maps[s[j]];
			mid_s += " ";
		}
		mid_s.pop_back();

		v.push_back({ mid_s,i });
	}

	sort(v.begin(), v.end(),cmp);

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cnt == 10) {
			cout << "\n";
			cnt = 0;
		}
		cout << v[i].second << ' ';
		cnt += 1;
	}
}