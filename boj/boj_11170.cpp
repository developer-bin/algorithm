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

int t;
int n, m;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		for (int i = n; i <= m; i++) {
			string s = to_string(i);
			for (int j = 0; j < (int)s.length(); j++) {
				if (s[j] == '0')ans += 1;
			}
		}

		cout << ans << '\n';
	}
}