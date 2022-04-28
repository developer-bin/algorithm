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
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first < b.first)return true;
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
		int num;
		string s;
		cin >> num >> s;
		v.push_back({ num,s });
	}
	//solve
	stable_sort(v.begin(), v.end(), cmp);
	//print
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}