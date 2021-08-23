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
multiset<string> sets;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		sets.insert(s);
	}

	for (int i = 1; i <= n - 1; i++) {
		string s;
		cin >> s;
		sets.erase(sets.find(s));
	}

	for (auto k : sets) {
		cout << k;
	}
}