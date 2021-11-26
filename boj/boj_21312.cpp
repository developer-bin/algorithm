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

int a, b, c;
int max_value = MIN_VALUE;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	if (a % 2 == 1) {
		max_value = max(a, max_value);
	}
	if (b % 2 == 1) {
		max_value = max(b, max_value);
	}
	if (c % 2 == 1) {
		max_value = max(c, max_value);
	}
	if ((a * b) % 2 == 1) {
		max_value = max(a*b, max_value);
	}
	if ((a * c) % 2 == 1) {
		max_value = max(a * c, max_value);
	}
	if ((b * c) % 2 == 1) {
		max_value = max(b * c, max_value);
	}
	if ((a * b * c) % 2 == 1) {
		max_value = max(a * b * c, max_value);
	}
	if (max_value == MIN_VALUE) {
		max_value = a * b * c;
	}

	cout << max_value;
}