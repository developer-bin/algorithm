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
	while (true) {
		cin >> s;
		if (s == "0")break;
		int l = 0, r = (int)s.length() - 1;
		bool check = true;
		while (l <= r) {
			if (s[l] != s[r]) {
				check = false;
				break;
			}
			l += 1;
			r -= 1;
		}
		if (check)cout << "yes\n";
		else cout << "no\n";
	}
	//solve
	//print
}
