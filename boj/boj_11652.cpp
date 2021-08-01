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

int n;
map<ll, int> maps;
vector<pair<ll, int>> v;

bool cmp(pair<ll, int> a, pair<ll, int> b) {
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

	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll num;
		cin >> num;
		maps[num] += 1;
	}

	for (auto k : maps) {
		v.push_back({ k.first,k.second });
	}

	sort(v.begin(), v.end(), cmp);

	cout << v.front().first;
}