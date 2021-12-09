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

int l, r, a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> r >> a;

	if (abs(l - r) > a) {

		cout << (min(l, r) + a) * 2;

	}else if (abs(l - r) == 0) {

		cout << l + r + (a / 2) * 2;

	}else if (abs(l - r) < a) {

		cout << max(l, r) * 2 + ((a - abs(l - r)) / 2) * 2;

	}else if (abs(l - r) == a) {

		cout << max(l, r) * 2;

	}
}