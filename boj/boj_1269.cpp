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

set<int> sets_a;
set<int> sets_b;
int a, b;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		int num;
		cin >> num;
		sets_a.insert(num);
	}
	for (int i = 1; i <= b; i++) {
		int num;
		cin >> num;
		sets_b.insert(num);
	}

	for (auto k : sets_a) {
		if (sets_b.find(k) == sets_b.end())ans +=1;
	}

	for (auto k : sets_b) {
		if (sets_a.find(k) == sets_a.end())ans += 1;
	}

	cout << ans;
}