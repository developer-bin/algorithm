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
int cnt[26];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		cnt[s[0] - 'a'] += 1;
	}
	//solve
	bool check = false;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) {
			check = true;
			char c = ('a' + i);
			cout << c;
		}
	}
	if (check == false) {
		cout << "PREDAJA";
	}
	//print
}