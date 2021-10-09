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
int cnt_s1[26];
int cnt_s2[26];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s1 >> s2;

	for (int i = 0; i < (int)s1.length(); i++) {
		cnt_s1[s1[i] - 'a'] += 1;
	}

	for (int i = 0; i < (int)s2.length(); i++) {
		cnt_s2[s2[i] - 'a'] += 1;
	}

	for (int i = 0; i < 26; i++) {
		ans += abs(cnt_s1[i] - cnt_s2[i]);
	}

	cout << ans;
}