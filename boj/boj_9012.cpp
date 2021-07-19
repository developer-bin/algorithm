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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int cnt = 0;
		bool check = true;
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == '(') {
				cnt += 1;
			}
			else if (s[i] == ')') {
				if (cnt <= 0) {
					check = false;
					break;
				}
				cnt -= 1;
			}
		}
		if (check) {
			if (cnt != 0)cout << "NO\n";
			else cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}