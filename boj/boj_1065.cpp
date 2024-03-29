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
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		if ((int)s.length() <= 1) {
			ans += 1;
		}
		else {
			int d = s[0] - s[1];
			bool check = true;
			for (int j = 0; j < (int)s.length() - 1; j++) {
				if (s[j] - s[j + 1] != d) {
					check = false;
					break;
				}
			}
			if (check)ans += 1;
		}
	}
	cout << ans;
}