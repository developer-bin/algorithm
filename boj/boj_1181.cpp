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
vector<string> v;
set<string> sets;

bool cmp(string a, string b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() == b.length()) {
		if (a < b)return true;
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
		string s;
		cin >> s;
		sets.insert(s);
	}
	//solve
	for (set<string>::iterator it = sets.begin(); it != sets.end(); it++) {
		v.push_back(*(it));
	}
	sort(v.begin(), v.end(),cmp);
	//print
	for (string k : v) {
		cout << k << '\n';
	}
}