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
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> s;
	//solve
	int l = 0, r = (int)s.length() - 1;
	while (l <= r) {
		if (s[l] != s[r]) {
			cout << 0;
			return 0;
		}
		l += 1;
		r -= 1;
	}
	//print
	cout << 1;
}
