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

int a, b;
set<int> sets;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		int num;
		cin >> num;
		sets.insert(num);
	}

	for (int i = 1; i <= b; i++) {
		int num;
		cin >> num;
		if (sets.find(num) != sets.end()) {
			sets.erase(num);
		}
	}

	cout << sets.size()<<'\n';
	for (auto k : sets) {
		cout << k << ' ';
	}
}