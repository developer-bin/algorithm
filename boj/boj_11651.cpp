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
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)return true;
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	//solve
	sort(v.begin(), v.end(), cmp);
	//print
	for (auto k : v) {
		cout << k.first << ' ' << k.second << '\n';
	}
}
