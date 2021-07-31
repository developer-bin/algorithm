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

string s1, s2;
int ans = MAX_VALUE;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s1 >> s2;

	if ((int)s1.length() == (int)s2.length()) {
		int cnt = 0;
		for (int i = 0; i < (int)s1.length(); i++) {
			if (s1[i] != s2[i])cnt += 1;
		}
		cout << cnt;
	}
	else {
		for (int i = 0; i < (int)s2.length(); i++) {
			int idx1 = 0;
			int cnt = 0;
			int idx2 = i;
			bool check = true;

			while (true) {
				if (s1[idx1] != s2[idx2])cnt += 1;
				idx1 += 1;
				idx2 += 1;
				if (idx1 == (int)s1.length())break;
				if (idx2 == (int)s2.length()) {
					check = false;
					break;
				}
			}

			if (check) {
				ans = min(ans, cnt);
			}
			else break;
		}

		cout << ans;
	}
}